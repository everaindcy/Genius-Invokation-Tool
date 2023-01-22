#pragma once

/**
 * todo:
 * character的装备和出战状态区分，装备区也按照打出顺序排列
 * 
 * 确认结算顺序，需要确认！
 * 先行动方，再非行动方，回合结束时先结束的先结算
 * 0. 死亡切人trigger/超载切人trigger
 * 1. 角色装备
 * 2. 角色出战状态
 * 3. 下一个角色装备/出战状态，再下一个角色装备/出战状态
 * 4. 阵营出战状态
 * 5. 支援区
 * 6. 召唤物区
 * 
 * 处理小阶段：
 * 0. wait    等待玩家
 * 1. target  选择目标
 * 2. cost    支付cost
 * 3. 处理时（超载切人任意插入，死亡切人不处理）
 *      这里可能有多个trigger
 *      1. 造成伤害相关
 *      2. 切换角色相关
 * 4. 处理后（仅在此阶段处理死亡切人，且死亡切人任意插入）
 *      这里同样可以产生多个trigger
 *      1. 切换角色相关
 *      2. 造成伤害相关
 * 
 * 确认：2次数燃烧打头上有草角色剩余2次数还是1次数：确认是1次数
 * 确认：超载切人是插入结算吗？确认是，元素反应结算优于一切
*/

#include "enum.h"
#include "card.h"
#include "character.h"
#include "summon.h"
#include "skill.h"

#include <vector>
#include <algorithm>
#include <random>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

typedef Color_dice Dice;

class Player
{
private:
    vector<Character> character; // 角色
    int frontCharacter;          // 出战角色，无出战则为-1
    vector<Card> deck;           // 牌组
    vector<Card> hand;           // 手牌
    vector<Dice> dice;           // 骰子
    vector<Summon> state;        // 出战状态（角色出战状态在角色）
    vector<Summon> support;      // 支援
    vector<Summon> summon;       // 召唤物

    vector<Skill> skill;         // 全局技能（切人、调和）
    vector<Summon> others;       // 其他状态（如本回合有没有死人）

    bool roundEnd;

    mt19937 *rdm;

public:
    Player(/* args */);
    ~Player() = default;

    Character& character_at(int idx) {return character.at(idx);}
    int character_alive_num() {
        int num = 0;
        for (auto &ch : character) {
            if (ch.is_alive()) num++;
        }
        return num;
    }
    int get_frontCharacter() {return frontCharacter;}
    void frontCharacter_change_to(int idx) {
        if(frontCharacter >= 0) {
            character_at(frontCharacter).front_change_to(false);
        }
        frontCharacter = idx;
        character_at(frontCharacter).front_change_to(true);
    }
    void frontCharacter_change_to_next() {
        if(frontCharacter >= 0 && character_alive_num() > 1) {
            character_at(frontCharacter).front_change_to(false);
            frontCharacter = (frontCharacter+1) % character.size();
            while(character_at(frontCharacter).is_dead()) frontCharacter = (frontCharacter+1) % character.size();
            character_at(frontCharacter).front_change_to(true);
        }
    }
    void frontCharacter_change_to_previous() {
        if(frontCharacter >= 0 && character_alive_num() > 1) {
            character_at(frontCharacter).front_change_to(false);
            frontCharacter = (frontCharacter-1) % character.size();
            while(character_at(frontCharacter).is_dead()) frontCharacter = (frontCharacter+1) % character.size();
            character_at(frontCharacter).front_change_to(true);
        }
    }

    void deck_shuffle() {shuffle(deck.begin(), deck.end(), *rdm);}
    void deck_pop() {deck.pop_back();}
    Card deck_top() {return deck.back();}
    Card deck_draw() {auto v = deck_top(); deck_pop(); return v;}
    void deck_push(Card v) {deck.push_back(v);}
    Card& deck_at(int idx) {return deck.at(idx);}
    int deck_num() {return deck.size();}

    void hand_push(Card v) {hand.push_back(v); sort(hand.begin(), hand.end());}
    Card& hand_at(int idx) {return hand.at(idx);}
    int hand_num() {return hand.size();}
    void hand_del(int idx) {hand.erase(hand.begin()+idx);}

    void dice_push(Dice v) {dice.push_back(v); sort(dice.begin(), dice.end());}
    void dice_push(Dice v, int num) {for (int i = 0; i < num; i++) dice.push_back(v); sort(dice.begin(), dice.end());}
    void dice_push(const vector<Dice>& v) {dice.insert(dice.end(), v.begin(), v.end()); sort(dice.begin(), dice.end());}
    Dice& dice_at(int idx) {return dice.at(idx);}
    int dice_num() {return dice.size();}
    void dice_del(int idx) {dice.erase(dice.begin()+idx);}
    void dice_cost(const vector<Dice>& cost) {
        for (const auto &die : cost) {
            for (int i = 0; i < dice_num(); i++) {
                if (dice_at(i) == die) {
                    dice_del(i);
                    break;
                }
            }
        }
    }
    void dice_roll() {dice_push(static_cast<Dice>(uniform_int_distribution<>(0,7)(rdm))); sort(dice.begin(), dice.end());}
    void dice_roll(int num) {for (int i = 0; i < num; i++) dice_roll();}
    void dice_reroll(int idx) {dice_del(idx); dice_roll();}
    void dice_reroll(const vector<int>& v) {for (int idx : v) dice_reroll(idx);}

    void state_push(Summon v) {state.push_back(v);}
    Summon& state_at(int idx) {return state.at(idx);}
    int state_num() {return state.size();}
    void state_del(int idx) {state.erase(state.begin()+idx);}

    void support_push(Summon v) {support.push_back(v);}
    Summon& support_at(int idx) {return support.at(idx);}
    int support_num() {return support.size();}
    void support_del(int idx) {support.erase(support.begin()+idx);}

    void summon_push(Summon v) {summon.push_back(v);}
    Summon& summon_at(int idx) {return summon.at(idx);}
    int summon_num() {return summon.size();}
    void summon_del(int idx) {summon.erase(summon.begin()+idx);}

    Skill& skill_at(int idx) {return skill.at(idx);}
    int skill_num() {return skill.size();}

    void others_push(Summon v) {others.push_back(v);}
    Summon& others_at(int idx) {return others.at(idx);}
    int others_num() {return others.size();}
    void others_del(int idx) {others.erase(others.begin()+idx);}

    bool is_RoundEnd() {return roundEnd;}
    void RonndEnd_change_to(bool v) {roundEnd = v;}
};

Player::Player(/* args */)
{
}


class Table
{
private:
    vector<Player> players;
    int moving_player;
    int next_turn_first_moving_player;

    int turn;

    Stage stage; // 阶段
    Event event; // 事件

    int index; // 当前生成物的index
    mt19937 *rdm;

    int maxDiceNum = 16;
    int maxHandCardNum = 10;
    int maxTurnNum = 15;

public:
    Table();
    ~Table() = default;

    Player& players_at(int idx) {return players.at(idx);}

    int get_moving_player() {return moving_player;}
    void moving_player_change() {moving_player = (moving_player+1)%2;}

    Stage get_stage() {return stage;}
    void stage_change_to(Stage v) {stage = v;}

    Event get_event() {return event;}
    void event_change_to(Event v) {event = v;}

    int get_index() {return index;}
    int get_new_index() {index++; return index;}
};

Table::Table()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

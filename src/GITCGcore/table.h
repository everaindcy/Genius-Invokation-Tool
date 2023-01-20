#pragma once

#include "GITCGcore/enum.h"
#include "GITCGcore/card.h"
#include "GITCGcore/character.h"
#include "GITCGcore/summon.h"
#include "GITCGcore/skill.h"

#include <vector>
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
    int frontCharacter;          // 出战角色
    vector<Card> deck;           // 牌组
    vector<Card> hand;           // 手牌
    vector<Dice> dice;           // 骰子
    vector<Summon> support;      // 支援
    vector<Summon> summon;       // 召唤物
    vector<Summon> state;        // 出战状态（角色出战状态在角色）

    vector<Skill> skill;         // 全局技能（切人、调和）
    vector<Summon> others;       // 其他状态（如本回合有没有死人）

    bool RoundEnd;

public:
    Player(/* args */);
    ~Player();

    Character& character_at(int);
    int character_alive_num();
    int frontCharacter();
    void frontCharacter_change_to(int);
    void frontCharacter_change_to_next();
    void frontCharacter_change_to_previous();

    void deck_shuffle();
    void deck_pop();
    Card deck_top();
    Card deck_draw();
    void deck_push(Card);
    Card& deck_at(int);
    int deck_num();

    void hand_push(Card);
    Card& hand_at(int);
    int hand_num();
    void hand_del(int);

    void dice_push(Dice);
    void dice_push(Dice, int);
    void dice_push(const vector<Dice>&);
    Dice& dice_at(int);
    void dice_num();
    void dice_del(int);
    void dice_cost(const vector<Dice>&);
    void dice_reroll(int);
    void dice_reroll(const vector<int>&);

    void support_push(Summon);
    Summon& support_at(int);
    int support_num();
    void support_del(int);

    void summon_push(Summon);
    Summon& summon_at(int);
    int summon_num();
    void summon_del(int);

    void state_push(Summon);
    Summon& state_at(int);
    int state_num();
    void state_del(int);

    Skill& skill_at(int);

    void others_push(Summon);
    Summon& others_at(int);
    int others_num();
    void others_del(int);

    bool RoundEnd();
    void RonndEnd_change_to(bool);
};

Player::Player(/* args */)
{
}

Player::~Player()
{
}


class Table
{
private:
    vector<Player> players;
    int moving_player;

    int turn;

    int index; // 当前生成物的index

    Stage stage; // 阶段
    Event event; // 事件

    int maxDiceNum = 16;
    int maxHandCardNum = 10;
    int maxTurnNum = 15;

public:
    Table();
    ~Table();

    Player& players_at(int);

    int moving_player();
    void moving_player_change();

    int get_index();
};

Table::Table()
{
}

Table::~Table()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

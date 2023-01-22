#pragma once

#include "summon.h"
#include "skill.h"
#include "code.h"

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

enum class Weapon_type {
    Sword,     // 单手剑
    Claymore,  // 双手剑
    Polearm,   // 长柄武器
    Bow,       // 弓
    Catalyst,  // 法器
    Others,
};

enum class Nation {
    Mondstadt, // 蒙德
    Liyue,     // 璃月
    Inazuma,   // 稻妻
    Sumeru,    // 须弥
    Monster,   // 魔物
    Fatui,     // 愚人众
    Others,
};

class Character
{
private:
    int index;
    string name;
    Color_character color_type;
    Weapon_type weapon_type;
    Nation nation;
    int maxHP;
    int maxPT;

    vector<Skill> skill; // 技能

    int position; // 站位
    int HP;       // 血量
    int PT;       // 能量
    bool full;    // 饱腹
    bool front;   // 出战

    vector<Color_damage> color_attached; // 元素附着

    vector<Summon> equipment; // 装备
    vector<Summon> state;     // 出战状态

    Code code_initialize;

public:
    Character();
    ~Character() = default;

    void HP_add(int v) {HP += v;}
    void PT_add(int v) {PT += v;}
    void full_change_to(bool v) {full = v;}
    void front_change_to(bool v) {front = v;}

    Reaction_type reaction(Color_damage);
    Color_damage& color_attached_at(int idx) {return color_attached.at(idx);}

    void equipment_push(Summon v) {equipment.push_back(v);}
    void equipment_del(int idx) {equipment.erase(equipment.begin()+idx);}
    Summon& equipment_at(int idx) {return equipment.at(idx);}
    int equipment_num() {return equipment.size();}

    void state_push(Summon v) {state.push_back(v);}
    void state_del(int idx) {state.erase(state.begin()+idx);}
    Summon& state_at(int idx) {return state.at(idx);}
    int state_num() {return state.size();}

    Skill& skill_at(int idx) {return skill.at(idx);}
    int skill_num() {return skill.size();}

    void code_initialize_run(); // todo

    bool is_alive() {return HP > 0;}
    bool is_dead() {return HP <= 0;}
    bool HP_is_max() {return HP == maxHP;}
    bool PT_is_max() {return PT == maxPT;}
    bool is_full() {return full;}
    bool is_front() {return front;}

    int get_index() {return index;}
    string get_name() {return name;}
    Color_character get_color_type() {return color_type;}
    Weapon_type get_weapon_type() {return weapon_type;}
    Nation get_nation() {return nation;}
    int get_maxHP() {return maxHP;}
    int get_maxPT() {return maxPT;}

    int get_position() {return position;}
    int get_HP() {return HP;}
    int get_PT() {return PT;}
    bool get_full() {return full;}
    bool get_front() {return front;}
};

Character::Character()
{
}

Reaction_type Character::reaction(Color_damage color) {
    sort(color_attached.begin(), color_attached.end());
    Reaction_type rt = Reaction_type::NoReaction;
    int i;
    for (i = 0; i < color_attached.size(); i++) {
        rt = Reaction_map.at(color_attached[i]).at(color);
        if (rt != Reaction_type::NoReaction) break;
    }
    if (rt != Reaction_type::NoReaction) {
        color_attached.erase(color_attached.begin()+i);
    } else if (color == Color_damage::Cryo ||
               color == Color_damage::Dendro ||
               color == Color_damage::Electro ||
               color == Color_damage::Hydro ||
               color == Color_damage::Pyro) {
        color_attached.push_back(color);
        sort(color_attached.begin(), color_attached.end());
        auto last = unique(color_attached.begin(), color_attached.end());
        color_attached.erase(last, color_attached.end());
    }
    return rt;
}


} // namespace GITCGcore

} // namespace GITCGtool

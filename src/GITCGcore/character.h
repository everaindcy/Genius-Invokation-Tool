#pragma once

#include "GITCGcore/summon.h"
#include "GITCGcore/skill.h"
#include "GITCGcore/code.h"

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

    vector<Skill> skills; // 技能

    int position; // 站位
    int HP;       // 血量
    int PT;       // 能量
    bool full;    // 饱腹
    bool front;   // 出战

    vector<Color_damage> color_attached; // 元素附着

    vector<Summon> state; // 出战状态，没有的情况下 index = -1
                          // state[0] = weapon
                          // state[1] = artifact
                          // state[2] = talent

    Code code_initialize;

public:
    Character(/* args */);
    ~Character();

    void HP_add(int);
    void PT_add(int);
    void full_change_to(bool);
    void front_change_to(bool);

    Reaction_type reaction(Color_damage);
    Color_damage& color_attached_at(int);

    void state_push(Summon);
    void state_del(int);
    Summon& state_at(int);
    Summon& weapon();
    Summon& artifact();
    Summon& talent();

    Skill& skills_at(int);

    void code_initialize_run();

    bool is_dead();
    bool HP_is_max();
    bool PT_is_max();
    bool is_full();
    bool is_front();

    int index();
    string name();
    Color_character color_type();
    Weapon_type weapon_type();
    Nation nation();
    int maxHP();
    int maxPT();

    int position();
    int HP();
    int PT();
    bool full();
    bool front();
};

Character::Character(/* args */)
{
}

Character::~Character()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

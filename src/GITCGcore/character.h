#pragma once

#include "GITCGcore/summon.h"
#include "GITCGcore/skill.h"

#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

enum Weapon_type {
    Sword,
    Claymore,
    Polearm,
    Bow,
    Catalyst,
    Others,
};

enum Nation {
    Mondstadt,
    Liyue,
    Inazuma,
    Sumeru,
    Monster,
    Fatui,   //愚人众
};

class Character
{
private:
    string name;
    Color_character color_character;
    Weapon_type weapon_type;
    Nation nation;

    int maxHP;
    int maxPT;

    int position; //站位
    int HP; // 血量
    int PT; // 能量

    vector<Summon> state; // 出战状态
    vector<Color_attached> color_attached; // 元素附着
    vector<Skill> skills; // 技能


public:
    Character(/* args */);
    ~Character();
};

Character::Character(/* args */)
{
}

Character::~Character()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

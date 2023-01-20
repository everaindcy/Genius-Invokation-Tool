#pragma once

#include "GITCGcore/code.h"
#include "GITCGcore/enum.h"

#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

enum class Card_type {
    Equipment, // 装备
    Support,   // 支援
    Event,     // 事件
};

enum class Card_type_sub {
    // 装备牌副类型
    Talent,    // 天赋
    Weapon,    // 武器
    Artifact,  // 圣遗物

    // 支援牌副类型
    Location,  // 场地
    Companion, // 伙伴
    Item,      // 道具

    // 事件牌副类型
    Resonance, // 共鸣
    Food,      // 食物

    None,      // 无，目前仅在事件牌中出现无副类型的卡
};

class Card
{
private:
    int index;
    string name;
    Card_type type;
    Card_type_sub type_sub;

    vector<Color_cost> cost;

    Code code_can_add_to_deck;
    Code code_initialize;

    Code code_can_use;
    Code code_run;

public:
    Card(/* args */);
    ~Card();
};

Card::Card(/* args */)
{
}

Card::~Card()
{
}
    

} // namespace GITCGcore
} // namespace GITCGtool

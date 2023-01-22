#pragma once
#include <map>
using namespace std;

namespace GITCGtool
{

enum class Color_damage {
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Cryo,    // 冰
    Geo,     // 岩
    Dendro,  // 草
    Physical,// 物理
    Piercing,// 穿透
};

enum class Color_dice {
    Pyro = 0,// 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
    Omni,    // 万能
};

enum class Color_character {
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
};

// enum class Color_attached {
//     Pyro,    // 火
//     Hydro,   // 水
//     Electro, // 雷
//     Dendro,  // 草
//     Cryo,    // 冰
// };

enum class Color_cost {
    PT,      // 能量
    White,   // 同色
    Black,   // 异色
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
};

enum class Reaction_type {
    Melt,               // 融化
    Superconduct,       // 超导
    Frozen,             // 冻结
    Vaporize,           // 蒸发
    ElectroCharged,     // 感电
    Bloom,              // 绽放
    Overloaded,         // 超载
    Burning,            // 燃烧
    Quicken,            // 激化
    CryoSwirl,          // 扩散-冰
    HydroSwirl,         // 扩散-水
    ElectroSwirl,       // 扩散-雷
    PyroSwirl,          // 扩散-火
    CryoCrystallize,    // 结晶-冰
    HydroCrystallize,   // 结晶-水
    ElectroCrystallize, // 结晶-雷
    PyroCrystallize,    // 结晶-火
    NoReaction,         // 无反应
};

// 已附着元素为第一个，新元素为第二个
const map<Color_damage, map<Color_damage, Reaction_type> > Reaction_map = {
    {Color_damage::Anemo, {
        {Color_damage::Anemo,    Reaction_type::NoReaction},
        {Color_damage::Cryo,     Reaction_type::NoReaction},
        {Color_damage::Dendro,   Reaction_type::NoReaction},
        {Color_damage::Electro,  Reaction_type::NoReaction},
        {Color_damage::Geo,      Reaction_type::NoReaction},
        {Color_damage::Hydro,    Reaction_type::NoReaction},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::NoReaction},
    }},
    {Color_damage::Cryo, {
        {Color_damage::Anemo,    Reaction_type::CryoSwirl},
        {Color_damage::Cryo,     Reaction_type::NoReaction},
        {Color_damage::Dendro,   Reaction_type::NoReaction},
        {Color_damage::Electro,  Reaction_type::Superconduct},
        {Color_damage::Geo,      Reaction_type::CryoCrystallize},
        {Color_damage::Hydro,    Reaction_type::Frozen},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::Melt},
    }},
    {Color_damage::Dendro, {
        {Color_damage::Anemo,    Reaction_type::NoReaction},
        {Color_damage::Cryo,     Reaction_type::NoReaction},
        {Color_damage::Dendro,   Reaction_type::NoReaction},
        {Color_damage::Electro,  Reaction_type::Quicken},
        {Color_damage::Geo,      Reaction_type::NoReaction},
        {Color_damage::Hydro,    Reaction_type::Bloom},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::Burning},
    }},
    {Color_damage::Electro, {
        {Color_damage::Anemo,    Reaction_type::ElectroSwirl},
        {Color_damage::Cryo,     Reaction_type::Superconduct},
        {Color_damage::Dendro,   Reaction_type::Quicken},
        {Color_damage::Electro,  Reaction_type::NoReaction},
        {Color_damage::Geo,      Reaction_type::ElectroCrystallize},
        {Color_damage::Hydro,    Reaction_type::ElectroCharged},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::Overloaded},
    }},
    {Color_damage::Geo, {
        {Color_damage::Anemo,    Reaction_type::NoReaction},
        {Color_damage::Cryo,     Reaction_type::NoReaction},
        {Color_damage::Dendro,   Reaction_type::NoReaction},
        {Color_damage::Electro,  Reaction_type::NoReaction},
        {Color_damage::Geo,      Reaction_type::NoReaction},
        {Color_damage::Hydro,    Reaction_type::NoReaction},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::NoReaction},
    }},
    {Color_damage::Hydro, {
        {Color_damage::Anemo,    Reaction_type::HydroSwirl},
        {Color_damage::Cryo,     Reaction_type::Frozen},
        {Color_damage::Dendro,   Reaction_type::Bloom},
        {Color_damage::Electro,  Reaction_type::ElectroCharged},
        {Color_damage::Geo,      Reaction_type::HydroCrystallize},
        {Color_damage::Hydro,    Reaction_type::NoReaction},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::Vaporize},
    }},
    {Color_damage::Physical, {
        {Color_damage::Anemo,    Reaction_type::NoReaction},
        {Color_damage::Cryo,     Reaction_type::NoReaction},
        {Color_damage::Dendro,   Reaction_type::NoReaction},
        {Color_damage::Electro,  Reaction_type::NoReaction},
        {Color_damage::Geo,      Reaction_type::NoReaction},
        {Color_damage::Hydro,    Reaction_type::NoReaction},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::NoReaction},
    }},
    {Color_damage::Piercing, {
        {Color_damage::Anemo,    Reaction_type::NoReaction},
        {Color_damage::Cryo,     Reaction_type::NoReaction},
        {Color_damage::Dendro,   Reaction_type::NoReaction},
        {Color_damage::Electro,  Reaction_type::NoReaction},
        {Color_damage::Geo,      Reaction_type::NoReaction},
        {Color_damage::Hydro,    Reaction_type::NoReaction},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::NoReaction},
    }},
    {Color_damage::Pyro, {
        {Color_damage::Anemo,    Reaction_type::PyroSwirl},
        {Color_damage::Cryo,     Reaction_type::Melt},
        {Color_damage::Dendro,   Reaction_type::Burning},
        {Color_damage::Electro,  Reaction_type::Overloaded},
        {Color_damage::Geo,      Reaction_type::PyroCrystallize},
        {Color_damage::Hydro,    Reaction_type::Vaporize},
        {Color_damage::Physical, Reaction_type::NoReaction},
        {Color_damage::Piercing, Reaction_type::NoReaction},
        {Color_damage::Pyro,     Reaction_type::NoReaction},
    }},
};

enum class Stage {
    DrawChangeCard,
    ChooseFrontCharacter,
    // DuelBegin,
    RoundBegin,
    RollDice,
    // ActionBegin,
    Action,
    // ActionEnd,
    // AnimeActionBegin,
    AnimeAction,
    // AnimeActionEnd,
    RoundEnd,
    // RoundEndResetDraw,
};

enum class Event {
    PlayCard,
    UseSkill,
    ElementalTuning,
    SwitchCharacter,
    RoundEnd,
};

} // namespace GITCGtool

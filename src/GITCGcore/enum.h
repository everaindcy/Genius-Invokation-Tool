#pragma once

namespace GITCGtool
{

enum class Color_damage {
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
    Physical,// 物理
    Piercing,// 穿透
};

enum class Color_dice {
    Pyro,    // 火
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

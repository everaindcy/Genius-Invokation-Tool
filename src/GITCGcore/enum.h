#pragma once

namespace GITCGtool
{

enum Color {
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
    Seven,   // 万能
};

enum Color_dice {
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
    Seven,   // 万能
};

enum Color_character {
    Pyro,    // 火
    Hydro,   // 水
    Anemo,   // 风
    Electro, // 雷
    Dendro,  // 草
    Cryo,    // 冰
    Geo,     // 岩
};

enum TriggerType {
    RoundBegin,
    Attack,
    Damage,
    ChangeCharacter,
    CharacterDie,
};

} // namespace GITCGtool

#pragma once

namespace GITCGtool
{
namespace GITCGcore
{


enum TriggerType {
    RoundBegin,
    RoundEnd,
    NormalAttack,
    ElementalSkill,
    ElementalBurst,
    Damage,
    ChangeCharacter,
    CharacterDie,
};

class Trigger
{
private:
    TriggerType type;
    
public:
    Trigger(/* args */);
    ~Trigger();
};

Trigger::Trigger(/* args */)
{
}

Trigger::~Trigger()
{
}

    

} // namespace GITCGcore
} // namespace GITCGtool

#pragma once

#include "GITCGcore/enum.h"
#include "GITCGcore/code.h"

#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

enum class SkillType {
    NormalAttack,
    ElementalSkill,
    ElementalBurst,
    Talent,
    Others,
};

class Skill
{
private:
    int index;
    string name;
    SkillType type;

    vector<Color_cost> cost;

    Code code_run;

public:
    Skill(/* args */);
    ~Skill();

    int index();
    string name();
    SkillType type();

    vector<Color_cost> cost();
};

Skill::Skill(/* args */)
{
}

Skill::~Skill()
{
}

    

} // namespace GITCGcore
} // namespace GITCGtool

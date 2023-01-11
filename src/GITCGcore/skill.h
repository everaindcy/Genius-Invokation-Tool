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

enum SkillType {
    NormalAttack,
    ElementalSkill,
    ElementalBurst,
    Talent,
    Others,
};

class Skill
{
private:
    string name;
    SkillType type;
    vector<Color_consume> color;
    Code code;

public:
    Skill(/* args */);
    ~Skill();
};

Skill::Skill(/* args */)
{
}

Skill::~Skill()
{
}

    

} // namespace GITCGcore
} // namespace GITCGtool

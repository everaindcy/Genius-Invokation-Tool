#pragma once

#include "enum.h"
#include "code.h"

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

    int get_index();
    string get_name();
    SkillType get_type();

    vector<Color_cost> get_cost();
};

Skill::Skill(/* args */)
{
}

Skill::~Skill()
{
}

    

} // namespace GITCGcore
} // namespace GITCGtool

#pragma once

#include "GITCGcore/code.h"

#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

enum class Summon_type {
    Shield,  // 护盾
    Others,
};

class Summon
{
private:
    int index;
    string name;
    Summon_type type;

    vector<int> data; // 各种数据

    Code code_initialize;
    Code code_run;
    Code code_death;

public:
    Summon(/* args */);
    ~Summon();

    int index();
    string name();
    Summon_type type();

    int& data_at(int);
};

Summon::Summon(/* args */)
{
}

Summon::~Summon()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

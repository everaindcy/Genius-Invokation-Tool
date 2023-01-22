#pragma once

#include "code.h"

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
                      // data[0] = 存在性
                      // data[1] = 可用次数/剩余回合

    Code code_initialize;
    Code code_run;
    Code code_death;

public:
    Summon(/* args */);
    ~Summon();

    int get_index();
    string get_name();
    Summon_type get_type();

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

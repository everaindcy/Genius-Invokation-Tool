#pragma once

#include "GITCGcore/code.h"

#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

enum Summon_type {
    
};

class Summon
{
private:
    string name;
    vector<int> data; // 各种数据
    Code code;

public:
    Summon(/* args */);
    ~Summon();
};

Summon::Summon(/* args */)
{
}

Summon::~Summon()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

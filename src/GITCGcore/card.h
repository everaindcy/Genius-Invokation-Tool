#pragma once

#include "GITCGcore/code.h"
#include "GITCGcore/enum.h"

#include <string>
#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

class Card
{
private:
    string name;
    vector<Color_consume> color;
    Code code;

public:
    Card(/* args */);
    ~Card();
};

Card::Card(/* args */)
{
}

Card::~Card()
{
}
    

} // namespace GITCGcore
} // namespace GITCGtool

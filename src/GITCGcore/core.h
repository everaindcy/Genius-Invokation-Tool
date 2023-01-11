#pragma once

#include "GITCGcore/enum.h"
#include "GITCGcore/card.h"
#include "GITCGcore/character.h"
#include "GITCGcore/summon.h"
#include "GITCGcore/skill.h"

#include <vector>
using namespace std;

namespace GITCGtool
{
namespace GITCGcore
{

typedef Color_dice Dice;

class Table
{
private:
    vector<Card> deck1;
    vector<Character> character1;
    int frontCharacter1;
    vector<Summon> support1;
    vector<Summon> summon1;
    vector<Summon> state1;
    vector<Card> hand1;
    vector<Dice> dice1;
    vector<Skill> skill1;

    vector<Card> deck2;
    vector<Character> character2;
    int frontCharacter2;
    vector<Summon> support2;
    vector<Summon> summon2;
    vector<Summon> state2;
    vector<Card> hand2;
    vector<Dice> dice2;
    vector<Skill> skill2;

public:
    Table();
    ~Table();

    void deck1_shuffle();
    
};

Table::Table()
{
}

Table::~Table()
{
}


} // namespace GITCGcore

} // namespace GITCGtool

#pragma once

#include "GITCGcore/enum.h"
#include "GITCGcore/card.h"
#include "GITCGcore/character.h"
#include "GITCGcore/invoked.h"

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
    vector<Invoked> support1;
    vector<Invoked> invoked1;
    vector<Invoked> state1;
    vector<Card> hand1;
    vector<Dice> dice1;

    vector<Card> deck2;
    vector<Character> character2;
    int frontCharacter2;
    vector<Invoked> support2;
    vector<Invoked> invoked2;
    vector<Invoked> state2;
    vector<Card> hand2;
    vector<Dice> dice2;

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

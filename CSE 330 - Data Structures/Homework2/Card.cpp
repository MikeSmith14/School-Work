/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Card.cpp
* Description - This is the file for class Card. It represents a single card.
* Implementation: Only has two constructors. Rest are in-lined in Card.h. Also overloaded
*                 operator << to output a card. Operator is non-member
* Modification - 02/12/2017 - Overload operator == in order to test if two cards are equal
********************************************/

#include "Card.h"

using namespace std;

//Default Constructor
Card::Card()
{
    rank = 1;
    suit = spade;
}

//Overload Constructor
//Takes in a specific rank and suit
Card::Card(suits sv, int rv)
{
    rank = rv;
    suit = sv;
}

//Allows the operator to output cards
ostream & operator<<(ostream & out, Card aCard)
{
    switch(int rank = aCard.getRank()){
        case 1: out << "Ace"; break;
        case 11: out << "Jack"; break;
        case 12: out << "Queen"; break;
        case 13: out << "King"; break;
        default: out << rank;
    }

    switch(suits suit = aCard.getSuit()){
        case diamond: out << " of Diamonds"; break;
        case spade: out << " of Spades"; break;
        case heart: out << " of Hearts"; break;
        case club: out << " of Clubs"; break;
    }
    return out;
}

//Overloaded Operator to test if two cards are equal to each other                                              modified 02/12/17 - Smith
bool Card::operator==(Card card1)
{
    if(this->getRank()==card1.getRank() && this->getSuit() == card1.getSuit())
        return true;
    else
        return false;
}

/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Deck.cpp
* Description - This file is the implementation of class Deck. Represents the entire deck
* Implementation: Based on Card, uses STL random_shuffle to shuffle cards
********************************************/

#include <algorithm>
#include "Card.h"
#include "Deck.h"
#include "Random.h"

using namespace std;

extern RandomInteger randomizer;

//Default Constructor
Deck::Deck()
{
    topCard = 0;
    for(int i = 1; i <=13; i++){
        Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
        cards[topCard++] = c1;
        cards[topCard++] = c2;
        cards[topCard++] = c3;
        cards[topCard++] = c4;
    }
}

//Draw from the Deck
Card Deck::draw()
{
    if (!isEmpty())
        return cards[--topCard];
    else{
        Card spadeAce(spade, 1);
        return spadeAce;
    }
}

//Shuffle the Deck
void Deck::shuffle()
{
    random_shuffle(cards, cards+52, randomizer);
}

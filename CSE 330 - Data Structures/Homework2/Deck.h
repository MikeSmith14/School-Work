/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Deck.h
* Description - This file is the definition of class Deck
* Implementation: As include file, provides the interface def.
********************************************/

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
    Card cards[52];     //Deck of all 52 cards
    int topCard;        //1 + index of next card
public:
    Deck();
    void shuffle();     //Uses the generic algorithm random_shuffle from STL
    bool isEmpty() {return topCard<=0;}
    Card draw();        //Return next card
};

#endif // DECK_H

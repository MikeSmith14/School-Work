/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: HumanPlayer.h
* Description - This file is the definition of class HumanPlayer
* Implementation: Derived from class Player.
********************************************/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Card.h"
#include "Deck.h"

class HumanPlayer: public Player
{
public:
    HumanPlayer(Deck &deck): Player(deck){}     //calls base constructor
    Card draw();                                //Another draw()!
};

#endif // HUMANPLAYER_H

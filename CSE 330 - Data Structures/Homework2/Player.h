/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Player.h
* Description - This file is the definition of class Player
* Implementation: only interface of a class is given in the header
*                 idealy even the implementation of in-line functions
*                 must reside in corresponding *.cpp file.
* Modified - 02/12/2017 - Added isEmpty() declaration
********************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

class Player
{
protected:
    Card myCards[3];
    int myScore;
    int removedCard;
public:
    Player(Deck &);
    Card draw();
    void addPoints(int howMany) {myScore += howMany;}
    bool isEmpty();                                                                 //Modified 02/12/2017 Smith
    void clearPosition();
    int score() {return myScore;}
    void replaceCard(Deck &aDeck) {myCards[removedCard] = aDeck.draw();}
};

#endif // PLAYER_H

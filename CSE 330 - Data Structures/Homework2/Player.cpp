/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Player.cpp
* Description - This file is the implementation of class Player
* Implementation: Constructor resets the score and picks 3 cards.
*                 the draw() method randomly chooses one of the three cards
* Modified - 02/12/2017 - Added a test to see if the player hand is empty.
********************************************/

#include "Player.h"
#include "Deck.h"
#include "Random.h"

using namespace std;

extern RandomInteger randomizer;

//Base constructor
Player::Player(Deck & aDeck)
{
    myScore = 0;
    for(int i = 0; i < 3; i++)
        myCards[i] = aDeck.draw();
    removedCard = 0;
}

//Randomly picks a card to play.
Card Player::draw()
{
    removedCard = randomizer(3);
    return myCards[removedCard];
}

//Test to see if the player hand is empty                                   modified - 02/12/2017 Smith
bool Player::isEmpty()
{
    Card test;
    if ((myCards[0] == test) && (myCards[1] == test) && (myCards[2] == test))
        return true;
    else
        return false;
}


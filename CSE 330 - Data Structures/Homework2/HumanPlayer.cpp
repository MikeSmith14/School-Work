/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: HumanPlayer.cpp
* Description - This file is the implementation of class HumanPlayer
* Implementation: Inherited from Player class. Only method draw() changes.
*                 allows the player the choice of which card to play
********************************************/

#include <iostream>
#include "HumanPlayer.h"
#include "Card.h"


using namespace std;

//Allows the human player to choose which card they would like to play
Card HumanPlayer::draw()
{
    cout << "You currently hold in your hand:" << endl;
    cout << "a) " << myCards[0] << endl;
    cout << "b) " << myCards[1] << endl;
    cout << "c) " << myCards[2] << endl;
    cout << "Which one do you want to play? ";

    char answer[80];
    removedCard=-1;
    while(removedCard == -1){
        cin >> answer;
        if(answer[0] == 'a')
            removedCard = 0;
        else if(answer[0] == 'b')
            removedCard = 1;
        else if(answer[0] == 'c')
            removedCard = 2;
        if(removedCard != -1)
            return myCards[removedCard];
        cout << "Please specify a, b, or c\n";
    }
}

/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Card.h
* Description - This is the file for the interface definition of Card class
* Implementation: Some functions are in-lined. The rest are in Card.cpp
* Modified - 02/12/2017 - Added an overload operator declaration to the header.
********************************************/
#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

enum suits {diamond, club, heart, spade};

class Card{

    int rank;
    suits suit;

public:
    //Constructors
    Card();
    Card(suits, int);

    //Accessors
    int getRank() {return rank;}
    suits getSuit() {return suit;}

    //Mutators
    void setRank(int rv) {rank = rv;}
    void setSuit(suits sv) {suit = sv;}

    //Overloaded Operators                                                      modified - 02/12/2017 Smith
    bool operator==(Card card1);
};

ostream & operator<<(ostream &, Card);

#endif // CARD_H

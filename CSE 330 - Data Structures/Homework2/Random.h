/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Player.cpp
* Description - This file is the definition  of class RandomInteger
* Implementation: Note extern declarition for randomizer
********************************************/

#ifndef RANDOM_H
#define RANDOM_H


class RandomInteger
{
public:
    RandomInteger();
    unsigned int operator()(unsigned int max);
};

#endif // RANDOM_H

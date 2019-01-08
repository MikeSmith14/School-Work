/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Random.cpp
* Description - This file is the implementation of class RandomInteger
* Implementation: Only one operator method is defined for this class.           ** FINISHES NOTES
********************************************/

#include <stdlib.h>         //for rand()
#include <time.h>           //for time()
#include "Random.h"

using namespace std;

//Base Constructor
RandomInteger::RandomInteger()
{
    srand(time(0));
}

unsigned int RandomInteger::operator()(unsigned int max)
{
    unsigned int rval = rand();
    return rval%max;
}

RandomInteger randomizer;

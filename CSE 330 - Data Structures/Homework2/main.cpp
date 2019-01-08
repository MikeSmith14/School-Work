/*******************************************
* Adapted from: Timothy Budd and Kay Zemoudeh
* Programmer: Michael Smith
* Date: 02/08/2017
* File: Player.cpp
* Description - this program simulates the game of war. each player gets
                3 cards. each player displays one of her cards.
                the player with the highest ranking card wins 2 points.
                in case of a tie each player gets 1 point. after each
                round, each player draws a new card from the deck.
* Implementation: this program uses 4 classes: Card, Deck, Player, and
                RandomInteger . it is a good example of Object Oriented
                Programming (OOP). Note the simplicity of each class and
                the main() function.

modified by:    kay zemoudeh
date:           8/19/98
modification:   the original program was a simulation of computer vs
                computer. this modification changes the program to make
                it an interactive game between a human player and
                computer. this was done by introducing a new class
                HumanPlayer and specifically its draw() method.

modified by:    kay zemoudeh
date:           8/20/98
modification:   changed the program to use a different seed for the
                random number generator, so that the deck is shuffled
                and the cards are drawn differently for each run.
                also in light of the fact that HumanPlayer and Player
                have a lot in common, changed HumanPlayer to inherit
                from Player.

modified by:    kay zemoudeh
date:           8/22/98
modification:   now uses separate compilation. each class is in its own
                file and is included here and/or linked with main object
                file.  To compile:
                     g++ -c Card.cpp
                     g++ -c Deck.cpp
                     g++ -c Player.cpp
                     g++ -c HumanPlayer.cpp
                     g++ -c Random.cpp
                     g++ -o war war.cpp Card.o Deck.o Player.o
                                   HumanPlayer.o Random.o
                Now, for example, Card.o can be linked to any other
                program that needs the Card class, without knowing the
                implementation details of Card, and without recompiling
                Card.cpp. Just include "Card.h" in the program.
                If "Card.h" is in another directory, you may specify
                where to look for it at compile time:
                     g++ -o war -I/other-dir-path war.cpp Card.o ...
                Alternatively consider using a makefile.

* Modified - 02/12/2017 - Changed the while loop to test if the player hand is empty instead
*                         of the Deck being empty. Making the game last until the player hand
*                         is empty (full of ace of spades).
********************************************/



#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "HumanPlayer.h"

using namespace std;

int main()
{
    Deck theDeck;       //creates deck
    theDeck.shuffle();

    //create to players
    HumanPlayer player1(theDeck);
    Player player2(theDeck);

    while(!player1.isEmpty()){                                          //Modified - 02/12/2017 Smith
        Card card1 = player1.draw();
        cout <<"Player 1 plays: " << card1 << endl;
        Card card2 = player2.draw();
        cout <<"Player 2 plays: " << card2 << endl;

        if(card1.getRank() == card2.getRank()){
            player1.addPoints(1);
            player2.addPoints(1);
            cout << "Players tie\n\n";
        }
        else if (card1.getRank() > card2.getRank()){
            player1.addPoints(2);
            cout << "Player 1 wins this round\n\n";
        }
        else{
            player2.addPoints(2);
            cout << "Player 2 wins this round\n\n";
        }
            //replace the cards drawn
            player1.replaceCard(theDeck);
            player2.replaceCard(theDeck);
    }

    cout << "Player 1 score: " << player1.score() << endl;
    cout << "Player 2 score: " << player2.score() << endl;
    if(player1.score() > player2.score())
        cout << "Player 1 wins\n";
    else if (player2.score() > player1.score())
        cout << "Player 2 wins\n";
    else
        cout << "It is a tie\n";
}









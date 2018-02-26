//
//  main.cpp
//  BullCowGame
//
//  Created by Cesar Caceres on 2/26/18.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


void Print_Intro();
string GetGuessAndPrintBack();

//main method and entry point
int main(int argc, const char * argv[])
{
    // Start Game by showing intro
    Print_Intro();
    
    //Loop for the number of turns to ask for guesses
    constexpr int NUMBER_OF_TURNS = 10;
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        //Get a guess from the user
        GetGuessAndPrintBack();
    }
    return 0;
}

void Print_Intro()
{
    constexpr int WORD_LENGTH = 3;
    
    //Introduction to the game
    cout << "Welcome to BULLS AND COWS!\n Have fun with words!\n";
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram?\n";
    cout << endl;
    
    return;
}

string GetGuessAndPrintBack()
{
    //Get a guess from the user
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);
    //Repeate the guess to the user
    cout << "Your Guess: " << Guess << endl;
    cout << endl;
    return Guess;
}

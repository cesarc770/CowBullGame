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

int main(int argc, const char * argv[]) {
    // insert code here...
    constexpr int WORD_LENGTH = 3;
    
    //Introduction to the game
    cout << "Welcome to BULLS AND COWS!\n Have fun with words!\n";
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram?\n";
    cout << endl;
    
    //Get a guess from the user
    cout << "Enter your guess: ";
    string Guess = "";
    getline(cin, Guess);
    
    //Repeate the guess to the user
    cout << "Your Guess: " << Guess << endl;
    cout << endl;
    
    return 0;
}

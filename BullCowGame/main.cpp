//
//  main.cpp
//  BullCowGame
//
//  Created by Cesar Caceres on 2/26/18.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void Print_Intro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


int main(int argc, const char * argv[])
{
    //main method and entry point
    bool PlayAgain = false;
    do
    {
        Print_Intro();
        PlayGame();
        PlayAgain  = AskToPlayAgain();
    } while(PlayAgain);
    return 0; //end of game
}

void Print_Intro()
{
    constexpr int WORD_LENGTH = 3;
    
    //Introduction to the game
    std::cout << "Welcome to BULLS AND COWS!\n Have fun with words!\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram?\n";
    std::cout << std::endl;
    
    return;
}

std::string GetGuess()
{
    //Get a guess from the user
    std::cout << "Enter your guess: ";
    std::string Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

void PlayGame()
{
    FBullCowGame BCGame;
    
    //Loop for the number of turns to ask for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        //Get a guess from the user and print it back to the user
        std::string Guess = GetGuess();
        std::cout << "Your Guess: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

bool AskToPlayAgain()
{
    std::string Response = "";
    std::cout << "Do you want to play again?(y/n) \n";
    std::getline(std::cin, Response);
    
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

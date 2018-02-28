//
//  main.cpp
//  BullCowGame
//
//  Created by Cesar Caceres.
//  Copyright © 2018 Cesar Caceres. All rights reserved.


/* This acts as the view in the MVC Pattern and will contain all that has to do with user interaction. The Game logic is in BullCowGame Class*/
#include <iostream>
#include <string>
#include "BullCowGame.hpp"

//function prototyping
void Print_Intro();
void PlayGame();
std::string GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

BullCowGame BCGame; // instantiating new game which is reused during each game

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
    //Introduction to the game
    std::cout << "\n\nWelcome to BULLS AND COWS!\n\n";
    std::cout << "\\|/          (__)" << std::endl;
    std::cout << "      \\------(oo)" << std::endl;
    std::cout << "       ||    (__)" << std::endl;
    std::cout << "       ||w--||     \\|/" << std::endl;
    std::cout << "   \\|/                " << std::endl;
    std::cout << "\nHave fun with words!\n\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram?\n";
    std::cout << std::endl;
    
    return;
}

//loop until user gives a valid guess
std::string GetValidGuess()
{
    WordStatus Status = WordStatus::Invalid_Status;
     std::string Guess = "";
    do
    {
        int CurrentTry = BCGame.GetCurrentTry();
        //Get a guess from the user
        std::cout << "Try #" << CurrentTry;
        std::cout << ". Enter your guess: ";
    
        std::getline(std::cin, Guess);
   
        Status = BCGame.CheckGuess(Guess);
        switch (Status) {
            case WordStatus::Wrong_Length :
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
                break;
            case WordStatus::Not_Isogram :
                std::cout << "Please enter a word without repeating letters.\n\n";
                break;
            case WordStatus::Not_Lowercase :
                std::cout << "Please enter all lowercases.\n\n";
                break;
            default:
                break;
        }
       
    }while (Status != WordStatus::OK);
    
    return Guess;
}

//Play each game until it is completed
void PlayGame()
{
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    
    std::cout << "You have " << MaxTries;
    std::cout << " tries to guess the correct word.\n";
    std::cout << std::endl;
    
    //Loop to ask for guesses while the game has not been won and there are tries available
    while(!BCGame.DidWinGame() && BCGame.GetCurrentTry() <= MaxTries)
    {
        //Get a guess from the user and print it back to the user
        std::string Guess = GetValidGuess();
        
        //submit valid guess to the game
        BullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        //print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
        
        std::cout << std::endl;
    }
    
    PrintGameSummary();
    return;
}

bool AskToPlayAgain()
{
    std::string Response = "";
    std::cout << "Do you want to play again?(y/n) \n";
    std::getline(std::cin, Response);
    
    return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
    if(BCGame.DidWinGame())
    {
        std::cout << "YOU WIN! -- JOB WELL DONE!\n\n";
    }
    else
    {
        std::cout << "YOU LOSE - BETTER LUCK NEXT TIME!\n\n";
    }
    return;
}

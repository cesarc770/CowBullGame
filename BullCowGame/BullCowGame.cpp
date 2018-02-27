//
//  BullCowGame.cpp
//  BullCowGame
//
//  Created by Cesar Caceres.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#include "BullCowGame.hpp"

BullCowGame::BullCowGame() { Reset(); }

int BullCowGame::GetCurrentTry() const { return CurrentTry; }
int BullCowGame::GetMaxTries() const { return MaxTries; }
int BullCowGame::GetHiddenWordLength() const { return HiddenWord.length(); }

bool BullCowGame::DidWinGame() const
{
    return false;
}

void BullCowGame::Reset()
{
    constexpr int MAX_TRIES = 8;
    MaxTries = MAX_TRIES;
    
    const std::string HIDDEN_WORD = "planet";
    HiddenWord = HIDDEN_WORD;
    CurrentTry = 1;
    return;
}

WordStatus BullCowGame::CheckGuess(std::string Guess) const
{
    if (false)//if the guess is not an isogram
    {
        return WordStatus::Not_Isogram;
    }
    else if (Guess.length() != GetHiddenWordLength()) //if guess is the wrong length
    {
        return WordStatus::Wrong_Length;
    }
    else if (false)//if guess is not all lowercase
    {
        return WordStatus::Not_Lowercase;
    }
    else //otherwise return OK
    {
        return WordStatus::OK;
    }
}

//Take a valid guess, count cows and bulls and increase # of tries
BullCowCount BullCowGame::SubmitGuess(std::string Guess)
{
    //increment turn number
    CurrentTry++;
    
    //setup return variable
    BullCowCount BullCowCount;
    
    int HiddenWordLength = HiddenWord.length();
    //loop through letters in the guess
    for(int i = 0; i < HiddenWordLength; i++){
        //compare letters in guess against letters in hidden word
        for(int j = 0; j < HiddenWordLength; j++){
            //if they match then
            if(HiddenWord[i] == Guess[j]){
                //if in the same place increment bulls
                if(i == j){
                    BullCowCount.Bulls++;
                }
                //if not in the same place increment cows
                else{
                    BullCowCount.Cows++;
                }
            }
        }
    }
    return BullCowCount;
}










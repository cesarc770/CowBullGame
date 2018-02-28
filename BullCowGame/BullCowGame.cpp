//
//  BullCowGame.cpp
//  BullCowGame
//
//  Created by Cesar Caceres.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#include "BullCowGame.hpp"
#include <map>

BullCowGame::BullCowGame() { Reset(); }

int BullCowGame::GetCurrentTry() const { return CurrentTry; }
int BullCowGame::GetMaxTries() const { return MaxTries; }
int BullCowGame::GetHiddenWordLength() const { return HiddenWord.length(); }
bool BullCowGame::DidWinGame() const { return GameIsWon; }

void BullCowGame::Reset()
{
    constexpr int MAX_TRIES = 3;
    MaxTries = MAX_TRIES;
    
    const std::string HIDDEN_WORD = "planet";
    HiddenWord = HIDDEN_WORD;
    CurrentTry = 1;
    GameIsWon = false;
    return;
}

WordStatus BullCowGame::CheckGuess(std::string Guess) const
{
    if (!isIsogram(Guess))//if the guess is not an isogram
    {
        return WordStatus::Not_Isogram;
    }
    else if (Guess.length() != GetHiddenWordLength()) //if guess is the wrong length
    {
        return WordStatus::Wrong_Length;
    }
    else if (!isLowerCase(Guess))//if guess is not all lowercase
    {
        return WordStatus::Not_Lowercase;
    }
    else //otherwise return OK
    {
        return WordStatus::OK;
    }
}

//Take a valid guess, count cows and bulls and increase # of tries
BullCowCount BullCowGame::SubmitValidGuess(std::string Guess)
{
    CurrentTry++;

    BullCowCount BullCowCount;
    
    int WordLength = HiddenWord.length();
    //loop through letters in the hidden word
    for(int i = 0; i < WordLength; i++){
        //compare letters in guess against letters in hidden word
        for(int j = 0; j < WordLength; j++){
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
    if(BullCowCount.Bulls == WordLength)
    {
        GameIsWon = true;
    }
    else
    {
        GameIsWon = false;
    }
    return BullCowCount;
}

bool BullCowGame::isIsogram(std::string Word) const
{
    //0 and 1 letter words are isograms
    if(Word.length() <= 1){ return true; }
    
    std::map<char, bool> LetterSeen;//define map
    for(auto Letter : Word)
    {
        Letter = tolower(Letter); //Handling all case types
        //if letter is in map
        if(LetterSeen[Letter])
        {
            return false;  //is not an isogram
        }
        else
        {
            LetterSeen[Letter] = true;//otherwise add letter to map
        }
    }
    return true;
}

bool BullCowGame::isLowerCase(std::string Word) const {
    for (auto Letter : Word)
    {
        if (!islower(Letter))
        {
            return false;
            
        }
    }
    
    return true;
}












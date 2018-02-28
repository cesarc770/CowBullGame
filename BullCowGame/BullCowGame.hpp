//
//  BullCowGame.hpp
//  BullCowGame
//
//  Created by Cesar Caceres.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#include <string>

struct BullCowCount
{
    int Bulls = 0;
    int Cows = 0;
};

enum WordStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class BullCowGame {
public:
    BullCowGame(); //This is a constructor
    int GetMaxTries() const;
    int GetCurrentTry() const;
    int GetHiddenWordLength() const;
    bool DidWinGame() const;
    void Reset();
    WordStatus CheckGuess(std::string) const;
    BullCowCount SubmitValidGuess(std::string);
    
   
    
private:
    //initialization in constructor definition
    int CurrentTry;
    int MaxTries;
    std::string HiddenWord;
    bool GameIsWon;
    
    bool isIsogram(std::string) const;
    bool isLowerCase(std::string) const;
};

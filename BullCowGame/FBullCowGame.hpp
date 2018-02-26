//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Cesar Caceres.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#pragma once
#include <string>

class FBullCowGame {
public:
    FBullCowGame(); //This is a constructor
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool DidWinGame() const;
    void Reset();
    bool checkGuess(std::string);
    
   
    
private:
    //initialization in constructor definition
    int CurrentTry;
    int MaxTries;
};

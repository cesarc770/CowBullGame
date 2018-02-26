//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Cesar Caceres on 2/26/18.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#pragma once
#include <string>

class FBullCowGame {
public:
    void Reset();
    int GetMaxTries();
    int GetCurrentTry();
    bool checkGuess(std::string);
    bool DidWinGame();
   
    
private:
    int CurrentTry;
    int MaxTries;
};

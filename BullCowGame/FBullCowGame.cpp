//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Cesar Caceres.
//  Copyright © 2018 Cesar Caceres. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetCurrentTry() const
{
    return CurrentTry;
}


int FBullCowGame::GetMaxTries() const
{
    return MaxTries;
}

bool FBullCowGame::DidWinGame() const
{
    return false;
}

void FBullCowGame::Reset()
{
    constexpr int MAX_TRIES = 8;
    MaxTries = MAX_TRIES;
    CurrentTry = 1;
    return;
}


bool FBullCowGame::checkGuess(std::string) { 
    return false;
}







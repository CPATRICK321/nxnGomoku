//File Name: Lab4.cpp
//Author: Christopher Patrick c.r.patrick@wustl.edu
//Description: This file takes input from the command line, interprets it, and plays a game 
    //according to the input specified.

#include <iostream>
#include <memory>
#include <string>

using namespace std;

#include "Common.h"
#include "TicTacToe.h"

int main(int argc, char* argv[])
{
    shared_ptr<GameBase> obj;
    //checks for bad allocation and dimensions validity
    try {
        obj = GameBase::makeObj(argc, argv);
    }
    catch (bad_alloc) {
        return usage(argv[programName], badAlloc, "bad allocation has been thrown");
    }
    catch (...) {
        return usage(argv[programName], invalidDimensions, "If you'd like to specify dimensions, be sure it is greater than or equal to 3. Note that the second input, the amount in a row, needs to be less than or equal to the dimensions. EG) Lab4.exe Gomoku 12 11");
    }
    //if object didn't fail to be created
    if (obj != 0) {
        //try catch for quit
        try {
            return (*obj).GameBase::play();
        }
        catch (...) {
            return usage(argv[programName], userQuit, "Sorry to see you go");
        }
    }
    else {
        return usage(argv[programName], invalidFirstArg, "should have 'TicTacToe' or 'Gomoku' as its argument. For example : 'Lab4.exe TicTacToe'");
    }

    return successful;
}


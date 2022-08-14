//File Name: Common.cpp
//Author: Christopher Patrick c.r.patrick@wustl.edu
//Description: This file contains the usage function that main uses to return a unique value.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "Common.h"
#include "TicTacToe.h"

int usage(char* program, TTTreturns returnValue,string message) {
    //helpful messages on how to run the program
    cout << program << " " << message << endl;
    return returnValue;//incargs
}



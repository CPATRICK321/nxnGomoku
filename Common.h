#pragma once

//File Name: Common.h
//Author: Christopher Patrick c.r.patrick@wustl.edu
//Description: This file contains neccessary declarations for Lab4.cpp. These include enumerations for important
//	argv positions and function declarations.

#include "TicTacToe.h"

typedef unsigned int UINT;

enum ArgValues {
	programName,
	game,
	dimensions,
	inarow,
	argumentAmount = 2
};

int usage(char* program, TTTreturns returnValue, string message);
#pragma once
//File Name: TicTacToe.h
//Author: Christopher Patrick c.r.patrick@wustl.edu
//Description: This file contains enumerations for return types, functions declarations, and the class structure to make
	//TicTacToe objects

#include <vector>
#include "Common.h"

enum TTTreturns {
	successful,
	userQuit,
	drawGame,
	badArgAmount,
	invalidFirstArg,
	badAlloc,
	invalidDimensions
};


//replaces chars in a string with a different char
void customReplace(string* text, char x, char y);
//determines how much space each piece should take
int getLongestPiece(int num);
//helper function used to see if the string only has digits
bool isInteger(string digs);


class GameBase {
protected:
	int longestPiece;//strlen of largest piece
	int height;
	int width;
	std::vector<std::string> pieces;
	std::vector<std::vector<int>> winningPos;
	std::vector<int> temps;
	const int iar;
	std::vector<std::string> pieceStrings;
	friend ostream& operator<<(ostream& ost, const GameBase& B);
public:
	GameBase(int l, int inRow, std::string pOne, std::string pTwo);
	virtual TTTreturns prompt(unsigned int& a, unsigned int& b);
	TTTreturns play();
	static shared_ptr<GameBase> makeObj(int argc, char* argv[]);
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual void turn() = 0;
	//helper functions I made
	virtual void populateWinningPos();
	bool proper(int one, int two);
};

class TicTacToe : public GameBase{
	public:
		TicTacToe();
		virtual bool done();
		virtual bool draw();
		virtual void turn();
		virtual void print() override;
};

class Gomoku : public GameBase {
public:
	Gomoku(int height, int rowCount);
	virtual bool done();
	virtual bool draw();
	virtual void turn();
	virtual void print() override;
protected:
	friend ostream& operator<<(ostream& ost, const Gomoku& B);
};

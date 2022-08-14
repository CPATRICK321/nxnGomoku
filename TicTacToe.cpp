//File Name: TicTacToe.cpp
//Author: Christopher Patrick c.r.patrick@wustl.edu
//Description: This file contains neccessary function definitions to play the game. These include prompting to make a move, 
	//checking the win state of the game, and printing out the board. There are also helper functions (customReplace() and
	//proper()) which help with the technical implementation of the game.

#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

#include "Common.h"
#include "TicTacToe.h"

//these contain the moves made by each player
vector<string> xMoves;
vector<string> oMoves;
//this will represent the amount of moves that have been made
int moveCount;

//insertion operator
ostream& operator<<(ostream& ost, const GameBase& B) {
	//for top line
	for (int i = B.height + 1; i >= 0; i--) {
		if (i == B.height + 1) {
			ost << setw(B.longestPiece) << to_string(B.height + 1);
		}
		else {
			ost << setw(B.longestPiece) << " ";
		}
	}
	ost << endl;
	//board formatting

	for (int i = B.height - 1; i >= 0; i--) {
		ost << to_string(i + 1) << " ";
		for (int j = 0; j < B.width; j++) {
			//got rid of +1 in height
			ost << setw(B.longestPiece) << " " << B.pieces[(int)((B.height ) * i + j)];
		}
		ost << endl;
	}

	//second to bottom line
	ost << setw(B.longestPiece) << "0" << " ";
	for (int i = 0; i < B.width + 3; i++) {
		ost << setw(B.longestPiece) << " " << " ";
	}
	ost << endl;

	//bottom line
	ost << setw(B.longestPiece) << " ";
	for (int i = 0; i < B.width + 3; i++) {
		ost << setw(B.longestPiece) << to_string(i) <<" ";
	}


	return ost;
}

ostream& operator<<(ostream& ost, const Gomoku& B) {
	//board formatting

	for (int i = B.height ; i >= 1; i--) {
		ost << setw(B.longestPiece) << to_string(i) << " ";
		for (int j = 0; j < B.width; j++) {
			//got rid of +1 in height
			ost << setw(B.longestPiece) << B.pieces[(int)((B.height) * (i-1) + j)]<< " ";
		}
		ost << endl;
	}

	//bottom line
	ost << setw(B.longestPiece) << "X" << " ";
	for (int i = 1; i < B.width +1; i++) {
		ost << setw(B.longestPiece) << to_string(i) << " ";
	}

	return ost;
}

void TicTacToe::print() {
	cout << *this;
}

void Gomoku::print() {
	cout << *this;
}


GameBase::GameBase(int l, int inRow, std::string pOne, std::string pTwo) : height(l), width(l), iar(inRow), longestPiece(getLongestPiece(l)) {
	//defining the empty board
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width ; j++) {
			//fill the vector with empty spaces
			pieces.push_back(" ");
		}
	}
	//putting the player pieces in the piece vector
	pieceStrings.push_back(pOne);
	pieceStrings.push_back(pTwo);
};

TicTacToe::TicTacToe() : GameBase(3, 3, "X", "O") {
	//the GameBase contructor will be called, passing in the height(3), in-a-row count(3), and piece strings
};
Gomoku::Gomoku(int height, int rowCount) : GameBase(height, rowCount, "B", "W") {
	//the GameBase contructor will be called, passing in the height, in-a-row count, and piece strings
};

bool TicTacToe::done() {
	populateWinningPos();
	int xMatched = 0;
	int oMatched = 0;
	//for each set of winning numbers,
	for (unsigned int i = 0; i < winningPos.size(); i++) {
		//look at each of those numbers,
		for (unsigned int j = 0; j < winningPos[0].size(); j++) {
			//and see if the string at that position is x or o
				//increment each time 
				if (pieces[winningPos[i][j]] == pieceStrings[0]) {
					xMatched++;
				}
				else if (pieces[winningPos[i][j]] == pieceStrings[1]) {
					oMatched++;
				}
				if (xMatched == iar) {
					return true;
				}
				else if (oMatched == iar) {
					return true;
				}
		}
		//this is when the alg will look at a different set of winning nums
		xMatched = 0;
		oMatched = 0;
	}
	xMatched = 0;
	oMatched = 0;
	return false;
};

//returns true if the game is a draw; false otherwise
bool TicTacToe::draw() {
	if (done() == true) {
		return false;
	}
	for (int i = 0; i < 9; i++) {
		if (pieces[i] == " ") {
			return false;
		}
	}
	return true;
};

bool Gomoku::draw() {
	if (done() == true) {
		return false;
	}
	for (int i = 0; i < (width*height); i++) {
		//if any positions are empty, then the game is not a draw
		if (pieces[i] == " ") {
			return false;
		}
	}
	return true;
};

bool Gomoku::done() {
	populateWinningPos();

	int xMatched = 0;
	int oMatched = 0;
	//for each set of winning numbers,
	for (unsigned int i = 0; i < winningPos.size(); i++) {
		//look at each position,
		for (unsigned int j = 0; j < winningPos[0].size(); j++) {
			//and see if the string at that position is x or o
				//increment each time 
			if (pieces[winningPos[i][j]] == pieceStrings[0]) {
				xMatched++;
			}
			else if (pieces[winningPos[i][j]] == pieceStrings[1]) {
				oMatched++;
			}
			if (xMatched == iar) {
				return true;
			}
			else if (oMatched == iar) {
				return true;
			}
		}
		//reset the amount matched so we can look at different set of winning nums
		xMatched = 0;
		oMatched = 0;
	}
	xMatched = 0;
	oMatched = 0;
	return false;
};


TTTreturns GameBase::prompt(UINT& a, UINT& b) {
	int x = 0;
	int y = 0;
	//this string will be used to check if there is a third parameter that is not an integer
	string z;
	string input;

	while (!(input == "quit")) {

		cout << "enter a coordinate in the form '0,0' or quit with 'quit'" << endl;
		getline(cin, input);
		cin.clear();
		customReplace(&input, ' ', '-');
		replace(input.begin(), input.end(), ',', ' ');
		istringstream iss(input);
		//sees if there is one int
		if (iss >> x) {
			//sees if there are two ints
			if (iss >> y) {
				//sees if there are not three ints/strings
				if (!(iss >> z)) {
					//checks to see if the coord is in the actual board
					if (proper(x, y)) {
						break;
					}
				}
			}
		}
	}
	
	if (input == "quit") {
		throw userQuit;
	}
	a = x;
	b = y;
	return successful;
};

//this will see if the two integers passed in are inside of the game board
bool GameBase::proper(int one, int two) {
	int moveIndex = (one-1) + two*(width-1);
	for (int i = 0; i < height; i++) {
		//if it is within the ith row
		if ((moveIndex >= i*width && moveIndex <= (i * width) + width)) {
			return true;
		}
	}
	
	return false;
};

void TicTacToe::turn() {
	UINT xMove = 0;
	UINT yMove = 0;
	//if it is xs turn
	if (moveCount % 2 == 0) {
		cout << "Player " << pieceStrings[0] << endl;
	}
	else {
		cout << "Player " << pieceStrings[1] << endl;
	}

		do {
			prompt(xMove, yMove);
		}
			//if the position is not empty, then prompt again
		while (pieces[(int)((yMove - 1.0) * width + (xMove - 1.0) )] != " ");

		//update the board
		if (moveCount % 2 == 0) {
			pieces[(int)((yMove - 1.0) * width + (xMove - 1.0))] = pieceStrings[0];
			string xstr = to_string(xMove) + "," + to_string(yMove);
			xMoves.push_back(xstr);
			//print out board moves made by this player
			cout << "\n" << *this << endl;
			cout << "Player " << pieceStrings[0] << ": ";
			for (string moov: xMoves) {
				cout << moov << "; ";
			}
			cout << "\n" << endl;
		}
		else {
			pieces[(int)((yMove - 1.0) * width + (xMove - 1.0))] = pieceStrings[1];
			string ostr = to_string(xMove) + "," + to_string(yMove);
			oMoves.push_back(ostr);
			//print out board and moves made by this player
			cout << "\n" << *this << endl;
			cout << "Player " << pieceStrings[1] << ": ";
			for (string moov : oMoves) {
				cout << moov << "; ";
			}
			cout << "\n" << endl;
		}
		moveCount++;

};

void Gomoku::turn() {
	UINT xMove = 0;
	UINT yMove = 0;
	//if it is xs turn
	if (moveCount % 2 == 0) {
		cout << "Player " << pieceStrings[0] << endl;
	}
	else {
		cout << "Player " << pieceStrings[1] << endl;
	}

	do {
		prompt(xMove, yMove);
	}
	//if the position is not empty, then prompt again
	while (pieces[(int)((yMove - 1.0) * width + (xMove - 1.0))] != " ");

	//update the board
	if (moveCount % 2 == 0) {
		pieces[(int)((yMove - 1.0) * width + (xMove - 1.0))] = pieceStrings[0];
		string xstr = to_string(xMove) + "," + to_string(yMove);
		xMoves.push_back(xstr);
		//print out board moves made by this player
		cout << "\n" << *this << endl;
		cout << "Player " << pieceStrings[0] << ": ";
		for (string moov : xMoves) {
			cout << moov << "; ";
		}
		cout << "\n" << endl;
	}
	else {
		pieces[(int)((yMove - 1.0) * width + (xMove - 1.0))] = pieceStrings[1];
		string ostr = to_string(xMove) + "," + to_string(yMove);
		oMoves.push_back(ostr);
		//print out board and moves made by this player
		cout << "\n" << *this << endl;
		cout << "Player "<< pieceStrings[1] << ": ";
		for (string moov : oMoves) {
			cout << moov << "; ";
		}
		cout << "\n" << endl;
	}
	moveCount++;

};

shared_ptr<GameBase> GameBase::makeObj(int argc, char* argv[]) {
	//if no dimensions are specified
	if (argc == 2) {
		if (string(argv[game]) == "TicTacToe") {
			shared_ptr<TicTacToe> c = make_shared<TicTacToe>();
			return c;
		}
		else if (string(argv[game]) == "Gomoku") {
			shared_ptr<Gomoku> c = make_shared<Gomoku>(19, 5);
			return c;
		}
		else {
			return 0;
		}
	}
	//if only the dimension is thought to be specified
	else if (argc == 3) {
		if (isInteger(argv[dimensions])) {
			char* ptr;
			int num = strtol(argv[dimensions], &ptr, 10);
			if (num >= 5) {
				shared_ptr<Gomoku> c = make_shared<Gomoku>(num, 5);
				return c;
			}
			else if(num >= 3 && num < 5){
				shared_ptr<Gomoku> c = make_shared<Gomoku>(num, num);
				return c;
			}
			else {
				cout << "dimensions are bad";
				throw "invalidDimensions";
			}
		}
		else {
			throw "not integers";
		}
	}
	else if(argc == 4){
		//if they are both integers
		if (isInteger(argv[dimensions]) && isInteger(argv[inarow])) {
			char* ptr;
			//num will represent dimensions
			int num = strtol(argv[dimensions], &ptr, 10);
			char* ptr2;
			//num2 will represent in-a-row amount
			int num2 = strtol(argv[inarow], &ptr2, 10);
			if (num2 <= num) {
				if (num2 >= 3) {
					shared_ptr<Gomoku> c = make_shared<Gomoku>(num, num2);
					return c;
				}
				else {
					throw "invalidDimensions";
				}
			}
			else {
				throw "invalidDimensions";
			}
		}
		return 0;
	}
	else {
		throw "wrong arg amount";
	}
}

TTTreturns GameBase::play() {
	moveCount = 0;
	cout << "\n" ;
	print();
	cout << "\n";
	//10 iterations for the longest possible game
	while (moveCount < width*height) {
		//asks for turn. Note that turn() prints the board
		turn();
		//sees if the game is over
		if (done() == true) {
			//if x made the last move
			if (moveCount % 2 == 1) {
				cout << pieceStrings[0] << " WON!" << endl;
			}
			//if o made the last move
			else {
				cout << pieceStrings[1] << " WON!" << endl;
			}
			return successful;
		}
		//sees if the game is a draw
		if (draw() == true) {
			cout << "The game is a draw. 9 moves were played" << endl;
			return drawGame;
		}
	}
	return successful;

};

//this was used to replace any spaces in the input with '-'
void customReplace(string *text, char x, char y) {
	for (unsigned int i = 0; i < (*text).length(); i++) {
		if ((*text)[i] == x) {
			(*text)[i] = y;
		}
	}
}

void GameBase::populateWinningPos() {
	const int inARow = iar;
	//initializing current checks for win

	//go through all board for HORIZONTAL WINS
	for (int i = 0; i < (width * width) - iar + 1; i++) {
		//set each of the five to different values
		for (int j = 0; j < iar; j++) {
			temps.push_back(i + j);
		}
		//if they are on the same line
		if ((temps[iar - 1] % width - temps[0] % width) == (iar - 1)) {
			winningPos.push_back(temps);
			temps.clear();
		}
		temps.clear();
	}

	//go through all board for VERTICAL WINS
	for (int i = 0; i < (width * width) - (iar - 1) * (width); i++) {
		//set each of the five to different values
		for (int j = 0; j < iar; j++) {
			temps.push_back(i + (j * width));
		}
		//temps will always be a win state, so push them
		winningPos.push_back(temps);
		temps.clear();
	}

	//for the diagonals going up and right

	for (int i = 0; i < (width * width) - (iar - 1) * (width); i++) {
		if ((i % width) < ((width - iar) + 1)) {
			for (int j = 0; j < iar; j++) {
				temps.push_back(i + (j * width) + j);
			}
			winningPos.push_back(temps);
			temps.clear();
		}
	}

	//for the diagonals going up and left

	for (int i = 0; i < (width * width) - (iar - 1) * (width); i++) {
		if ((i % width) > (iar - 2)) {
			for (int j = 0; j < iar; j++) {
				temps.push_back(i + (j * width) - j);
			}
			winningPos.push_back(temps);
			temps.clear();
		}
	}
}

int getLongestPiece(int num) {
	int a = 1;
	int x = 10;
	int b = num;
	while (b != (b % x)) {
		x = x * 10;
		a++;
	}
	return a;

}

//this function will be used to see if the input is an integer
bool isInteger(string digts) {
	for (char a : digts) {
		if (!(isdigit(a))) {
			return false;
		}
	}
	return true;
}
Christopher Patrick c.r.patrick@wustl.edu
Lab 4

Functions 

	bool GameBase::proper(int one, int two);
		This is a helper function I made to check whether the coordinate given by the user is within the game board
	TTTreturns GameBase::play();
		This prints out the board and initializs the move count. While the move count is less that 10, play with call turn() to 
		make a move and check to see if anyone has won or the game has been drawn.
	static shared_ptr<GameBase> GameBase::makeObj(int argc, char* argv[]);
		This function checks that the command line args, which specify game type, dimensions, and amount needded in a row
		aren't invalid. If they are valid, then the function returns a shared pointer to a new object of the specified type.
	void GameBase::populateWinningPos();
		This populates the members variable, which is a vector, with the positions such that if one person has them, they
		win the game. This works for any n by n board with m in a row, with the precondition m<=n.
	ostream& operator<<(ostream& ost, const GameBase& B);
		This accepts a GameBase object and prints out the current position of the board. This function is used to print out
		the TicTacToe object.
	TicTacToe();
		I made the constructor of a TicTacToe object call the GameBase constructor, which defines the height, width, and in
		a row member variables to 3, initializes the board, and makes the piece appear as "X" and "O".
		with the correct labels.
	bool TicTacToe::done();
		This will iterate over the sets of winning numbers and see if any one player has achieved three in a row/column/diagnol.
		It will return true if this is the case and false otherwise.
	bool TicTacToe::draw();
		This method checks if the game is a draw by calling the done() method and by seeing if there are any empty spaces within
		the game board. It will return true if the game is a draw; false otherwise.
	void TicTacToe::turn();
		This method uses 'moves' to decide whos turn it is based on how many moves have been made. It then calls prompt to get a
		valid move. It may call prompt repeatedly if the coordinate on the board has already been taken. It then makes the move
		by changing a value in the pieces vector. Lastly, it prints out the board and all of the moves that have been made by the 
		player who just moved.
	void TicTacToe::print();
		This uses the insertion operator to cout the board position.
	Gomoku(int height, int rowCount);
		I made the constructor of a TicTacToe object call the GameBase constructor, which defines the height and width as height
		, the in a row member variable to rowCount, initializes the board, and makes the piece appear as "X" and "O".
		with the correct labels.
	bool Gomoku::done();
		This will iterate over the sets of winning numbers and see if any one player has achieved three in a row/column/diagnol.
		It will return true if this is the case and false otherwise.
	bool Gomoku::draw();
		This method checks if the game is a draw by calling the done() method and by seeing if there are any empty spaces within
		the game board. It will return true if the game is a draw; false otherwise.
	void Gomoku::turn();
		This method uses 'moves' to decide whos turn it is based on how many moves have been made. It then calls prompt to get a
		valid move. It may call prompt repeatedly if the coordinate on the board has already been taken. It then makes the move
		by changing a value in the pieces vector. Lastly, it prints out the board and all of the moves that have been made by the 
		player who just moved.
	void Gomoku::print();
		This uses the insertion operator to cout the board position.
	ostream& Gomoku::operator<<(ostream& ost, const Gomoku& B);
		This couts the board's state according to the lab instructions' guidelines.
	void customReplace(string* text, char x, char y);
		I made this helper function to replace spaces is the user input with dashed. However, it can replace any character with
		another by passing in parameters
	bool isInteger(string dgts);
		This helper function takes in a string and returns a boolean which indicates if the string can be converted into an integer.
	int getLongestPiece(int num);
		This takes the dimensions that the board will be and determines how much space each piece should take up, based
		on that integer's string length.
	TTTreturns usage(char* program, TTTreturns returnValue, string message);
		This function prints out the name of the program along with a message to explain what went wrong. It returns an enumeration,
		which is returned in main.

Build Warnings
	"warning C4018: '<': signed/unsigned mismatch"
		

	"The enum type TTTreturns is unscoped"
		
		Professor Shidal said this is okay so I kept it this way.

Tests

	Input:"Lab3.exe Chess"
	Output:"Lab3.exe should have 'TicTacToe' as its argument. For example : 'Lab3.exe TicTacToe'"
	
	Input:"Lab3.exe TicTacToe random"
	Output: "lab3.exe should take one line argument. For example : 'Lab3.exe TicTacToe'"

	Input:"Lab3.exe TicTacToe random"
	Output: "lab3.exe should take one line argument. For example : 'Lab3.exe TicTacToe'"

		Input:"Lab3.exe TicTacToe"
	Output:
"
4
3
2
1
0
  0 1 2 3 4

Player X
enter a coordinate in the form '0,0' or quit with 'quit'

"
	
	Input: Player X puts piece at 1,1
	Output:
"
4
3
2
1   X
0
  0 1 2 3 4

Player X: 1,1;
"
	Input: Player O moves to 2,2
	Output:
"
4
3
2     O
1   X
0
  0 1 2 3 4

Player O: 2,2;
"

	Input: Invalid coordinate 43,42
	Output:
"
Player X
enter a coordinate in the form '0,0' or quit with 'quit'
43, 42
enter a coordinate in the form '0,0' or quit with 'quit'
"

	Input: Coordinate 1,1 which has already been played
	Output:
"
enter a coordinate in the form '0,0' or quit with 'quit'
1,1
enter a coordinate in the form '0,0' or quit with 'quit'
"

	Input "quit"
	Output:
"
enter a coordinate in the form '0,0' or quit with 'quit'
quit
lab3.exe Sorry to see you go
"

	Input: 3,1 which makes x win the game
	Output:
"
Player X
enter a coordinate in the form '0,0' or quit with 'quit'
3,1

4
3     O
2     O
1   X X X
0
  0 1 2 3 4

Player X: 1,1; 2,1; 3,1;

X WON!
"

	Input: Poorly-formed input
	Output:
"
enter a coordinate in the form '0,0' or quit with 'quit'
0 , 0
enter a coordinate in the form '0,0' or quit with 'quit'
"

FOR GOMOKU
	Input: "Lab4.exe Gomoku"
	Output:
"
19
18
17
16
15
14
13
12
11
10
 9
 8
 7
 6
 5
 4
 3
 2
 1
 X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
"

	input: A game in which a player gets 5 in a row
	output:
"
19
18
17
16
15
14
13
12
11
10
 9
 8
 7                    W
 6                 W  W
 5  B
 4  B
 3  B
 2  B  W
 1  B
 X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
Player B: 1,1; 1,2; 1,3; 1,4; 1,5;

B WON!
"
	Input: invalid coordinates (33, 33)
	Output: "enter a coordinate in the form '0,0' or quit with 'quit'"

	Input: Coordinate 1,1 which has already been played
	Output:
"
enter a coordinate in the form '0,0' or quit with 'quit'
1,1
enter a coordinate in the form '0,0' or quit with 'quit'
"

	All of these tests were satisfactory in that they did what I expected and what the lab instructions directed.

EXTRA CREDIT
	Summary
		The two most difficult parts were makingn a vector with sets of winning positions
		given the dimensions and the amount needed in a row. I accomplished this by
		splitting the wins (horizontal, vertical, diagonal up-left, diagonal up-right)
		into different cases. These were all different. For example, the horizontal
		win algorithm used modulus to check if all of the positions were in the same row,
		while the diagonal algorithms used carefully constructed for-loops. Checking for
		these wins, or comparing the current board to the vector of vectors with the 
		winning positions, was accomplished with nested for-loops which tallied how
		many numbers matched for each player per set.
	Usage
		"lab4.exe Gomoku 10 5" will make a 10x10 board and you will need 5 in a row to win
		"lab4.exe Gomoku 10" will make a 10x10 board and you will need 5 in a row to win 
		*when given one dimension, it will default to 5, unless the given dimension is less than 5*
		"lab4.exe Gomoku 4" will make a 4x4 board and you will need 4 in a row to win 
	Example
		input: "lab4.exe Gomoku 6 4"
		output:
"
6
5
4
3
2
1
X 1 2 3 4 5 6
Player B
enter a coordinate in the form '0,0' or quit with 'quit'
"
		input: winning position for B
		output:
"
6
5
4 B
3 B   W
2 B W
1 B B W W
X 1 2 3 4 5 6
Player B: 1,1; 2,1; 1,2; 1,3; 1,4;

B WON!
"
		input: "lab4.exe Gomoku 1 100"
		output: "lab4.exe If you'd like to specify dimensions, 
		be sure it is greater than or equal to 3. Note that the second input, 
		the amount in a row, needs to be less than or equal to the 
		dimensions. EG) Lab4.exe Gomoku 12 11"

		input: "lab4.exe Gomoku 9 notAnInteger"
		output: "lab4.exe If you'd like to specify dimensions, 
		be sure it is greater than or equal to 3. Note that the second input, 
		the amount in a row, needs to be less than or equal to the 
		dimensions. EG) Lab4.exe Gomoku 12 11"
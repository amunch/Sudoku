//Sudoku.h
//Interface and implementation for a templated sudoku class
//Lab 5
//By: Andy Munch

#ifndef PUZZLE_H
#define PUZZLE_H //Prevent class redefintion.


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T> //Templated for concise code for use with both sudoku and wordoku boards.
class Puzzle {
	public:
		Puzzle(); //Default constructor that will set the private data members.
		void print(); //Function to print the board to the screen.
		void place(); //Place the value on the specified position. 
		bool won(); //Check if the user has won the game.
		bool check(int value, int row, int column); //Check if a move is valid.
	private:
		vector<vector <T> > puzzle; //Vector array that will hold the board.
		vector<vector <T> > original; //Copy of the original board.
		int boardSize; //Size of the board, 9 for standard sudoku boards and this represents both dimenstions as the board is square.
};

#endif

template <typename T> //Templated so that these functions can take in any data type.
Puzzle<T>::Puzzle() { //Default constuctor to set up the private data members.
	boardSize = 9; //Standard sodoku board is 9x9.
	
	vector<T> tempVec; //temporary vector for creating the vector array.
	T temp; //Temporary variable to store what the file takes in.

	string fileName;
	cout << "Please enter a file name: "; //The name of the file is inputted by the user.
	cin >> fileName;

	ifstream inFile; //File stream pointer.
	inFile.open(fileName.c_str()); //Open the file, inFile points to the beginning.

	while(!inFile.eof()) { //Loop through data while there is still data in the file.
		for(int i = 0; i < boardSize; i++) { //This loop is used for a single line of the text file.	
			inFile >> temp; //Temporary variable takes the value that inFile is pointing to.
			tempVec.push_back(temp); //Allocate space for this value in the temporary vector.
		}
		puzzle.push_back(tempVec); //Using pushback, set the temporary vector as a element of the puzzle vector of vectors.
		original.push_back(tempVec);
		tempVec.clear(); //Clear the temporary vector for reuse.
	}
}		

template <typename T>
void Puzzle<T>::print() {
	for(int i = 0; i < boardSize; i++) { 
		for(int j = 0; j < boardSize; j++) { //Loop through each element of the board and print that along with a space.
			cout << puzzle[i][j] << " ";
			if(j % 3 == 2 && j != 8) { //For each third column, that is not the last column, Place a vertical wall.
				cout << "| ";
			}
		}
		cout << endl;
		if(i % 3 == 2 && i != 8) { //For each third row that is not the last row, place a horizontal row of dashes.
			cout << "---------------------" << endl; //These serve to break up the mini squares that make up the board.
		}
	}
}

template <typename T>
void Puzzle<T>::place() { //Place the value if it is a valid move.
	bool valid = 0; //Truth value for if the move is valid.
	int value, row, column;
	
	while(!valid) { //While the validity is not true, loop.
		cout << "Please input a number from to 1 to 9: ";
		cin >> value; //Take in the user's desired input.
		if(value < 1 || value > 9) { //Make sure the input is valid 1-9 number.
			cout << "Please enter a valid input." << endl;;
		}
		else {
			cout << "Please input the row you would like to place your number into: ";
			cin >> row; //Take in the user's desired row.
			cout << "Please input the column you would like to place your number into: ";
			cin >> column; //Take in the user's desired column.
			if(row < 1 || row > 9 || column < 1 || column > 9) { 
				//Check if the row and column are valid inputs.
				cout << "Please enter a valid input." << endl;
			}
			else if(original[row - 1][column - 1] != 0) { 
				//Make sure that the number inputted is not in the original board.
				cout << "That number was in the original board!" << endl;
			} 
			else if(check(value, row, column)) {
				//Make sure that this move is a valid one.
				cout << "This is not a valid move!" << endl;
			}
			else { //Exit the loop if none of these checks are tripped.
				valid = 1; 
			}
		}
	}	
	puzzle[row - 1][column - 1] = value; //Assign value to correct row and column
	print();
}

template <typename T>
bool Puzzle<T>::won() { //Check to see if the board has been won.
	//Loop through the board and see if any of the numbers are 0. This indicates a board has not been won.
	for(int i = 0; i < boardSize; i++) {
		for(int j = 0; j < boardSize; j++) {
			if(puzzle[i][j] == 0) {
				return 0; //Return false, that the board has not been won.
			}
		}
	}
	return 1;
}

template <typename T>
bool Puzzle<T>::check(int value, int row, int column) { //Check to see if a move is valid.
	int realRow = row - 1; //By convention, the vector rows and cols start at 0.
	int realCol = column - 1;
	for(int i = 0; i < boardSize; i++) { 
		//If the value matches any of the same column or row, this is an invalid move.
		if(value == puzzle[realRow][i] && i != realCol) { 
			return 1;
		}
		if(value == puzzle[i][realCol] && i != realRow) {
			return 1;
		}
	}
	int miniRow = realRow / 3; //Location of the mini grid for the given value.
	int miniCol = realCol / 3;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			//Check to see if the value equals any in this mini grid, and that the value is not the value being replaced, because we need to be able to edit values already placed that are   not original.
			if(value == puzzle[3 * miniRow + i][3 * miniCol + j] && (3 * miniRow + i) != realRow) {
				if((3 * miniCol + j) != realCol) {
					return 1;
				}
			}
		}
	}
	return 0; //Return 0 if no checks tripped.
}	

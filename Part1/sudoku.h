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
	private:
		vector<vector <T> > puzzle; //Vector array that will hold the board.
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

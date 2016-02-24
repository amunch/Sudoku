//main.cpp
//A small driver program to play sudoku.
//Lab 5
//By: Andy Munch

#include <iostream>
#include "sudoku.h" //Include the class implementation and interface.

int main() {
	Puzzle<int> puzz; //Create a puzzle that will take in a board of numbers.
	puzz.print(); //Print out this board to the screen.
	while(!puzz.won()) { //Play while the board has not been won.
		puzz.place();
	}	
	cout << "Congratulations, you have won!" << endl; //Display a winning message if the user wins.
	return 0;
}

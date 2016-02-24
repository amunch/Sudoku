//main.cpp
//A small driver program to play sudoku.
//Lab 5
//By: Andy Munch

#include <iostream>
#include "sudoku.h" //Include the class implementation and interface.

int main() {
	Puzzle<int> numPuzzle; //Create a puzzle that will take in a board of numbers.
	numPuzzle.print(); //Print out this board to the screen.
	Puzzle<char> charPuzzle; //Same as above, but with chars.
	charPuzzle.print(); 
}

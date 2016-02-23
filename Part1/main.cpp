//main.cpp
//A small driver program to play sudoku.
//Lab 5
//By: Andy Munch

#include <iostream>
#include "sudoku.h"

int main() {
	Puzzle<int> numPuzzle;
	numPuzzle.print();
	Puzzle<char> charPuzzle;
	charPuzzle.print(); 
}

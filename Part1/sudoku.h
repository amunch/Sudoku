//Sudoku.h
//Interface and implementation for a templated sudoku class
//Lab 5
//By: Andy Munch

#ifndef PUZZLE_H
#define PUZZLE_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
class Puzzle {
	public:
		Puzzle();
		void print();
	private:
		vector<vector <T> > puzzle;
		int boardSize;
};

#endif

template <typename T>
Puzzle<T>::Puzzle() {
	boardSize = 9;
	
	vector<T> tempVec;
	T temp;

	string fileName;
	cout << "Please enter a file name: ";
	cin >> fileName;

	ifstream inFile;
	inFile.open(fileName.c_str());

	while(!inFile.eof()) {
		for(int i = 0; i < boardSize; i++) {	
			inFile >> temp;
			tempVec.push_back(temp);
		}
		puzzle.push_back(tempVec);
		tempVec.clear();
	}
}		

template <typename T>
void Puzzle<T>::print() {
	for(int i = 0; i < boardSize; i++) {
		for(int j = 0; j < boardSize; j++) {
			cout << puzzle[i][j] << " ";
			if(j % 3 == 2 && j != 8) { 
				cout << "| ";
			}
		}
		cout << endl;
		if(i % 3 == 2 && i != 8) {
			cout << "---------------------" << endl;
		}
	}
}

#pragma once
#include<iostream>
#include<string>
#include"SolverFunctions.h"

int board[9][9];
int get_Board() {
	//This function asks the user to input the board, and stores the values in a matrix
	int i, j;
	cout << "Enter the board sequentially: " << endl;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> board[i][j];
			cout << " ";
		}
	}
	return 0;
}
bool valid(int board[9][9], int row, int column, int num) {
	//This function uses for loops to check if the current number being checked can be valid
	int i, j;
	for (i = 0; i < 9; i++) {
		//This loop checks all elements in a row to see if the number appears there
		if (board[row][i] == num) {
			return false;
		}
	}
	for (j = 0; j < 9; j++) {
		//This loop checks all elements in a column to see if the current number is repeated
		if (board[j][column] == num) {
			return false;
		}
	}
	//The following variables are used as starting positions fo rthe loops which check the sub-grids for the current number
	int startRow = row - row % 3;
	int startCol = column - column % 3;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i + startRow][j + startCol] == num) {
				return false;
			}
		}
	}
	return true;
	// If all statements are true, this function also returns true
}
bool solve(int board[9][9], int row, int column) {
	if (row == 9 - 1 && column == 9) {
		//This checks to see if the program is on the final box of the grid
		return true;
	}
	if (column == 9) {
		//This moves the program to the next line on the array once it reaches the end
		row++;
		column = 0;
	}
	if (board[row][column] > 0) {
		//This recurring function is used to move on to the next box once one is solved for
		return solve(board, row, column + 1);
	}
	for (int num = 1; num <= 9; num++) {
		//This is the actual function that solves by first calling the valid function to check if the number is valid for that box
		//It then recurringly solves the next box, and if that returns true, then the board is solved
		//If it returns false, then the box resets to 0 and trys again with the next number in the loop
		if (valid(board, row, column, num)) {
			board[row][column] = num;
			if (solve(board, row, column + 1)) {
				return true;
			}
			else {
				board[row][column] = 0;
			}
		}
	}
	return false;
}
void print_board() {
	int i, j;
	//This function prints out the sudoku board in a more readable manner
	for (i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
		if (i % 3 == 0) {
			cout << "-------------------------" << endl;
		}
		for (j = 0; j < sizeof(board) / sizeof(board[0]); j++) {
			if (j == 8) {
				cout << board[i][j] << " |";
			}
			else if (j % 3 == 0) {
				cout << "| ";
				cout << board[i][j] << " ";
			}
			else
			{
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "-------------------------";
}

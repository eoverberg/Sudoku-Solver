#include<iostream>
#include<string>
#include"SolverFunctions.h"
using namespace std;

int main() {
	//The main function calls the other functions, and if they all return true, it prints the board
	//Else, it prints no solution
	get_Board();
	print_board();
	cout << endl;
	if (solve(board, 0, 0)) {
		print_board();
	}
	else {
		cout << "No solution" << endl;
	}
	return 0;
}

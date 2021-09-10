#include<iostream>
#include<string>

int board[9][9];

int get_Board();

bool valid(int board[9][9], int row, int column, int num);

bool solve(int board[9][9], int row, int column);

void print_board();

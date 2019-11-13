
/*
AUTHOR: Marlon Louis

DESCRIPTION: Place 8 1's on an 8x8 grid meeting certain criteria without any being in the same
			 row, column, or diagonal.
*/



#include <iostream>
using namespace std;

int main()
{
	//initializing the board
	int b[8][8] = {0};
	int r, c = 0, solution = 0, tempX, tempY;

	//place a queen in the top left corner
	b[0][0] = 1;
	
	//will move to the next column
nextCol:
	
	r = -1;
	c++;
	if (c == 8) goto print;

nextRow:
	r++;
	if (r == 8) goto backTrack;

	//check if there is a queen in this row
	for (int i = c; i >= 0; i--) {
			if (b[r][i] == 1) goto nextRow;
	}

	//check if there is a queen in the upper left diagonal
	tempX = c-1;
	tempY = r - 1;
	while (tempX >= 0 && tempY >= 0) {
		if (b[tempY][tempX] == 1) goto nextRow;
		tempX--;
		tempY--;
	}


	//check if there is a queen in the lower left diag
	tempX = c - 1;
	tempY = r + 1;
	while (tempX >= 0 && tempY <= 7) {
		if (b[tempY][tempX] == 1) goto nextRow;
		tempX--;
		tempY++;
	}

	//placing a queen after checking
	b[r][c] = 1;
	goto nextCol;



backTrack:

	//going to the previous column to find the previous queen
	c--;

	//This means we printed all solutions
	if (c < 0) {
		cout << "\nALL SOLUTIONS PRINTED\n";
		return 0;
	}

	//searching for the queen
	r = 7;
	while (1) {
		if (b[r][c] == 1) break;
		r--;
	}
	
	//removing the previous queen to find a new spot in that column
	b[r][c] = 0;
	goto nextRow;


print:

	solution++;
	cout << "\nSolution: " << solution << "\n";

	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8; j++) {
			cout << b[i][j];
		}
		cout << "\n";
		
		
	}
	
	goto backTrack;


}



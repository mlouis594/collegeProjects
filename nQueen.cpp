#include <iostream>
using namespace std;

//N Queens: 
//creating an n*n board and counting the number of existing solutions

//prototyping functions
bool okFunc(int*, int);
int nQueen(int);


int main(){


for(int i = 1;i < 13; i++ ) cout << "There are " << nQueen(i) << " solutions to " << i << " Queen problem" << endl;

}




bool okFunc(int *arr, int col){

	for(int i = 0; i < col; i++){
			
		if((*(arr+i)) == (*(arr+col)) || abs((*(arr+i)) - (*(arr+col))) == (col - i)) return false;

	}
	return true;

}



int nQueen(int x){

	int *a = new int[x]{0};
	int col = 0, sol = 0;
	

	while (col >= 0) {  // NEXT COL:
		col++;                // Move to the next column
		if (col >= x) {          // If you have passed the last column, a solution is found
			sol++;      // Call the print function and backtrack
			col--;
		}
		else (*(a+col)) = -1;   // set to -1 so in inner loop you can start q[c] from 0
		while (col >= 0) {  // NEXT ROW:
			(*(a+col))++;           // Move to the next row

			if ((*(a+col)) >= x) {
				(*(a+col)) = -1; col--; 
			}else             

				if (okFunc(a, col)) break; // If ok (returns true), a queen is filled in the row
		}
	}

delete[] a;
	return sol;


}//end of nQueen func



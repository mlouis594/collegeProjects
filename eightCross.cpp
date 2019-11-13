#include <iostream>
#include <cmath>
using namespace std;

//prototyping functions
bool ok(int[], int);
bool bacTrac(int*, int&);
void print(int[]);
bool moveFunc(int*, int&);
int bro();

//main function
int main(){

	int b[8], x = 0;
	//moveFunc(b, x);
	bro();

}


bool bacTrac(int *a, int &c){

	//reset current
	*(a+c) = 0;

	//back up
	c--;

	//no solutions
	if(c < 0) return false;

	//inc prev
	(*(a+c))++;

	//check bounds
	if((*(a+c)) >7) return bacTrac(a, c);

	//passed all checks
	return true;




}


//this function expects to be passed an array of sz 8
//the call will initiate from the main func then the func will run auto
//when there are no more solutions the func will stop
//the sol purpose of this function is to move the col
bool moveFunc(int *a, int &c){

	//increment 
	c++;

	//check bounds
	if(c > 7){

		//solution found
		print(a);

		//if bacTrac fails there are no more solutions
		if(!bacTrac(a, c)) return false;
	}

	while(!ok(a, c)){

		//trying until successful number is found
		(*(a+c))++;

		//check bounds
		if((*(a+c)) >=8) {
		       if(!bacTrac(a, c)){
				return false;
		       }
		}


		
	}
	
	return moveFunc(a, c);

}




int bro() {
	
	// initialize…
	int b[8], c = 0;
	bool flg = false, t = true;

		while (c >= 0) { // BOX PART:
		   //backtracking when needed
			if (flg) {
				c--;
				flg = false;
			}
			else {
				c++;
				//calling the print function when a solution has been found
				//will backtrack next
				if (c == 8) print(b);
				b[c] = 0;
				if (t) {
					c--;
					t = false;
				}
			}

			
		   // Otherwise, reset number to 0, so you will start from number 1 in the inner loop
			while (c >= 0) { // NUMBER PART:
			   // Move to the next number
			   // If you tried all number answers, backtrack
			   // Otherwise, call the ok function.
			   // If it returns true, go back to the box part.
			   // otherwise continue this loop to next number
				++b[c];
				if (b[c] == 9) {
					flg = true;
					break;
				}

				//breaking from the loop if a valid pos is found
				if (ok(b, c)) break;

			}
		}

	return 0;

}


//ok function
bool ok(int b[], int c) {

	//cout << "ok func";
	
	//this array will store the neighbors of each index
	static int index[8][5] = {
	{-1},                 // 0
	{0, -1},              // 1
	{0, 1, -1},           // 2
	{0, 2, -1},           // 3     
	{1, 2, -1},           // 4
	{1, 2, 3, 4, -1},     // 5
	{2, 3, 5, -1},        // 6
	{4, 5, 6, -1}         // 7
	};

	//checking the cross for duplicates
	for (int i = 0; i < c; i++) {
		if (b[c] == b[i]) return false;
	}

	//this check will seach the neighbors
	for (int i = 0; index[c][i] != -1; i++) { 
		if (abs(b[index[c][i]] - b[c]) == 1) return false;
	}

	return true;
}



//print function
void print(int b[]) {

	cout << "print func";

	//will keep track of the solutions
	static int solution = 1; 

	cout << "Solution #" << solution++ << ":" << endl;
	cout << " " << " " << b[1] << b[2] << endl;
	cout << " " << b[0] << b[3] << b[4] << b[5] << endl;
	cout << " " << " " << b[6] << b[7] << endl;

	cout << "----------------" << endl;
}

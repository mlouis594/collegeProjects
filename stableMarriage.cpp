
/*
AUTHOR: Marlon Louis

DESCRIPTION: Will find stable matches for individuals based on their preference
*/



#include <iostream>
using namespace std;

bool okFunc(int b[], int c) {
	// c and b[c] are the current man and woman to be matched
	// i and b[i] are the man and woman already married

	// the smaller number means more preferable.
	// mp[man][woman] = the score that man given to that woman
	static int mp[3][3] = { { 0,2,1 },   // Man#0's preferences
						{ 0,2,1 },   // Man#1's preferences
						{ 1,2,0 } };  // Man#2's preferences

	// wp[woman][man] = the score that woman given to that man
	static int wp[3][3] = { { 2,1,0 },   // Woman#0's preferences
						{ 0,1,2 },   // Woman#1's preferences
						{ 2,0,1 } };  // Woman#2's preferences
	for (int i = 0; i < c; i++) {
		// Test #1: Similar to row test in 8 queens
			// Check if the current woman has already been married to other men.
		if (b[i] == b[c]) return false;

		// Test #2:
			// Part A: Current man and other women
			// Check if the current man (c) likes any other woman (q[i]) more than current woman (q[c]).
		if (mp[i][b[c]] < mp[i][b[i]] && wp[b[c]][i] < wp[b[c]][c]) return false; //unstable couple

		// Part B: Current woman and other men
		// Check if other men (i) like the current woman (q[c]) more than their own wifes (q[i]).
		if (mp[c][b[i]] < mp[c][b[c]] && wp[b[i]][c] < wp[b[i]][i]) return false;
	}//end of for loop
	return true;
}//end of func

//print function
void print(int b[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i = 0; i < 3; ++i)
		cout << i << "\t" << b[i] << "\n";
	cout << "\n";
}



int main() {

	//declaring vars
	int b[3];
	int c = 0;
	b[0] = 0;

	//main loop
	while (c >= 0) {

		//printing if a solution is found
		if (c == 2) {
			print(b);
			c--;
		}

		//otherwise continuing to the inner loop
		else
			b[++c] = -1;

		//finding the right match for the selected person
		while (c >= 0) {
			b[c]++;

			//backtracking if no match is found
			if (b[c] == 3)
				c--;

			//doing a function check if a potential match is found
			else if (okFunc(b, c))
				//exiting the loop if a match is found
				break;
		}
	}
	return 0;

}








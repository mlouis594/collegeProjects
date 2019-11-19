#include <iostream>
#include <cstring>
using namespace std;

//function prototypes
int rectangle(int);
int triangle(int);
int secondDigit(int);
int exp(int, int);
void print(char*);
void printRev(char*);
string printBinary(int n);

int main(){

	//preparations for the rectangle function
	int x = 0; 
	//cout << "How many rows for the rectangle: "; cin >> x;
	rectangle(x);

	//preparations for the triangle function
	int y = 0;
	//cout << "\nHow many triangle rows? "; cin >> y;
	cout << "There are " << triangle(y) << " total dots" << endl;

	//preparations for secondDigit
	int z = 0;
	//cout << "Submit your number for testing: "; cin >> z;
	cout << "\n the second digit is " << secondDigit(z) << endl;

	//preparations for the expFunc
	int a = 0, b = 0; 
	//cout << "Which number and to what power? "; cin >> a >> b;
        cout << a << " raised to the " << b << " power is: " << exp(a, b) << endl;

	//preparations for the print function
	char c[6] = "hello";
	print(c);
	cout << endl;

	//preparations for the printRev function
	printRev(c);
	cout << endl;	
}

int rectangle(int n){

	if(n <= 0) return 0;
	cout << "**********" << endl;

	return rectangle(n-1);
}


int triangle(int n){

	if(n == 0) return 0;
	return n + triangle(n-1);

}


int secondDigit(int n){
	
	if(n < 100) return n%10;
	return secondDigit(n/10);
}

//complete this on paper before attempting
string printBinary(){return "s";}


int exp(int x, int n){

	if(n == 0) return 1;
	if(n == 1) return x;

	return x * exp(x, n-1);

}


//this section will be devoted to the 6a problem
void print(char *s){

	char *temp = s;
	if(*(temp) == '\0') return;
	cout << *temp;
	print(temp+1);
}


void printRev(char *c){

	for(int i = strlen(c)-1; i >= 0; i--) cout << c[i];
	return;
	

}

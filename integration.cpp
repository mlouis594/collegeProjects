//STUDENT: Marlon Louis
#include <iostream>
using namespace std;

typedef double FUNC(double);

// Seturns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles 
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)








double integrate(FUNC f, double a, double b) {
	// Fill in.
	// loop x from a to b, each x represents width of rectangle (0.0001)
	// area += height * width, 
	// width = 0.0001, height = f(x + 0.0001/2) (the mid-point is more accurate)
	// return area;
	double res = 0;
	for (double x = a; x < b;x+=0.0001) {
		res += .0001 * f(x + .0001/2);
	}
	return res;
}

double line(double x) {

double square(double x) {
	return x * x;
}
	return x * x * x;
}

int main() {
	cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;   // output: 12
	cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // output: 41.3333
	cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // output: 156
	return 0;
}






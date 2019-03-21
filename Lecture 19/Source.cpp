// Lecture 18 supplementary program

#include<iostream>
#include<string>
#include<cstdlib> // loads in the c standard library which includes the rand function.
#include<time.h> // loads in the time command for use with the srand function.

using namespace std;

int sum(int, int);
void swap(int, int);
void swapRef(int &x, int &y);
void counterTypes(int &counter1, int &counter2, int &counter3);

int main() {
	// Normal functions operate by having arguments passed to them through their parameters
	// These arguments can be any variable type or nothing at all
	// This is called 'pass by value' You are passing the values as input but not references to variables that can change local variables.
	cout << sum(4, 2) << endl; // we are passing by value the integers 4 & 2 to the function as defined by the function parameters and receiving their sum

	int x = 5;
	int y = 10;

	cout << "Before swap. x = " << x << " y = " << y << endl;
	swap(x, y); // Passing by value two integers and receiving no return as it is a void function. 
	cout << "Values in the main loop are unchanged. x = " << x << " y = " << y << endl;

	// Passing by reference uses the entire variable as input to the function, changing the value of it in the main loop
	// The function is declared using '&' before each parameter in it's definition and called the same way as a normal function.
	// When a function is defined by reference, we can only pass variables to them and normal integers etc without an associated variable with throw and error.
	cout << "Before swap. x = " << x << " y = " << y << endl;
	swapRef(x, y); // Passing by value two integers and receiving no return as it is a void function. 
	cout << "Values in the main loop are changed. x = " << x << " y = " << y << endl; // The variables x, y have been changed by the void function because of the reference call of the function.

	// Passing by reference can be used to retrieve multiple returns from a function.
	int a(0), b(0), c(0);
	counterTypes(a, b, c);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	// The Random function:

	// The rand function is used to create a series of psuedo random numbers for various purposes wherever we may need them.
	srand(0); // initializes the seed of the random function. If we use a fixed integer the same string of random numbers will always be the same.
	//srand(time(NULL)); // initializing with the time(NULL) seed, picks a seed based on the current time making it change every time the program is run.
	cout << rand() << endl;
	for (int i = 0; i < 10; ++i) {
		cout << rand() % 100 + 25 << endl; // for generating in a specific range, use modulus to cap the upper bound of your desired numbers and adding a number == to your lower range
	}
	cout << rand() % 51 - 25 << endl; // outputs a random number from -25 to 50

	system("pause");
	return 0;
}

int sum(int a, int b) {
	return a + b;
}

void swap(int x, int y) {
	int temp;
	cout << "Before swap. x = " << x << " y = " << y << endl;
	temp = x;
	x = y;
	y = temp;
	cout << "After swap. x = " << x << " y = " << y << endl;
}

// Pass by reference
// Adding & before the parameters makes them pass by reference rather than value.
void swapRef(int &x, int &y) {
	int temp;
	cout << "Before swap. x = " << x << " y = " << y << endl;
	temp = x;
	x = y;
	y = temp;
	cout << "After swap. x = " << x << " y = " << y << endl;
}

void counterTypes(int &counter1, int &counter2, int &counter3) {
	counter1 = counter1 + 10;
	counter2 = counter2 + 100;
	counter3 = counter3 + 1000;


}
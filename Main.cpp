#include <iostream>
#include <math.h>   
#include "ModArithmetics.h"

using namespace std;


int main() {
	int elmnts = 0;
	int operation;

	cout << "Enter the number of elements of the remainder ring" << endl;
	cin >> elmnts;

	int *arr = new int[elmnts];

	FillArray(arr, elmnts);
	cout << "Choose function :" << endl << "1 - addition " << endl << "2 - subtraction " << endl <<
		"3 - multiplication " << endl << "4 - couples with remainder '1'" << endl <<
		"5 - reciprocal of all elements " << endl <<
		"6 - reciprocal of a specific element " << endl << "7 - division " << endl <<
		"8 - exponentiation method 1" << endl <<
		"9 - exponentiation method 2" << endl <<
		"10 - check if remainder ring is a remainder field" << endl <<
		"11 - check if number is a primitive root" << endl <<
		"12 - check which numbers from remainder field are primitive roots" << endl <<
		"13 - find the discrete logarithm of a number from the remainder field" << endl;

		cin >> operation;


		if (operation == 1) {
			AddElements(elmnts);
		}

		else if (operation == 2) {
			SubtractElements(elmnts);
		}

		else if (operation == 3) {
			MultiplyElements(elmnts);
		}

		int counter = 0;
		counter = PairableElements(elmnts, arr);
		int x = 2;
		int **array = new int*[x];
		for (int i = 0; i <= x - 1; i++) {
			array[i] = new int[counter];
		}
		InsertParElements(elmnts, array, arr);


		if (operation == 4) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j <= counter; j++) {
					cout << array[i][j] << " ";
				}
				cout << endl;
			}
		}


		if (operation == 5) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j <= counter; j++) {
					cout << array[i][j] << " ";
				}
				cout << endl;
			}
			ReciprocalArray(array, counter);
		}


		if (operation == 6) {
			int UInput;
			cout << "Enter an element from the remainder ring: " << endl;
			cin >> UInput;
			ReciprocalElement(elmnts, UInput);
		}

		if (operation == 7) {
			DivisionElements(elmnts, array);
		}

		if (operation == 8) {
			PowerElements1(elmnts);
		}
		if (operation == 9) {
			PowerElements2(elmnts);
		}

		if (operation == 10) {
			RemainderField(elmnts);
		}
		delete[] arr;

		if (operation == 11) {
			if (RemainderField(elmnts) == 1) {
				PrimitiveRoot(elmnts);
			}
		}

		if (operation == 12) {
			if (RemainderField(elmnts) == 1) {
				AllPrimitiveRoots(elmnts);
			}
		}

		if (operation == 13) {
			if (RemainderField(elmnts) == 1) {
				DiscreteLog(elmnts);
			}
		}
	system("PAUSE");
	return 0;
}
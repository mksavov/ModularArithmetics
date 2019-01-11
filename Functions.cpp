#include <iostream>
#include "ModArithmetics.h"

using namespace std;

int FillArray(int *arr, int a) {
	for (int i = 0; i < a; i++)
	{
		arr[i] = i;

		cout << arr[i] << "\t";
	}
	cout << endl;
	return 0;
}

void AddElements(int a) {
	int el1, el2;
	cout << "Enter two elements from the remainder ring: " << endl;
	cin >> el1;
	cin >> el2;
	cout << (el1 + el2) % a << endl;
}

void SubtractElements(int a) {
	int dif = 0;
	int el1, el2;
	cout << "Enter two elements from the remainder ring: " << endl;
	cin >> el1;
	cin >> el2;
	dif = (el1 - el2) % a;
	if (dif < 0) {
		dif += a;
	}
	cout << dif << endl;
}

void MultiplyElements(int a) {
	int el1, el2;
	cout << "Enter two elements from the remainder ring: " << endl;
	cin >> el1;
	cin >> el2;
	cout << (el1 * el2) % a << endl;
}

int PairableElements(int c, int *arr) {
	int x = 2;
	int i;
	int j;
	int counter = 0;

	for (i = 1; i < c; i++) {
		for (j = 2; j < c; j++) {
			if ((arr[i] * arr[j]) % c == 1) {
				counter++;
			}
		}
	}
	return counter;
}

void InsertParElements(int c, int **array, int *arr) {
	int counter = 0;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if ((arr[i] * arr[j]) % c == 1) {
				array[0][counter] = arr[i];
				array[1][counter] = arr[j];
				counter++;
			}
		}
	}
}

void ReciprocalArray(int **array, int a) {
	for (int j = 0; j <= a; j++) {
		cout << "The reciprocal value of " << array[1][j] << " is: " << endl;
		cout << "1/" << array[0][j] << endl;
	}
}

void ReciprocalElement(int c, int a) {
	int counter = 0;
	for (int i = 2; i < c; ++i)
	{
		if (c % i == 0)
		{
			counter++;
		}
	}
	if (counter > 1) {

		cout << "The remainder ring is not prime" << endl;
	}
	else {

		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				if ((a*i) - (c*j) == 1) {
					cout << "The reciprocal element is: " << i << endl;
				}
			}
		}
	}
}

void DivisionElements(int a, int **array) {
	int UInput;
	int UInput2;
	int k = 0;
	int f = 0;
	cout << "Enter first number from the remainder ring: " << endl;
	cin >> UInput;

	cout << "Enter second number from the remainder ring: " << endl;
	cin >> UInput2;


	for (int i = 0; i < a; i++) {
		if (UInput2 == array[0][i]) {
			k = (UInput * array[1][i]) % a;
			f = 1;
		}
	}
	if (f == 1) {
		cout << UInput << " / " << UInput2 << " % " << a << " = " << k << endl;
	}
	else {
		cout << UInput << " / " << UInput2 << " % " << a << " = " << " -1 " << endl;
	}
}

void PowerElements1(int a) {
	int base;
	int pownum;
	int k;
	int newmod;

	cout << "Enter a base number from the ramainder ring: " << endl;
	cin >> base;
	cout << "Enter the power to that base: " << endl;
	cin >> pownum;

	for (int i = 1; i < pownum; i++) {
		k = (int)pow(base, i);
		k = k % a;

		if (k == 1) {
			cout << base << " to the power of " << pownum;

			newmod = i;
			pownum = pownum % newmod;
			k = (int)pow(base, pownum);
			k = k % a;

			cout << " mod " << a << " = " << k << endl;

			break;
		}
	}
}


void PowerElements2(int a) {
	int base = 0;
	int pownum;
	int counter = 0;
	int i = 0;
	int temp;
	long long unsigned int k = 1;

	cout << "Enter a base number from the ramainder ring: " << endl;
	cin >> base;
	cout << "Enter the power to that base lower than 32: " << endl;
	cin >> pownum;

	temp = pownum;
	int binaryNum[1000];


	while (temp > 0) {


		binaryNum[i] = temp % 2;
		temp = temp / 2;
		i++;
	}


	int z = 0;
	int q = 0;

	for (int w = 0; w < i; w++) {
		if (binaryNum[w] == 1) {
			q++;
		}

	}
	int *numbers = new int[q];

	for (int j = 0; j < i; j++) {
		if (binaryNum[j] == 1) {
			numbers[z] = (int)pow(2, j);
			z++;
		}
	}

	for (int s = 0; s < z; s++) {
		k = k * (int)pow(base, numbers[s]) % a;
	}
	cout << base << " to the power of " << pownum << " mod " << a << " = " << k % a << endl;
}

int RemainderField(int a) {
	int i;
	int isPrime = 1;
	for (i = 2; i <= a / 2; ++i)
	{
		if (a % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	if (isPrime)
		cout << "The remainder ring is a remainder field" << endl;
	else
		cout << "The remainder ring is NOT a remainder field" << endl;

	return isPrime;
}

void PrimitiveRoot(int a) {
	int UInput;
	int counter = 0;
	int *pelements = new int[a - 1];
	int f = 0;

	cout << "Enter a number from the remainder field: " << endl;
	cin >> UInput;


	for (int i = 1; i < a; i++) {
		pelements[counter] = (int)pow(UInput, i) % a;
		counter++;

	}

	for (int z = 0; z < a - 1; z++) {
		for (int x = 1; x < z; x++) {
			if (pelements[z] == pelements[x]) {
				f = 1;
			}
		}
	}

	if (f == 1) {
		cout << "The number " << UInput << " is NOT a primtive root" << endl;
	}
	else if (f == 0) {
		cout << "The number " << UInput << " is a primitive root" << endl;
	}

}

void AllPrimitiveRoots(int a) {
	for (int w = 1; w < a; w++) {
		int counter = 0;
		int *pelements = new int[a - 1];
		int f = 0;

		for (int i = 1; i < a; i++) {
			pelements[counter] = (int)pow(w, i) % a;
			counter++;
		}
		for (int z = 0; z < a - 1; z++) {
			for (int x = 1; x < z; x++) {
				if (pelements[z] == pelements[x]) {
					f = 1;
				}
			}
		}
		if (f == 1) {
			cout << "The number " << w << " is NOT a primitive root" << endl;
		}
		else if (f == 0) {
			cout << "The number " << w << " is a primitive root" << endl;
		}
		delete[] pelements;
	}
}

void DiscreteLog(int a) {
	int base;
	int arg;
	int f = 0;

	cout << "Enter a base number from the remainder field: " << endl;
	cin >> base;

	cout << "Enter a number from the remainder field: " << endl;
	cin >> arg;

	for (int i = 0; i < a; i++) {
		if (((int)pow(base, i) % a) == arg) {
			f = 1;
			cout << "dlog " << base << " " << arg << " = " << i << endl;
			break;
		}
	}
	if (f == 0) {
		cout << "dlog " << base << " " << arg << " = " << " -1 " << endl;
	}
}
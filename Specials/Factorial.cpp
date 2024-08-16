#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	cout << "Plz enter a number : ";
	cin >> n;
	if (n == 0 || n == 1)
		cout << "\t 1";
	else {
		int fact=1;
		while (n > 1) {
			fact = fact * n;
			n--;
		}

		cout << "\t" << fact;
	}

	_getch();
	return 0;
	
}
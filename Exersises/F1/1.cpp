#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i;
	cout << "Plz enter a number: ";
	cin >> n;
	for (i = 2;i < n;i = i + 2) {
		cout << i;
		cout << " ";
	}
	_getch();
	return 0;
}
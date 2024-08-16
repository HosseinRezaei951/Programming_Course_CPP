#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	cout << "Plz enter a number : ";
	cin >> n;
	int fact = 1, sum = 0;
	for (int i = 1;i <= n;i++) {
		fact = fact *i;
		sum = sum + fact;
	}
	cout << "ans is = " << sum;

	_getch();
	return 0;

}
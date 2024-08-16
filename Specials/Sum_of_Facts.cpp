#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	cout << "Plz enter a number : ";
	cin >> n;
	int fact = 1, sum = 0;
	for (int i = 1;i <= n;i++) {
		fact = 1;
		for (int j = 1;j <= i;j++) 
			fact = fact *j;
		sum = sum + fact;
	}
	cout << "ans is = " << sum;

	_getch();
	return 0;
	
}
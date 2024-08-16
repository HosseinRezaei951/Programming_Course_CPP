#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i = 2;
	cout << "Plz enter anumber: ";
	cin >> n;
	while (n > 1)
		if (n%i == 0) {
			n = n / i;
			cout << " " << i;
		}
		else
			i++;

	_getch();
	return 0;	
}
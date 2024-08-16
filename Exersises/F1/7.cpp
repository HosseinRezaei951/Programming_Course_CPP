#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i = 0, s = 0,r;
	cout << "Plz enter anumber: ";
	cin >> n;
	while (n != 0) {
		r = n % 2;
		n = n / 2;
		s = r*(pow(10,i)) + s;
		i++;
	}
	cout << "\t"<< s;
	_getch();
	return 0;
}
#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i,s=0;
	cout << "Plz enter anumber: ";
	cin >> n;
	for (i = 1;i < n;i++)
		if (n%i == 0)
			s = s + i;
	if (s == n)
		cout << n << " is a complete number";
	else 
		cout << n << " is not a complete number";
	_getch();
	return 0;
}
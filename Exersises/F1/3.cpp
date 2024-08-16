#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i, count = 0, fact = 1, s = 0;
	cout << "Plz enter anumber: ";
	cin >> n;
	for (i = 1;i <= n;i++) {
		fact = fact*i;
		count++;
		cout << " ";
		if (count % 2 == 0)
			s = s - fact;
		else
			s = s + fact;
	}
	cout <<"\t answer is "<< s;
	_getch();
	return 0;
}
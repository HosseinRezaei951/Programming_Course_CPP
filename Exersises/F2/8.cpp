#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int primes[100000];
	int i = 0,j=0,n ,counter = 0,flag=0;
	cout << "Plz,enter a number: ";
	cin >> n;
	primes[counter++] = 2;
	for (i = 3;i < n;i++) {

		flag = 0;
		for (j = 0;j < counter;j++)

			if (i%primes[j] == 0) {
				flag = 1;
				break;
			}
		if (flag == 0)
			primes[counter++] = i;
	}
	cout << "\n";
	for (i = 0;i < counter;i++)
		cout << "\t" << primes[i];

	_getch();
	return 0;
}
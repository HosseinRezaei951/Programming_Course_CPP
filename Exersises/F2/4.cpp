#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int a[100], b[100];
	int i = 0, j = 0, n = 0,flag =0;
	cout << "Plz enter a number of elments: ";
	cin >> n;
	while ((n < 1 || n>100) || (n%2!=0)) {
		cout << "Incorrect,Plz enter a number of elments: ";
		cin >> n;
	}
	while (i < n) {
		cout << "enter a number" << (i + 1) << " : ";
		cin >> a[i];
		i++;
	}

	for (i = 0;a[i] >= 0;i++)
		cout << a[i] << "\t";
	i = 0;
	while (i <= n && flag < 2) {

		while (i < ((n / 2) ) && flag == 0)
			b[j++] = a[i++];

		b[j++] = 7;
		flag = 1;
		while (i <= n && flag == 1) 
			b[j++] = a[i++];
		flag = 2;
				
	}
	cout << " =====> \t";
	for (i = 0;b[i] >= 0;i++)
		cout << b[i] << "\t";

	_getch();
	return 0;

}
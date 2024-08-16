#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int a[100];
	int i = 0, j = 0, n = 0, flag = 0;
	cout << "Plz enter a number of elments: ";
	cin >> n;
	while (n < 1 || n>100) {
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

	for (i = 0;i < (n-1);i++)
		if (a[i] > a[i + 1]) {
			flag ++;
			break;
		}
	
	for (i = 0;i < (n - 1);i++)
		if (a[i] < a[i + 1]) {
			flag ++;
			break;
		}
	if (flag >= 2)
		cout << " =====> \t" << "Not sorted";
	else 
		cout << " =====> \t" << "is sorted";
	_getch();
	return 0;
}
#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int a[100],b[100];
	int i = 0, j = 0, n = 0, flag = 0,m=0;

	//List A:
	cout << "Plz enter a number of elments(A): ";
	cin >> n;
	while (n < 1 || n>100) {
		cout << "Incorrect,Plz enter a number of elments(A): ";
		cin >> n;
	}
	while (i < n) {
		cout << "\t(A): enter a number" << (i + 1) << " : ";
		cin >> a[i];
		i++;
	}

	//List B:
	cout << "Plz enter a number of elments(B): ";
	cin >> m;
	while (m!=n) {
		cout << "Incorrect,Plz enter a number of elments(B): ";
		cin >> m;
	}
	while (j < m) {
		cout << "\t(B): enter a number" << (j + 1) << " : ";
		cin >> b[j];
		j++;
	}

	//print List A:
	cout << "(A):\t";
	for (i = 0;i<n;i++)
		cout << a[i] << "\t";

	cout <<"\n";

	//print List B:
	cout << "(B):\t";
	for (j = 0;j<m;j++)
		cout << b[j] << "\t";

	for (i = 0;i <=n;i++)
		if (a[i] != b[i]) {
			flag=1;
			break;
		}

	cout << "\n";
	if (flag ==1 )
		cout << " \t" << "Not mached";
	else
		cout << " \t" << "mached";
	_getch();
	return 0;
}
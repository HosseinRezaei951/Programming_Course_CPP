#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	int n, m, k;
	int a[100], b[100], c[100];
	cout << "please enter n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "please enter a[" << i << "]: ";
		cin >> a[i];
	}

	cout << "please enter m: ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		cout << "please enter a[" << i << "]: ";
		cin >> b[i];
	}

	k = 0;
	int counter1 = 0, counter2 = 0;
	while (counter1 < n && counter2 < m)
		if (a[counter1] <= b[counter2])
			c[k++] = a[counter1++];
		else
			c[k++] = b[counter2++];

	for (int i = counter1; i < n; i++)
		c[k++] = a[i];

	for (int i = counter2; i < m; i++)
		c[k++] = b[i];

	cout << endl;
	for (int i = 0; i < k; i++)
		cout << c[i] << "\t";

	_getch();
	return 0;
}
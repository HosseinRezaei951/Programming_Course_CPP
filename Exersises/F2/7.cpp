#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int a[100],b[100];
	int i=0 , j = 1, n = 0, flag = 0, m = 0;

	//List A:
	cout << "Plz enter a number of elments(A): ";
	cin >> n;
	while (n < 1 || n>100) {
		cout << "Incorrect,Plz enter a number of elments(A): ";
		cin >> n;
	}
	while (j < n+1) {
		cout << "\t(A): enter a number" << j  << " : ";
		cin >> a[j-1];
		
		while (a[j - 1]<-50 || a[j - 1]>50){
			cout << "\tIncorrect,Plzenter a number" << j << " again : ";
			cin >> a[j-1];
		}
		j++;
	}
	for (i = 0;i < 100;i++)
		b[i] = 0;
	for (i = 0;i < n;i++){
		m = (a[i] + 50);
		b[m] ++;
	}

	//print List A:
	cout << "(A):\t";
	for (i = 0;i<n;i++)
		cout << a[i] << "\t";

	cout << "\n";
	cout << "\n =====>";
	//print resoult
	for (i = 0;i < 100;i++)
		if (b[i] >= 2)
			cout <<"\t"<< i -50;

	_getch();
	return 0;
}
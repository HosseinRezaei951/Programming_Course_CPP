#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int n,counter=0;
	int a[100];
	int i = 0,j, flag = 0;
	cout << "Plz enter a number : ";
	cin >> n;

	for (i = 2;i < n;i++) {
		flag = 0;
		for (j = 2;j <= (i / 2);j++) 
			if (i%j == 0) {
				flag = 1;
				break;
			}
		if (flag == 0)
			a[counter++] = i;
		
	}

	for (int i = 0;i < counter;i++)
		cout << "\t" << a[i];

		
	_getch();
	return 0;

}
#include<iostream>
#include<conio.h>
using namespace std;

int i, n,j,flag=0;
int main() {
	cout << "Plz enter a number: ";
	cin >> n;
	i = n - 1;
	while (i > 1) {
		
		if (n%i == 0) {
			flag = 0;
			for (j = 2;j <= i/2;j++) 
				if (i%j == 0) {
					flag = 1;
					break;
				}
			if (flag == 0) 
				cout << " " << i;	
		}
		
		i--;
	}
	_getch();
	return 0;
}
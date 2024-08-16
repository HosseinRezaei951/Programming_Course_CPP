#include<iostream>
#include<conio.h>
using namespace std;

int i, n, j, flag = 0;
int main() {
	cout << "Plz enter a number: ";
	cin >> n;
	i = n - 1;
	while (i > 1) {
			flag = 0;
			for (j = 2;j <= i / 2;j++)
				if (i%j == 0) {
					flag = 1;
					break;
				}
			while (flag == 0 && n%i == 0){
				cout << " " << i;
				n = n / i;
				}
			i--;
	}
	_getch();
	return 0;
}
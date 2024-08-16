#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i, j, flag,cont=0;
	cout << "Plz enter a number: ";
	cin >> n;
	cout << "\t";
	for (i = 2;i < n;i++) {
		flag = 0;
		for (j = 2;j<=i / 2;j++)
			if (i%j == 0) {
				flag = 1;
				break;
			}
		if (flag == 0){
			cout << i;
			cout << " ";
			cont++;
		}
		if (cont % 10==0){
			cout << "\n";
			cout << "\t";			
		}		
	}
	_getch();
	return 0;
}
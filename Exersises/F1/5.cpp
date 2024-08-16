#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	int n, i = 2,flag=0;
	cout << "Plz enter anumber: ";
	cin >> n;
	while (n > 1)
		if (n%i == 0){
			n = n / i;	
			if (i != flag){
				cout << " " << i;
				flag = i;
			}
		}
		else
			i++;

	_getch();
	return 0;
}
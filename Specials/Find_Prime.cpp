#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	for (int flag = 0;flag ==0; ) {
		cout << "Plz enter a number : ";
		cin >> n;
		for(int i=2;i<(n/2);i++)
			if (n%i == 0) {
				flag = 1;
				break;
			}
		if (flag == 0) {
			cout << "yes";
			break;
		}
		flag = 0;
	}

	_getch();
	return 0;

}
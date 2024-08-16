#include <conio.h>
#include <iostream>

using namespace std;

int main(){
	int n;
	cout << "Plz enter a number : ";
	cin >> n;
	int i = 2;
	int flag = 0; 
	while (i < (n / 2) && flag != 1) {
		if (n %i == 0)
			flag = 1;
		i++;
	}
	if (flag == 1)   
		cout << "is not prime";
	else
		cout << "is prime";
	_getch();
	return 0;
	
}


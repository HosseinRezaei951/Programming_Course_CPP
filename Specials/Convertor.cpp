#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int i = 0;
	char a[100];
	
	cout << "Plz enter the string : ";
	gets_s(a);
	while (a[i] != '\0') {
		if (a[i] <= 'Z'&&a[i] >= 'A') 
			a[i] = a[i] + ('a' - 'A');
		
		else if (a[i] <= 'z'&&a[i] >= 'a') 
			a[i] = a[i] + ('A' - 'a');
		
		i++;
	}
	i = 0;
	while (a[i] != '\0') {
		cout << a[i];
		i++;
	}


	_getch();
	return 0;

}
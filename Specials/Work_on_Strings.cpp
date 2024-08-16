#include<conio.h>
#include<iostream>
#include <string.h>

using namespace std;

int main() {
	char a[100];
	char b[100];
	int i;

	/*i = 0;
	while (a[i] != '\0') {
		cout << a[i];
		i++;
	}

	i = 0;
	while (b[i] != '\0') {
		cout << b[i];
		i++;
	}*/
	/*cout << "Plz enter the first string : ";
	cin>>a;
	cout << "Plz enter the second string : ";
	gets_s(b);*/

	strcpy(a, "book");

	i = 0;
	while (a[i] != '\0') {
		cout << a[i];
		i++;
	}
	
	i = 0;
	while (b[i] != '\0') {
		cout << b[i];
		i++;
	}

	int Z=strcmp(a, b);
	cout << "Z : " << Z;

	cout << "***************************************";

	strcat(a, b);
	i = 0;
	while (a[i] != '\0') {
		cout << a[i];
		i++;
	}

	i = 0;
	while (b[i] != '\0') {
		cout << b[i];
		i++;
	}
	

	_getch();
	return 0;

}
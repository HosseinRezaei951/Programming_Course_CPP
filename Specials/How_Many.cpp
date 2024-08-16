#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	int i= 0;
	char a[100];
	int big = 0 ,small=0, num = 0 ;
	cout << "Plz enter the string : ";
	gets_s(a);
	while (a[i] != '\0') {
		if (a[i] >= '0'&&a[i] <= '9')
			num++;
		if (a[i] <= 'Z'&&a[i] >= 'A')
			big++;
		if (a[i] <= 'z'&&a[i] >= 'a')
			small++;
		i++;
	}
	cout << "big alpha : " << big << endl;
	cout << "small alpha : " << small << endl;
	cout << "numbers : " << num << endl;

	_getch();
	return 0;

}
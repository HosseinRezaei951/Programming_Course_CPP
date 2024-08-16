#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<math.h>
using namespace std;

int main() {

	struct number {
		int STR[100];
		int len;
	};

	number num[100];

	ifstream myfile;
	string STR;
	char str[100];
	int Sum[100];
	int flag = 0, counter = 0, i = 0, f=0,len=0,n=0,c=0;
	int j = 0,S=0;
	for (int i = 0; i < 100;i++)
		Sum[i] = 0;

	myfile.open("F:\\programming\\C++\\exersises\\f 3\\1-2\\input.txt");
	if (!myfile){
		cout << "Error in reading";
		_getch();
		exit(0);
	}


	cout << "The file is : ";
	
	while (myfile >> str[j]){
		cout << str[j];
		j++;
	}
	cout << endl;

	while (i < j) {
		flag = 0;
		len = 0;
		c = 0;
		while (str[i] >= '0' && str[i] <= '9') { 
			num[counter].STR[c] = str[i]-'0';
			i++;
			c++;
			len++;
			flag = 1;
		}
		
		if (flag == 1){
			num[counter].len = len;
			counter++;

		}
		else
			i++;
	}
	
	for (int i = 0;i < counter;i++) {
		for (int j = 0;j < num[i].len+1;j++) {
			long A = (num[i].STR[j]);
			long B = pow(10, (num[i].len) - 1);
			
			Sum[i] = Sum[i] +(A * B);
			num[i].len--;

		}
	}

	for (int i = 0;i < counter;i++)
		S = S + Sum[i];
	cout << "The sum of all numbers in the file: " << S<< endl;
	
	myfile.close();
	_getch();
	return 0;
}

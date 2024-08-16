#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int main() {

	struct number {
		int STR[100];
		int len = 0;
		int len_2 = 0;
		int f = 0;
	};

	number num[100];

	ifstream myfile;
	string STR;
	char str[100];
	double Sum[100];
	int flag = 0, counter = 0, i = 0, f = 0, len = 0, len_2 = 0, n = 0, c = 0;
	int j = 0, T = 1, k = 0, z;
	double S = 0;
	for (int i = 0; i < 100;i++)
		Sum[i] = 0;

	myfile.open("F:\\programming\\C++\\exersises\\f 3\\3\\input.txt");
	if (!myfile) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}


	cout << "The file is : ";

	while (myfile >> str[j]) {
		cout << str[j];
		j++;
	}
	cout << endl;

	while (str[i] == ' ' || str[i] == '-' || str[i] == '+') {
		num[counter].f = str[i];
		
		i++;
		c = 0;
		flag = 0;
		len = 0;
		len_2 = 0;
		c = 0;
		while (str[i] >= '0' && str[i] <= '9') {
			num[counter].STR[c] = str[i] - '0';
			i++;
			c++;
			len++;
			flag = 1;

			if (str[i] == '.') {
				num[counter].STR[c] = '.';
				c++;
				i++;
				len_2 = 0;

				while (str[i] >= '0' && str[i] <= '9') {
					num[counter].STR[c] = str[i] - '0';
					i++;
					c++;
					len_2++;
					flag = 1;

				}

			}
		}
	

		if (flag == 1) {
			num[counter].len = len;
			num[counter].len_2 = len_2;
			counter++;

		}
		else
			i++;
	}


		                                                         


	for (int i = 0;i < counter;i++) {
		int PW = num[i].len;
		for (int z = 0;z < num[i].len;z++) {
			double A = (num[i].STR[z]);
			double B = pow(10, (PW)-1);
			
			Sum[i] = Sum[i] + (A * B);
			PW--;
		}

		int T = 0;
		if (num[i].len_2>0)
			for (int k = (num[i].len + 1);k < (num[i].len_2 + num[i].len) + 1;k++) {
				double A = (num[i].STR[k]);
				double B = pow(10, -(T + 1));

				Sum[i] = Sum[i] + (A * B);
				T++;
			}
	}
	int w = 0;
	for (int i = 0;i < counter;i++) {
		cout << "number" << i + 1 << ": " << Sum[i] << endl;
		if(num[w].f=='-')
			S = S - Sum[i];
		else
			S = S + Sum[i];
		w++;
	}
	cout << "The sum of all numbers in the file: " << S << endl;
	myfile.close();
	_getch();
	return 0;
}

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream myfile;
	char str[100];
	int flag = 0,counter=0,i=0,j=0,n=0;
	myfile.open("F:\\programming\\C++\\exersises\\f 3\\1\\input.txt");
	if (!myfile) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}
	cout << "The file is : ";
	while (myfile >> str[i]) {
		cout << str[i];
		i++;
	}
	n = i;
	/*cout << "\n" << n;*/
	for (int i = 0;i < n;i++) {
		flag = 0;

		while (str[i] >= '0' && str[i] <= '9') {
			flag = 1;
			if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '.') {
				j = i + 2;
				/*cout << "\n" << "j=" << j;*/
				while (str[j] >= '0' && str[j] <= '9') {
					flag = 1;
					j++;
				}

				i = j;
				/*cout << "\n" << "i=" << i;*/

			}
			else
				i++;
			/*cout << "\n" << "i=" << i;*/

		}

		if (flag == 1)
			counter++;
	}
	cout << "\nThe numbers are find in the file: "<<counter;
	
	myfile.close();
	_getch();
	return 0;
}

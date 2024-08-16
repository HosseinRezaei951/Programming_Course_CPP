#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

struct student {
	char name[100];
	char family[100];
	char id[100];
	float grades[5];
	float avg;
	// grades [0] is for Math
	// grades [1] is for Chemistry
	// grades [2] is for English
	// grades [3] is for Physics
	// grades [4] is for Programming

};

int main() {

	student st[100];
	int lines;
	ifstream myfile;


	myfile.open("F:\\programming\\C++\\exersises\\f 3\\2-2\\input.txt");
	if (!myfile) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}

	myfile >> lines;

	for (int i = 0;i < lines;i++) {
		myfile >> st[i].name;
		myfile >> st[i].family;
		myfile >> st[i].id;
		myfile >> st[i].grades[0];
		myfile >> st[i].grades[1];
		myfile >> st[i].grades[2];
		myfile >> st[i].grades[3];
		myfile >> st[i].grades[4];
		st[i].avg = (float)(st[i].grades[0] + st[i].grades[1] + st[i].grades[2] + st[i].grades[3] + st[i].grades[4]) / 5;

	}
	
	student tmp;
	int i, j;
	int a, b;

	/* strcmp (a,b) :
		if a in the first >> -1 
		if b in the first >> 1 
		else >> 0

		*/
	for (i = 0; i<lines; i++) {
		for (int j = i;j<lines;j++) {
			a = strcmp(st[i].family, st[j].family);

			if (a == 1) {
				tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
			if (a == 0) {
				b = strcmp(st[i].name, st[j].name);
				if (b == 1) {
					tmp = st[i];
					st[i] = st[j];
					st[j] = tmp;

				}


			}
		}
	}

	for (int i = 0; i < lines;i++)
		cout << st[i].name << " " << st[i].family << ": (id: " << st[i].id << ") avg = " << st[i].avg << endl;


	myfile.close();
	_getch();
	return 0;
}

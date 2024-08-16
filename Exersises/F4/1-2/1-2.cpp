#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

class student {
private:
	int lines;
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

public:

	//ste :
	void set(ifstream &myfile) {
		myfile >> name;
		myfile >> family;
		myfile >> id;
		myfile >> grades[0];
		myfile >> grades[1];
		myfile >> grades[2];
		myfile >> grades[3];
		myfile >> grades[4];
	}

	//calculat avg :
	void  setavg() {
		avg = (float)(grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5;
	}

	//get:
	float  getavg() { return avg = (float)(grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5; };
	char  getname() { return *name; }
	char  getfamily() { return *family; };
	//print :

	void print() {
		cout << name << " " << family << ": (id: " << id << ") avg = " << avg << endl;
	}
};

int main() {
	student st[100];
	int lines;
	ifstream myfile;
	myfile.open("F:\\programming\\C++\\exersises\\f 4\\1-2\\input.txt");
	if (!myfile) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}

	myfile >> lines;
	for (int i = 0;i < lines;i++) {
		st[i].set(myfile);
		st[i].setavg();
	}
	
	int a, b;
	char c, d;
	student tmp;
	for (int i = 0; i<lines; i++) {
		for (int j = i;j<lines;j++) {
			c = st[i].getfamily();
			d = st[j].getfamily();
			a = strcmp(&c, &d);


			if (a == 1) {
				tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			}
			if (a == 0) {
				c = st[i].getname();
				d = st[j].getname();
				b = strcmp(&c, &d);
				if (b == 1) {
					tmp = st[i];
					st[i] = st[j];
					st[j] = tmp;

				}


			}
		}
	}
	

	for (int i = 0; i < lines;i++)
		st[i].print();


	myfile.close();
	_getch();
	return 0;
}

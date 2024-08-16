#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

class student {
private :
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

public :
	
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
	float  getavg() { return avg=(float)(grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5; };

	//print :
	
	void print() {
		cout << name << " " << family << ": (id: " << id << ") avg = " << avg << endl;
	}
};

int main() {
	student st[100];
	int lines;
	ifstream myfile;
	myfile.open("F:\\programming\\C++\\exersises\\f 3\\2\\input.txt");
	if (!myfile) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}

	myfile >> lines;
	for (int i = 0;i < lines;i++)
		st[i].set(myfile);

	student temp;
	for (int i = 0; i < lines;i++) 
		for (int j = i;j < lines;j++)
			if (st[i].getavg() < st[j].getavg()) {
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}

	for (int i = 0; i < lines;i++)
		st[i].print();


	myfile.close();
	_getch();
	return 0;
}

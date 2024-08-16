#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

class Array {
private:
	int a[100];
	int len;
	int sum=0;
	float avg;

public:

	//ste :
	void setlen(int a) { len = a; }
	void setelement(int i, int x) { a[i] = x; }
	void setall(int x) {
		for (int i = 0;i < len;i++)
			a[i] = x;
	}
	void Sum(int x) { sum = sum + x; }
	//sort :
	void  sort() {
		int tmp;
		for (int i = 0;i < len - 1;i++)
			for (int j = i + 1;j < len;j++)
				if (a[i] > a[j]) {
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
	}


	//get :
	int  getlen() { return len; };
	int  getelement(int i) { return a[i]; }
	float getavg() { return avg; }

	//calculat avg :
	float calculat_avg() { return (float)avg = (float)(sum / len); }

	//print :
	void print() {
		for (int i = 0;i<len;i++)
			cout << a[i];
	}

};

int main() {
	Array A;
	int a;
	cout << "Plz enter number of elements: ";
	cin >> a;
	A.setlen(a);
	int b;
	for (int i = 0;i <( A.getlen());i++) {
		cout << "number" << i + 1 << ": ";
		cin >> b;
		A.setelement(i, b);
		A.Sum(b);
	}
	A.sort();
	A.calculat_avg();
	cout << "avg is: " << A.getavg() << " \nand the elements are above the avg are: " << endl;
	for (int i = 0;i < (A.getlen());i++)
		if (A.getelement(i) > A.getavg())
			cout << A.getelement(i) << "\t";

	_getch();
	return 0;
}

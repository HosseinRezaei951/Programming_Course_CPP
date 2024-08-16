#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

class array {
private:
	int a[100];
	int len;
	
public:

	//ste :
	void setlen(int a) { len = a; }
	void setelement(int i, int x) { a[i] = x; }
	void setall(int x) {
		for (int i = 0;i < len;i++)
			a[i] = x;
	}

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


	//get:
	int  getlen() { return len; };
	int  getelement(int i) { return a[i]; }
	//print :

	void print() {
		for(int i=0;i<len;i++)
			cout << a[i];
	}
};

int main() {
	
	_getch();
	return 0;
}

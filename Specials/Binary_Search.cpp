#include <iostream>
#include <conio.h>
using namespace std;

int merg(int n,int goal,int *a) {
	int low = 0;
	int high = n - 1; // n : number of elements (size)
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == goal)
			return (mid + 1);
		else if (a[mid] > goal)
			high = mid - 1;
		else if (a[mid] < goal)
			low = mid + 1;
	}
	return -1;
}

int main() {
	int n,goal;
	int a[100];
	cout << "Plz enter the number of elements : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "please enter number" << i + 1 << " : ";
		cin >> a[i];
	}
	cout << "Plz enter the goal : ";
	cin >> goal;
	
	int i = merg(n,goal,a);
	if (i != (-1))
		cout << "the goal was found in the : " << i ;
	else 
		cout << "the goal was not found ";

	_getch();
	return 0;
}

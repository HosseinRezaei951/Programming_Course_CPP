#include<conio.h>
#include<iostream>

using namespace std;

int main(){
	int n,sum = 0;
	int a[100];
	float avg;
	cout << "Plz enter the number of elements : ";
	cin >> n;
	for (int i = 0;i < n;i++) {
		cout << "plz enter number" << i + 1 << " : ";
		cin >> a[i];
		sum = sum + a[i];
	}
	(float)avg = (float)(sum / n);
	for (int i = 0;i < n;i++) 
		if (a[i] > avg)
			cout << "\t" << a[i];
		
	_getch();
	return 0;

}
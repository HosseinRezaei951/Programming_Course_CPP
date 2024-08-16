#include<conio.h>
#include<iostream>

using namespace std;

class Stack {
private:
	int maxsize;
	int *data;
	int top;

public:
	Stack();
	bool isempty();
	bool isfull();
	int getsize() { return top + 1; }
	bool push(int);
	bool pop(int&);
	Stack(int s);

};
Stack::Stack(){
	maxsize = 100;
	data = new int[100];
	top = -1;
	
}
bool Stack::isempty() {
	if (top == -1)
		return true;
	else
		return false;
}
bool Stack::isfull() {
	if (top < maxsize)
		return false;
	else
		return true;
}
bool Stack::push(int x) {
	if (isfull())
		return false;
	top++;
	data[top] = x;
		return true;
}
bool Stack::pop(int &x) {
	if (isempty())
		return false;
	x = data[top--];
	return true;
}
Stack::Stack(int s) {
	maxsize = s;
	data = new int[s];
	top = -1;
}



int main(){
	Stack a;

	bool t;
	if (a.isempty())
		cout << "Yes";

	t = a.push(7);
	t = a.push(13);
	t = a.push(11);

	int m;
	t = a.pop(m);
	t = a.pop(m);
	cout << m;
	Stack b(25);

	_getch();
	return 0;
}
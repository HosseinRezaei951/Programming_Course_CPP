#include<conio.h>
#include<iostream>

using namespace std;

template <class T>
class Stack {
private:
	int maxsize;
	T *data;
	int top;

public:
	Stack();
	bool isempty();
	bool isfull();
	int getsize() { return top + 1; }
	bool push(T x);
	bool pop(T &x);
	Stack(int s);

};

template <class T>
Stack<T>::Stack() {
	maxsize = 100;
	data = new T[100];
	top = -1;

}

template <class T>
bool Stack<T>::isempty() {
	if (top == -1)
		return true;
	else
		return false;
}

template <class T>
bool Stack<T>::isfull() {
	if (top < maxsize)
		return false;
	else
		return true;
}

template <class T>
bool Stack<T>::push(T x) {
	if (isfull())
		return false;
	top++;
	data[top] = x;
	return true;
}

template <class T>
bool Stack<T>::pop(T &x) {
	if (isempty())
		return false;
	x = data[top--];
	return true;
}

template <class T>
Stack<T>::Stack(int s) {
	maxsize = s;
	data = new T[s];
	top = -1;
}

int main() {
	Stack <int> a;

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
	//	Stack b(25);

	_getch();
	return 0;
}
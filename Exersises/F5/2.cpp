#include <conio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Node
{
	friend class LinkedList;

private:
	int value;
	Node* Next;

public:
	Node(void)
	{
		Next = NULL;
		value = 0;
	}

	Node(int val)
		: value(val), Next(NULL)
	{ }

	Node(int val, Node* next)
		: value(val), Next(next)
	{ }

	int getValue(void)
	{
		return value;
	}

	Node* getNext(void)
	{
		return Next;
	}

	void setvalue(int data)
	{
		value = data;
	}

	void setNext(Node* p)
	{
		Next = p;
	}

};

class LinkedList
{
private:
	Node* Head;
	Node* Tail;

public:
	LinkedList(void);
	LinkedList(int val);
	void traverse_and_print();
	void add_node_at_end(int val);
	void add_vlaue_to_all(int val);
	int how_many_have(int val);
};


LinkedList::LinkedList()
{
	Head = Tail = NULL;
}



LinkedList::LinkedList(int val)
{

	Head = new Node(val);
	Tail = Head;
}

void LinkedList::traverse_and_print()
{
	Node* p = Head;

	if (p == NULL) {
		cout << "The list is empty" << endl;
		return;
	}
	cout << "LinkedList: ";
	while (p != NULL) {
		cout << p->value << " ";
		p = p->Next;
	}
	cout << endl;
}

void LinkedList::add_node_at_end(int val)
{
	if (Head == NULL) {
		Head = new Node(val);
		Tail = Head;
		return;
	}
	Tail->Next = new Node(val);
	Tail = Tail->Next;
}

void LinkedList::add_vlaue_to_all(int val)
{
	if (Head == NULL) {
		cout << "There is no element in list. " << endl;
		return;
	}
	Node* tmp = Head;
	while (tmp != NULL) {
		tmp->value = tmp->value + val;
		tmp = tmp->Next;
	}
	return;
}

int LinkedList::how_many_have(int val)
{
	int ans=0;
	if (Head == NULL) {
		cout << "There is no element in list. " << endl;
		return ans;
	}
	Node* tmp = Head;

	while (tmp != NULL) {
		if (tmp->value == val)
			ans++;
		tmp = tmp->Next;
	}
	return ans;
}


int main()
{
	/* Create a list with only one node */
	LinkedList list1(10);

	/* add vlaue to elements of List2*/
	list1.add_node_at_end(15);
	list1.add_node_at_end(6);
	list1.add_node_at_end(222);
	list1.add_node_at_end(12);
	list1.add_node_at_end(2);
	list1.add_node_at_end(75);
	list1.add_node_at_end(10);
	list1.add_node_at_end(222);
	list1.add_node_at_end(35);
	list1.add_node_at_end(222);


	cout << "Created a list named list1 :" << endl;
	list1.traverse_and_print();
	cout << "\n";

	/* give goal */
	int n;
	cout << "Plz enter a number : ";
	cin >> n;
	
	/* how many we have */
	cout << "we have " << list1.how_many_have(n) << " of {" << n <<"}"<< endl;
	cout << "\n";

	/* Create a list with only one node */
	LinkedList list2;
	cout << "Created a list named list2 :" << endl;
	list2.traverse_and_print();
	cout << "\n";

	int m;
	cout << "Plz enter a number : ";
	cin >> m;
	/* how many we have */
	cout << "we have " << list2.how_many_have(m) << " of {" << m << "}" << endl;


	_getch();
	return 0;
}

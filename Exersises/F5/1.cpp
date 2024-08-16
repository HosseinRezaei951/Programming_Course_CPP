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
	if (Head == NULL){
		Head = new Node(val);
		Tail = Head;
		return;
	}
	Tail->Next = new Node(val);
	Tail = Tail->Next;
}

void LinkedList::add_vlaue_to_all(int val) {
	if (Head == NULL){
		cout << "There is no element in list. " << endl;
		return;
	}
	Node* tmp = Head;
	while (tmp!=NULL){
		tmp->value = tmp->value + val;
		tmp = tmp->Next;
	}
	return;
}


int main()
{
	/* Create a list with only one node */
	LinkedList list1(10);

	/* add vlaue to elements of List2*/
	list1.add_node_at_end(15);
	list1.add_node_at_end(6);
	list1.add_node_at_end(222);
		
	cout << "Created a list named list2 with only one node." << endl;
	list1.traverse_and_print();
	cout << "\n";
	
	/* add same vlaue to all elements of List2*/
	cout << "Add same vlaue(7) to all elements of List2." << endl;
	list1.add_vlaue_to_all(7);
		
	list1.traverse_and_print();
	cout << "\n";

	/* Create an empty list */
	LinkedList list2;
	cout << "Create an empty list then Add same vlaue(7) to all elements of List2." << endl;

	cout << "Add vlaue(7) to all elements of List3." << endl;
	list2.add_vlaue_to_all(7);
	list2.traverse_and_print();


	_getch();
	return 0;
}

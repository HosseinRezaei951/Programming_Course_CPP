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
	Node* get_head(void);
	Node* get_tail(void);
	Node* get_next_node(Node*);
	void set_head(Node* p);
	void set_tail(Node* p);
	void add_node_at_end(int val);
	void add_vlaue_to_all(int val);
	int how_many_have(int val);
	void revers(void);
	void chang(void);
	void sort();
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
	int ans = 0;
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

Node* LinkedList::get_head(void)
{
	return Head;
}

Node* LinkedList::get_tail(void)
{
	return Tail;
}

void LinkedList::set_head(Node* p)
{
	Head = p;
	return;
}

void LinkedList::set_tail(Node* p)
{
	Tail = p;
	return;
}

Node* LinkedList::get_next_node(Node* p)
{
	Node* tmp = p;
	tmp = p->Next;
	return tmp;
}

void myListcopy(LinkedList &listA, LinkedList &listB)
{
	Node* tmp = listB.get_head();

	while (tmp != NULL) {
		listA.add_node_at_end(tmp->getValue());
		tmp = listB.get_next_node(tmp);

	}

	listA.set_tail(listB.get_tail());
	return;
}

void LinkedList::revers(void)
{
	if (Head == NULL)
		return;

	Node *prev = NULL, *current = NULL, *next = NULL;
	current = Head;
	while (current != NULL) {
		next = current->Next;
		current->Next = prev;
		prev = current;
		current = next;
	}
	// now let the head point at the last node (prev)
	Head = prev;

	return;
}

void LinkedList::chang(void)
{
	Node *prev = NULL, *current = NULL, *next = NULL, *tmp = NULL;
	int flag = 0;
	current = Head;
	next = current->Next;

	Head = next;
	while (next->Next != NULL)
	{
		tmp = next->Next;
		next->Next = current;

		if (prev != NULL)
			prev->Next = next;

		prev = current;
		current = tmp;
		next = tmp->Next;
		if (current->Next == NULL)
			break;
	}

	prev->Next = next;
	if (next != NULL)
		next->Next = current;
	else
	{
		prev->Next = current;
		Tail = current;
		current->Next = NULL;
		flag++;
	}


	if (flag == 0)
	{
		Tail = current;
		current->Next = NULL;
	}

	return;
}

void LinkedList::sort()
{
	Node * temphead = Head;
	Node * tempnode = NULL;
	int count = 0;
	while (temphead)
	{
		temphead = temphead->Next;
		count++;
	}
	cout << count;
	_getch();
	for (int i = 0; i<count; i++) {
		cout << "bad" << endl;

		for (int j = i+1; j<count; j++) {
			cout << "bad" << endl;
			if ((temphead->value) > (temphead->Next)->value) {
				tempnode = temphead;
				temphead = temphead->Next;
				temphead->Next = tempnode;
				cout << "bad" << endl;
			}

			temphead = temphead->Next;
			/*count++;*/
		}
	}
	return;
}

int main()
{
	/* Create a list with only one node */
	LinkedList list1;

	/* add vlaue to elements of List1*/
	
	list1.add_node_at_end(1);
	list1.add_node_at_end(2);
	list1.add_node_at_end(3);
	list1.add_node_at_end(4);
	list1.add_node_at_end(5);
	
	/*list1.add_node_at_end(1);
	list1.add_node_at_end(5);
	list1.add_node_at_end(2);
	list1.add_node_at_end(4);
	list1.add_node_at_end(3);*/


	cout << "Created a list named list1 :" << endl;
	list1.traverse_and_print();

	cout << "\n";

	list1.sort(list1);
	cout << "New list1 :" << endl;
	list1.traverse_and_print();
	cout << "\n";





	_getch();
	return 0;
}


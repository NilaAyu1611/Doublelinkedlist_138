#include <iostream>
#include < string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();			//step 1
	newNode->noMhs = nim;		//step 2
	newNode->name = nm;			//step 2

	/*insert a node in the beginning of a doubly - linked listy*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;		//Step 3 (Make the next field of the new node point to the first node in the list)
		if (START != NULL)
			START->prev = newNode;		// step 4 (Make the prev field of START point to the new node)
		newNode->prev = NULL;		//step 5 (Make the prev field of the new node point to NULL)
		START = newNode;		//Step 6 (Make START, point to the new node)
		return;
	}

	/*Inserting a Node Between Two Nodes in the List*/
	Node* current = START;			// step 1.a (Make current point to the first node)
	Node* previous = NULL;					//step 1.b (Make previous point to NULL)
	while (current->next != NULL && current->next->noMhs < nim)			//step 1.c (Repeat steps d and e until current.info > newnode.info or current = NULL)
	{
		previous = current;						// 1.d (Make previous point to current)
		current = current->next;					//1.e (Make current point to the next node in sequence)
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;		//step 4 (Make the next field of the new node point to current)
	newNode->prev = current;		//step 5 (Make the prev field of the new node point to previous)
	if (current->next != NULL)
		current->next->prev = newNode;		//step 6 (Make the prev field of current point to the new node)
	current->next = newNode;		//step 7 (Make the next field of previous point to the new node)
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;		//Step 1.a
	*current = START;		//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {		//step 1.c
		*previous = *current;		//step 1.d
		*current = (*current)->next;		//step 1.e
	}
	return (*current != NULL);
}

	


	
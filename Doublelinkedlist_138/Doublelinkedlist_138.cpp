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

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous->next;		//step 2
	if (previous != NULL)
		previous->next = current->next;			//step 3
	else
		START = current->next;

	delete current;		//step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted" << endl;
}

void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record from the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values enterned." << endl;
		}
	}
}



	
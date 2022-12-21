#include <iostream>

using namespace std;

template <class T>
class Node {
public:
	T val;
	Node *next;
};

template <class T>
class SinglyLinkedList {
protected:
	Node<T> *head, *tail;
public:
	SinglyLinkedList() {
		head = tail = NULL;
	}

	~SinglyLinkedList() {
		if (this->isEmpty())
			return;
		Node<T> *ptr, *temp = head;
		while (temp != NULL) {
			ptr = temp->next;
			delete temp;
			temp = ptr;
		}
		head = tail = NULL;
		return;
	}

	bool isEmpty() {
		return (head == NULL || tail == NULL);
	}

	void addToHead(int x) {
		Node<T> *temp = new Node<T>();
		temp->val = x;
		temp->next = head;
		if (this->isEmpty())
			tail = temp;
		head = temp;
	}

	void addToTail(int x) {
		Node<T> *temp = new Node<T>();
		temp->val = x;
		temp->next = NULL;
		if (this->isEmpty())
			head = tail = temp;
		else
			tail->next = temp;
		tail = temp;
	}

	void addAtLoc(int x, int loc) { // loc start from 1
		if (loc == 1) {
			this->addToHead(x);
			return;
		}
		Node<T> *temp = head;
		for (int i = 1; temp != NULL && i < loc - 1; i++)
			temp = temp->next; // this gives element before the position 
		if (temp == NULL) {
			cout << "Invalid location...\n";
			return;
		} if (temp == tail) {
			this->addToTail(x);
			return;
		}
		Node<T> *node = new Node<T>();
		node->val = x;
		node->next = temp->next;
		temp->next = node;
	}

	void deleteFromHead() {
		if (this->isEmpty()) {
			cout << "Can not delete from an empty list!\n";
			return;
		}
		Node<T> *temp = head;
		head = temp->next;
		delete temp;
		if (this->isEmpty())
			tail = NULL;
	}

	void deleteFromTail() {
		if (this->isEmpty()) {
			cout << "Can not delete from an empty list!\n";
			return;
		}
		if (head == tail) {
			this->deleteFromHead();
			return;
		}
		Node<T> *temp = head;
		while (temp->next->next != NULL)
			temp = temp->next;
		delete temp->next;
		temp->next = NULL;
		tail = temp;
	}

	void deleteAtLoc(int loc) {
		if (this->isEmpty()) {
			cout << "Can not delete from an empty list!\n";
			return;
		}
		if (loc == 1) {
			this->deleteFromHead();
			return;
		}
		Node<T> *temp = head;
		for (int i = 1; temp != NULL && i < loc - 1; i++) 
			temp = temp->next; // this gives the term before the postion
		if (temp == NULL || temp->next == NULL) {
			cout << "Invalid location...\n";
			return;
		}
		if (temp == tail) {
			this->deleteFromTail();
			return;
		}
		Node<T> *node = temp->next->next;
		delete temp->next;
		temp->next = node;
	}

	void reverse() {
		if (this->isEmpty()) {
			cout << "\nList is empty.\n";
			return;
		}
		Node<T> *temp = head,
		         *next = NULL,
		          *prev = NULL;
		tail = temp;
		while (temp != NULL) {
			next = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next;
		}
		head = prev;
		cout << "\nList reversed...\n";
	}

	void concat(SinglyLinkedList<T> &list) {
		if (list.isEmpty() || this->isEmpty()) {
			cout << "\nOne of the list is empty\n";
			return;
		}
		Node<T> *node,
		     *temp = tail,
		      *temp1 = list.head;
		while (temp1 != NULL) {
			node = new Node<T>();
			node->val = temp1->val;
			temp->next = node;
			temp = temp->next;
			temp1 = temp1->next;
		}
		tail = node;
		cout << "Concatenated two lists...\n";
	}

	void operator+(SinglyLinkedList<T> &list) {
		this->concat(list);
	}

	Node<T> *search(T e) {
		if (this->isEmpty())
			return nullptr;
		Node<T> *temp = head;
		while (temp != NULL) {
			if (temp->val == e)
				return temp;
			temp = temp->next;
		}
		return nullptr;
	}

	int count() {
		if (this->isEmpty())
			return 0;
		int count = 0;
		Node<T> *temp = head;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	void display() {
		if (this->isEmpty()) {
			cout << "\nList is empty.\n";
			return;
		}
		Node<T> *temp = head;
		cout << "\nList: ";
		while (temp->next != NULL) {
			cout << temp->val << " -> ";
			temp = temp->next;
		}
		cout << temp->val << endl;
	}
};

int main() {
	int choice, e, loc, size, val;
	SinglyLinkedList<int> ob, ob1;
	do {
		cout << "\tSingly Linked List\n"
		     << "=====================================\n"
		     << " (1)  Search		(2)  AddToHead\n"
		     << " (3)  AddToTail		(4)  AddAtLoc\n"
		     << " (5)  DeleteFromHead	(6)  DeleteFromTail\n"
		     << " (7)  DeleteAtLoc	(8)  Display\n"
		     << " (9)  Count		(10) Reverse\n"
		     << " (11) Concat		(0)  Exit\n";
		     cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter search element: ";
			cin >> e;
			if (ob.search(e) != nullptr)
				cout << "Element " << e << " found...\n";
			else
				cout << "Element not found...\n";
			break;
		case 2:
			cout << "\nEnter element: ";
			cin >> e;
			ob.addToHead(e);
			break;
		case 3:
			cout << "\nEnter element: ";
			cin >> e;
			ob.addToTail(e);
			break;
		case 4:
			cout << "\nEnter element: ";
			cin >> e;
			cout << "Enter location: ";
			cin >> loc;
			ob.addAtLoc(e, loc);
			break;
		case 5:
			ob.deleteFromHead();
			break;
		case 6:
			ob.deleteFromHead();
			break;
		case 7:
			cout << "\nEnter location: ";
			cin >> loc;
			ob.deleteAtLoc(loc);
			break;
		case 8:
			ob.display();
			break;
		case 9:
			cout << "\nNumber of nodes: " << ob.count() << endl;
			break;
		case 10:
			ob.reverse();
			break;
		case 11:
			if (!ob1.isEmpty()) {
				cout << "\nList B: ";
				     ob1.display();
			}
			cout << "Enter number of nodes in list B: ";
			cin >> size;
			for (int i = 0; i < size; i++) {
				cout << "Enter element: ";
				cin >> val;
				ob1.addToTail(val);
			}
			ob + ob1;
			break;
		case 0:
			break;
		default:
			cout << "Invalid choice...\n";
		}
		system("pause");
		system("cls");
	} while (choice != 0);
}
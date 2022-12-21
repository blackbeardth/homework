#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	Node<T> *next;
	T val;
};

template <class T>
class CircularSinglyLinkedList {
protected:
	Node<T> *tail;
public:
	CircularSinglyLinkedList() {
		tail = NULL;
	}

	~CircularSinglyLinkedList() {
		if (this->isEmpty())
			return;
		Node<T> *ptr, *temp = tail->next;
		while (temp != tail) {
			ptr = temp->next;
			delete temp;
			temp = ptr;
		}
		delete temp;
		tail = NULL;
	}

	bool isEmpty() {
		return (tail == NULL);
	}

	void addToHead(T x) {
		Node<T> *temp = new Node<T>();
		temp->val = x;
		if (this->isEmpty()) {
			temp->next = temp;
			tail = temp;
			return;
		}
		temp->next = tail->next;
		tail->next = temp;
	}
	void addToTail(T x) {
		Node<T> *temp = new Node<T>();
		temp->val = x;
		if (this->isEmpty()) {
			// this->addToHead(x)
			temp->next = temp;
			tail = temp;
			return;
		}
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	void addAtLoc(int loc, T x) {
		if (this->isEmpty()) {
			cout << "List was empty...\n";
			return;
		}
		if (loc == 1) {
			addToHead(x);
			return;
		}
		Node<T> *temp = tail->next;

		int i = 1;
		do {
			temp = temp->next;
			i++;
		} while (temp != tail->next && i < loc - 1);
		if (temp == tail->next) {
			cout << "Invalid location...\n";
			return;
		}
		if (temp == tail) {
			addToTail(x);
			return;
		}
		Node<T> *node = new Node<T>();
		node->val = x;
		node->next = temp->next;
		temp->next = node;
	}
	void deleteFromHead() {
		if (this->isEmpty()) {
			cout << "List is empty...\n";
			return;
		}
		Node<T> *temp = tail->next;
		tail->next = temp->next;
		delete temp;
	}
	void deleteFromTail() {
		if (this->isEmpty()) {
			cout << "List is empty...\n";
			return;
		}
		if (tail->next == tail) {
			delete tail;
			tail = NULL;
			return;
		}
		Node<T> *temp = tail->next;
		while (temp->next != tail)
			temp = temp->next;
		temp->next = tail->next;
		delete tail;
		tail = temp;
	}

	void deleteAtLoc(int loc) {
		if (this->isEmpty()) {
			cout << "List is empty...\n";
			return;
		}
		if (loc == 1) {
			deleteFromHead();
			return;
		}
		Node<T> *temp = tail->next;
		int i = 1;
		do {
			temp = temp->next;
			i++;
		} while (temp != tail->next && i < loc - 1);
		if (temp == tail->next) {
			cout << "Invalid location...\n";
			return;
		}
		if (temp->next == tail) {
			deleteFromTail();
			return;
		}
		Node<T> *node = temp->next;
		temp->next = node->next;
		delete node;
	}
	void concat(CircularSinglyLinkedList<T> &list) {
		if (list.isEmpty() || this->isEmpty()) {
			cout << "One of the lists is empty...\n";
			return;
		}
		Node<T> *temp = tail->next;
		tail->next = list.tail->next;
		tail = list.tail;
		tail->next = temp;
	}
	void operator+(CircularSinglyLinkedList<T> &list) {
		this->concat(list);
	}
	Node<T> *search(T e) {
		if (this->isEmpty()) {
			return nullptr;
		}
		Node<T> *temp = tail->next;
		do {
			if (temp->val == e)
				return temp;
			temp = temp->next;
		} while (temp != tail->next);
		return nullptr;
	}
	int count() {
		Node<T> *temp = tail->next;
		int count = 0;
		do {
			temp = temp->next;
			count++;
		} while (temp != tail->next);
		return count;
	}
	void display() {
		if (this->isEmpty()) {
			cout << "\nList is empty...\n";
			return;
		}
		Node<T> *temp = tail->next;
		cout << "\nList: ";
		while (temp != tail) {
			cout << temp->val << " -> ";
			temp = temp->next;
		}
		cout << temp->val << endl;
	}
};

int main() {
	int choice, e, loc, size, val;
	CircularSinglyLinkedList<int> ob, ob1;
	do {
		cout << "\tCircular Singly Linked List\n"
		     << "===========================================\n"
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
			// ob.reverse();
			cout << "Work in progress...\n";
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

// Stack implementation using Linked list
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

	T getTail() {
		return this->isEmpty() ? (T)(NULL) : this->tail->val;
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
			temp = temp->next;
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
			temp = temp->next;
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
		node = NULL;
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
		while (temp->next != NULL) {
			cout << temp->val << " -> ";
			temp = temp->next;
		}
		cout << temp->val << endl;
	}
};

template <class T>
class Stack {
protected:
	SinglyLinkedList<T> list;
public:
	bool isEmpty() {
		return list.isEmpty();
	}
	bool push(T e) {
		list.addToTail(e);
		return true;
	}
	T pop() {
		if (this->isEmpty()) {
			cout << "ERROR: Buffer Underflow...\n";
			return (T)(NULL);
		}
		T val = list.getTail();
		list.deleteFromTail();
		return val;
	}
	T top() {
		if (this->isEmpty()) {
			cout << "ERROR: Buffer Underflow...\n";
			return (T)(NULL);
		}
		return list.getTail();
	}
	void clear() {
		list.~SinglyLinkedList();
	}
	void display() {
		if (this->isEmpty()) {
			cout << "ERROR: Stack is empty...\n";
			return;
		}
		cout << "\nStack: ";
		list.display();
	}

};

int main() {
	int e, choice, out;
	Stack<int> ob;
	do {
		cout << "\tStack-SLL\n"
		     << "==============================\n"
		     << " (1) Push	(2) Pop\n"
		     << " (3) Top	(4) Is Empty\n"
		     << " (5) Clear	(6) Display\n"
		     << " (0) Exit\n";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter element: ";
			cin >> e;
			ob.push(e);
			break;
		case 2:
			out = ob.pop();
			if (out != 0)
				cout << "Element Popped: " << out << endl;
			break;
		case 3:
			out = ob.top();
			if (out != 0)
				cout << "Element on Top: " << out << endl;
			break;
		case 4:
			ob.isEmpty() ? cout << "True\n" : cout << "False\n";
			break;
		case 5:
			ob.clear();
			break;
		case 6:
			ob.display();
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
// practical9

//#include "csll.cpp"
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
public:
	Node<T> *tail;

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


template <class T>
class Queue {
protected:
	Node<T>* front, *rear;
	CircularSinglyLinkedList<T> list;
public:
	Queue() {
		front = rear = list.tail;
	}
	bool isEmpty() {
		return list.isEmpty();
	}
	
	bool enqueue(T e) {
		list.addToTail(e);
		front = list.tail->next;
		rear = list.tail;
		return true;
	}
	T dequeue() {
		if (this->isEmpty()) {
			cout << "ERROR: Queue is empty...\n";
			return (T)(NULL);
		}
		T temp = front->val;
		list.deleteFromHead();
		if (this->isEmpty())
			front = list.tail;
		else
			front = list.tail->next;
		rear = list.tail;
		return temp;
	}
	void display() {
		int i; 
		if (this->isEmpty()) {
			cout << "ERROR: Queue is empty...\n";
			return;
		}
		list.display();
	}
};

int main() {
	int size, e, choice, out;
	Queue<int> ob;
	do {
		cout << "\tCircular linked list Queue\n";
		cout << "============================\n";
		cout << " (1)Enqueue	(2)Dequeue\n"
		     << " (3)Display	(0)Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter element: ";
			cin >> e;
			ob.enqueue(e);
			cout << "Element enqueued\n";
			break;
		case 2:
			out = ob.dequeue();
			if (out != 0)
				cout << "Element dequeued: " << out << endl;
			break;
		case 3:
			ob.display();
			break;
		case 0:
			break;
		default:
			cout << "Invalid input...\n";
		}
		system("pause");
		system("cls");
	} while (choice != 0);
}
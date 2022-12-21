#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T val;
	Node *next = NULL;
	Node *prev = NULL;
};

template <class T>
class DoublyLinkedList {
public:
	Node<T> *head, *tail;

	DoublyLinkedList() {
		head = tail = NULL;
	}

	~DoublyLinkedList() {
		if (this->isEmpty())
			return;
		Node<T> *temp, *ptr = head;
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
		if (this->isEmpty())
			head = tail = temp;
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void addToTail(int x) {
		Node<T> *temp = new Node<T>();
		temp->val = x;
		if (this->isEmpty())
			head = tail = temp;
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	void addAtLoc(int x, int loc) {
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
		}
		if (temp == tail) {
			this->addToTail(x);
			return;
		}
		Node<T> *node = new Node<T>();
		node->val = x;
		node->prev = temp;
		node->next = temp->next;
		temp->next = node;
		node->next->prev = node;
	}

	void deleteFromHead() {
		if (this->isEmpty()) {
			cout << "Can not delete from an empty list!\n";
			return;
		}
		Node<T> *temp = head;
		head = temp->next;
		if (this->isEmpty())
			tail = NULL;
		else
			head->prev = NULL;
		delete temp;
	}

	void deleteFromTail() {
		if (this->isEmpty()) {
			cout << "Can not delete from an empty list!\n";
			return;
		}
		Node<T> *temp = tail;
		tail = temp->prev;
		if (this->isEmpty())
			head = NULL;
		else
			tail->next = NULL;
		delete temp;
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
		if (temp->next == tail) {
			this->deleteFromTail();
			return;
		}
		Node<T> *node = temp->next;
		temp->next = node->next;
		node->next->prev = temp;
		delete node;
	}
	void reverse() {
		if (this->isEmpty()) {
			cout << "List is empty...\n";
			return;
		}
		Node <T> *temp = head,
		          *temp1 = NULL;
		tail = temp;
		while (temp1 != NULL) {
			temp1 = temp->prev;
			temp->prev = temp->prev;
			temp = temp->prev;
		}
		if (temp1 != NULL)
			head = temp->prev;
	}
	void concat(DoublyLinkedList<T> &list) {
		if (list.isEmpty() || this->isEmpty()) {
			cout << "\nOne of the lists is empty...\n";
			return;
		}
		Node<T> *node,
		     *temp = tail,
		      *temp1 = list.head;

		while (temp1 != NULL) {
			node = new Node<T>();
			node->val = temp1->val;
			node->prev = temp;
			temp->next = node;
			temp = temp->next;
			temp1 = temp1->next;
		}
		tail = node;
		cout << "Concatenated two lists...\n";
	}

	void operator+(DoublyLinkedList<T> &list) {
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

template <class T>
class DoublyEndedQueue
{
protected:
	Node<T> *front, *rear;
	DoublyLinkedList<T> list;
public:
	DoublyEndedQueue()
	{
		this->front = this->list.head;
		this->rear = this->list.tail;
	}
	void enqueueFront(T ele)
	{
		this->list.addToHead(ele);
		this->front = this->list.head;
		this->rear = this->list.tail;
	}
	void enqueueRear(T ele)
	{
		this->list.addToTail(ele);
		this->front = this->list.head;
		this->rear = this->list.tail;
	}
	T dequeueFront()
	{
		if (this->isEmpty())
		{
			cout << "ERROR: Queue Empty\n";
			return (T)(NULL);
		}
		T temp = this->front->val;
		this->list.deleteFromHead();
		this->front = this->list.head;
		this->rear = this->list.tail;
		return temp;
	}
	T dequeueRear()
	{
		if (this->isEmpty())
		{
			cout << "ERROR: Queue Empty\n";
			return (T)(NULL);
		}
		T temp = this->rear->val;
		this->list.deleteFromTail();
		this->front = this->list.head;
		this->rear = this->list.tail;
		return temp;
	}
	T frontEl()
	{
		if (this->isEmpty())
		{
			cout << "Queue Empty";
			return (T)(NULL);
		}
		return this->front->val;
	}
	bool isEmpty()
	{
		return this->list.isEmpty();
	}
	void clear()
	{
		while (!this->isEmpty())
			this->dequeue();
	}
	void display()
	{
		if (this->isEmpty())
		{
			cout << "Queue Empty";
			return;
		}
		this->list.display();
		return;
	}
};
int main(void)
{
	int el, res, choice;
	DoublyEndedQueue<int> q;
	do
	{
		cout << "\tDoubly Ended Queue - Deque\n"
		     << "====================================\n"
		     << " (1) EnqueueBack (2) DequeueRear\n"
		     << " (3) EnqueueFront (4) DequeueFront\n"
		     << " (5) Front (6) Display\n"
		     << " (0) Exit\n\n";
		cout << "Enter Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter Element: ";
			cin >> el;
			q.enqueueRear(el);
			cout << "\nEnqueued " << el << " at rear...\n";
			cout << "Queue: ";
			q.display();
			break;
		case 2:
			res = q.dequeueRear();
			if (res)
			{
				cout << "\nDequeued " << res << " from rear...\n";
				cout << "Queue: ";
				q.display();
			}
			break;
		case 3:
			cout << "\nEnter Element: ";
			cin >> el;
			q.enqueueFront(el);
			cout << "\nEnqueued " << el << " at front...\n";
			cout << "Queue: ";
			q.display();
			break;
		case 4:
			res = q.dequeueFront();
			if (res)
			{
				cout << "\nDequeued " << res << " from front...\n";
				cout << "Queue: ";
				q.display();
			}
			break;
		case 5:
			cout << "\nFront Element: "
			     << q.frontEl() << endl;
			break;
		case 6:
			cout << "\nQueue: ";
			q.display();
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 0);
	return 0;
}
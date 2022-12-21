#include <iostream>
#define MAX_SIZE 100
using namespace std;

template <class T>
class Queue {
protected:
	int front, rear, size;
	T arr[MAX_SIZE];
public:
	Queue(int size = 30) {
		front = rear = -1;
		this->size = size;
	}
	bool isFull() {
		return (front == 0 && rear == size - 1) || (front == rear + 1);
	}
	bool isEmpty() {
		return (front == -1);
	}
	void enqueue(T e) {
		if (this->isFull()) {
			cout << "ERROR: Queue is full...\n";
			return;
		}
		if (front == -1)
			front++;
		arr[++rear] =  e;
	}
	T dequeue() {
		if (front == -1) {
			cout << "ERROR: Queue is empty...\n";
			return (T)(NULL);
		}
		T temp = arr[front];
		if (front == rear) {
			front = rear = -1;
			return temp;
		}
		if (front == size - 1) {
			front = 0;
			return temp;
		}
		return arr[front++];
	}
	void display() {
		int i;
		if (front == -1) {
			cout << "ERROR: Queue is empty...\n";
			return;
		}
		else if (rear >= front) {
			for (i = front; i < rear; i++) 
				cout << arr[i] << " <- ";
			cout << arr[i] << endl;
		}
		else {
			for (i = front; i < size; i++)
				cout<< arr[i] << "<-";
			for (int i = 0; i < rear; i++)
				cout<< arr[i] << " <- ";
			cout<< arr[i] << endl;
		}	
	}
};

int main() {
	int size, e, choice, out;
	cout << "Enter size of the queue: ";
	cin >> size;
	Queue<int> ob(size);
	do {
		cout << "\tLinear Queue\n";
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
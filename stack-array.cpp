//Stack implementation based on an array.

#include <iostream>
using namespace std;
#define MAX_SIZE 100

template <class T>
class Stack {
protected:
	int tos, size;
	T arr[MAX_SIZE];
public:
	Stack(int size = 30) {
		tos = -1;
		this->size = size;
	}
	bool isEmpty() {
		return (tos == -1);
	}
	bool push(T e) {
		if (tos >= size - 1) {
			cout << "ERROR: Stack Overflow...\n";
			return false;
		}
		arr[++tos] = e;
		return true;
	}
	T pop() {
		if (this->isEmpty()) {
			cout << "ERROR: Stack Underflow...\n";
			return (T)(NULL);
		}
		return arr[tos--];
	}
	T top() {
		if (this->isEmpty()) {
			cout << "ERROR: Stack is empty...\n";
			return (T)(NULL);
		}
		return arr[tos];
	}
	void clear() {
		while (!this->isEmpty())
			this->pop();
	}
	void display() {
		if (this->isEmpty()) {
			cout << "ERROR: Stack is empty...\n";
			return;
		}
		cout << "\nStack: ";
		int i;
		for (i = 0; i < tos; i++) {
			cout << arr[i] << " -> ";
		}
		cout << arr[i] << endl;
		cout << endl;
	}
};


int main() {
	int size, e, choice, out;
	cout << "Enter size of the stack: ";
	cin >> size;
	Stack<int> ob(size);
	do {
		cout << "\tStack-Array\n"
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


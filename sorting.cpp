// practical 12

#include <iostream>
#define MAX_SIZE 100
using namespace std;

template <class T>
void swapElements(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
T *bubbleSort(T *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swapElements<T>(arr[j], arr[j + 1]);
		}
	}
	return arr;
}

template <class T>
T *insertionSort(T *arr, int size)
{
	T key;
	int i, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return arr;
}
template <class T>
T *selectionSort(T *arr, int size) {
	int min;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		swapElements<T>(arr[i], arr[min]);
	}
	return arr;
}

template <class T>
void display(T *arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main() {
	int arr[] = {4, 2, 3, 5, 1};
	display<int>(insertionSort<int>(arr, 5), 5);
}
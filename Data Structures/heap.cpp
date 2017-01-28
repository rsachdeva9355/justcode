#include<iostream>
#include<climits>

using namespace std;

bool isPrior(int neu, int old) {
	return neu > old;
}

void printArr(int *heap, int size) {
	cout << endl;
	for (int i = 1; i <= size; i++) {
		cout << heap[i] << " ";
	}
}

void heapify(int *heap, int size, int i) {
	int temp = heap[i];
	int j = i * 2;
	while (j <= size) {
		j = j >= size ? j : (heap[j] > heap[j + 1] ? j : j + 1);
		if (heap[j] < temp) {
			break;
		} else {
			heap[j/2] = heap[j];
			j *= 2;
		}
	}
	heap[j/2] = temp;
}

void buildHeap(int *heap, int size) {
	for (int i = size / 2; i >= 1; i--) {
		heapify(heap, size, i);
		printArr(heap, size);
	}
}

int getTop(int *heap) {
	return heap[1];
}

int removeTop(int *heap, int size) {
	heap[1] = heap[size];
	heap[size] = INT_MIN;
	heapify(heap, size - 1, 1);
	return size - 1;
}

int main() {
	int size;
	
	cin >> size;

	int heap[size * 2 + 1];
	for (int i = 0; i < size*2 + 1; i++) {
		heap[i] = INT_MIN;
	}

	for (int i = 1; i <= size; i++) {
		cin >> heap[i];
	}
	buildHeap(heap, size);
	printArr(heap, size);
	size = removeTop(heap, size);
	printArr(heap, size);
}
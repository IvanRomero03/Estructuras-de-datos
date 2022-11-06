#ifndef _HEAPSORT_H
#define _HEAPSORT_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class HeapSort
{
private:
    std::vector<T> list;
    
public:
    HeapSort();
    ~HeapSort();
	void heapify(T arr[], int N, int i);
    void heapSort(T arr[], int N);
	void printArray(T arr[], int N);
};

template <typename T>
HeapSort<T>::HeapSort()
{
}

template <typename T>
HeapSort<T>::~HeapSort()
{
}


// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
template <typename T>
void HeapSort<T>::heapify(T arr[], int N, int i)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
template <typename T>
void HeapSort<T>::heapSort(T arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
template <typename T>
void HeapSort<T>::printArray(T arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

#endif //HEAPSORT
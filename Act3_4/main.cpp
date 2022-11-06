// g++ -std=c++17 -Wall -O3 -o main *.cpp

#include <iostream> 
#include "HeapSort.h"

int main()
{

	// Function call
	std::string line;
	getline(cin, line);
	int n = line.find(":");
	HeapSort<int> hs;
	hs.heapSort(arr, n);
	hs.printArray(arr, n);

	return 0
}
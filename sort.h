#ifndef __SORT__
#define __SORT__

#include "RecursionCounter.h"
class Sort
{
public:
	// constructor
	Sort(int a_Size);
	~Sort();

	

	void InitArray();

	void SelectionSort();
	void InsertionSort();
	void AlgorithmSort();
	void MergeSort();
	void QuickSort();

	int GetSize() const;
	int* GetDataArray() const;
private:
	// add code here
	int* myList;
	int a_Size;
	void Merge(int i, int j, int k);
	int Partition(int i, int k);
	void MergeSortRecursionHelper(int initialLowIndex, int initialHighIndex);
	void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
};

#endif


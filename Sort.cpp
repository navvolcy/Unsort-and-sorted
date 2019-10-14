#include <random>
#include <algorithm>
#include "Sort.h"



void Sort::MergeSort()
{
	MergeSortRecursionHelper(0, a_Size - 1);
}
void Sort::MergeSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
	if (initialLowIndex >= initialHighIndex) {
		return;
	}
	int pas = (initialHighIndex + initialLowIndex) / 2;
	MergeSortRecursionHelper(initialLowIndex, pas);
	MergeSortRecursionHelper(pas + 1, initialHighIndex);
	Merge(initialLowIndex, pas ,initialHighIndex);


}
void Sort::Merge(int i, int j, int k) {
	
	int m_Size = k - i + 1;              // Size of merged partition
	int mergePos = 0;                          // Position to insert merged number
	int left_P = 0;                          // Position of elements in left partition
	int right_P = 0;                         // Position of elements in right partition
	int* mergedList;
	mergedList = new int[m_Size];   // Dynamically allocates temporary array
											  // for merged list

	left_P = i;                           // Initialize left partition position
	right_P = j + 1;                     // Initialize right partition position

	// Add smallest element from left or right partition to merged Lists
	while (left_P <= j && right_P <= k) {
		if (myList[left_P] <= myList[right_P]) {
			mergedList[mergePos] = myList[left_P];
			++left_P;
		}
		else {
			mergedList[mergePos] = myList[right_P];
			++right_P;

		}
		++mergePos;
	}

	// If left partition is not empty, add remaining elements to merged Lists
	while (left_P <= j) {
		mergedList[mergePos] = myList[left_P];
		++left_P;
		++mergePos;
	}

	// If right partition is not empty, add remaining elements to merged List
	while (right_P <= k) {
		mergedList[mergePos] = myList[right_P];
		++right_P;
		++mergePos;
	}

	// Copy merge number back to myList
	for (mergePos = 0; mergePos < m_Size; ++mergePos) {
		myList[i + mergePos] = mergedList[mergePos];
	}

	

}

void Sort::QuickSort()
{
	QuickSortRecursionHelper(0, a_Size - 1);
}

void Sort::QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
	if (initialLowIndex >= initialHighIndex) {
		
		return;
    }
	int par = Partition(initialLowIndex, initialHighIndex);
	QuickSortRecursionHelper(initialLowIndex, par);
	QuickSortRecursionHelper(par + 1, initialHighIndex);

}
int Sort::Partition(int i, int k)
{
	// initailizing variables & picking middles values as pivot
	int mid_point = i + (k - i) / 2;
	int pivot = myList[mid_point];


	bool done = false;
	int temp = 0;
	int l = i;
	int h = k;
	while (!done) {
		/* Increment l while myList[l] < pivot */
		while (myList[l] < pivot) {
			++l;
		}

		/* Decrement h while pivot < mylist[h] */
		while (pivot < myList[h]) {
			--h;
		}
		/* If there are zero or one items remaining,
		 all numbers are partitioned. Return h */
		if (l >= h) {
			done = true;
		}
		else {
			/* Swap myList[l] and myList[h],
			   update l and h */
			temp = myList[l];
			myList[l] = myList[h];
			myList[h] = temp;

			++l;
			--h;
		}
	}
	return h;
}

Sort::Sort(int a_Size)
{
	this->a_Size = a_Size;
	myList = new int[a_Size];
	InitArray();
}

Sort::~Sort()
{
	delete[] myList;
}
// initialize the array with random integers
void Sort::InitArray()
{
	//use the same seed before each array initialization, so the array is always the same
	srand(0);
	for (int i = 0; i < a_Size; i++)
	{
		myList[i] = rand();
	}
}
//Selection Sort of the array data
void Sort::SelectionSort()
{
	for (int i = 0; i < a_Size - 1; ++i) {

		// Find index of smallest remaining element
		int small_index = i;
			for (int j = i + 1; j < a_Size; ++j) {

				if (myList[j] < myList[small_index]) {
					small_index = j;
				}
			}

		// Swap myList[i] and myList[small_index]
			int temp = myList[i];
			myList[i] = myList[small_index];
			myList[small_index] = temp;
	}

}
//Insertion Sort of the array data
void Sort::InsertionSort()
{
	for (int i = 1; i < a_Size; ++i) {
		int j = i;
			// Insert myList[i] into sorted part 
			// stopping once myList[i] in correct position
			while (j > 0 && myList[j] < myList[j - 1]) {

				// Swap Mylist[j] and MyList[j - 1]
				int temp = myList[j];
				myList[j] = myList[j - 1];
				myList[j - 1] = temp;
				--j;
			}
	}

}

//get the size of the array
int Sort::GetSize() const
{
	return a_Size;
}
//return the array of integers
int* Sort::GetDataArray() const
{
	return myList;
}
// std::sort() (should be one line of code)
void Sort::AlgorithmSort()
{
	std::sort(myList, myList + a_Size - 1);
}

/********************************************************************************************
**	Project: Sort
**  Programmer: Nav L' Volcy
**  Course:		cs2420
**	Section:	001
**	Assignment: 5
**	Data:		Sept 29, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include "Sort.h"
#include "Timer.h"

using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main() {

	int size = 50;
	Sort mySort(size);
	Timer t;

	cout << "starting SelectionSort" << endl;
	mySort.InitArray();
	t.Start();
	mySort.SelectionSort();
	t.End();
	cout << "SelectionSort duration: " << t.DurationInMicroSeconds() << "ms." << endl << endl;

	cout << "starting InsertionSort" << endl;
	mySort.InitArray();
	t.Start();
	mySort.InsertionSort();
	t.End();
	cout << "InsertionSort duration: " << t.DurationInMicroSeconds() << "ms." << endl << endl;

	cout << "starting MergeSort" << endl;
	mySort.InitArray();
	t.Start();
	mySort.MergeSort();
	t.End();
	cout << "MergeSort duration: " << t.DurationInMicroSeconds() << "ms." << endl << endl;

	cout << "starting QuickSort" << endl;
	mySort.InitArray();
	t.Start();
	mySort.QuickSort();
	t.End();
	cout << "QuickSort duration: " << t.DurationInMicroSeconds() << "ms." << endl << endl;

	cout << "starting std::sort()" << endl;
	mySort.InitArray();
	t.Start();
	mySort.AlgorithmSort();
	t.End();
	cout << "std::sort() duration of: " << t.DurationInMicroSeconds() << "ms." << endl;







	

	




	
}

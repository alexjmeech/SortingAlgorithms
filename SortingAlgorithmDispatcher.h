#ifndef SORTINGALGORITHMDISPATCHER_H_
#define SORTINGALGORITHMDISPATCHER_H_

#include <string>
using namespace std;

enum SortingAlgorithmType
{
	BUBBLE,
	MERGE,
	INSERTION,
	END_SORTS
};

typedef void(*AlgorithmFunction)(int*, unsigned long);

class SortingAlgorithmDispatcher
{
private:
	static void BubbleSort(int*, unsigned long);
	static void MergeSort(int*, unsigned long);
	static void InsertionSort(int*, unsigned long);
public:
	static AlgorithmFunction getAlgorithm(SortingAlgorithmType);
	static string getAlgorithmName(SortingAlgorithmType);
};

#endif /* SORTINGALGORITHMDISPATCHER_H_ */

#include "SortingAlgorithmDispatcher.h"
#include <cstring>

void SortingAlgorithmDispatcher::BubbleSort(int* data, unsigned long total)
{
	bool swapped;

	do
	{
		swapped = false;

		for (unsigned long i = 0; i < total; i++)
		{
			if (i + 1 == total)
			{
				break;
			}

			if (data[i + 1] < data[i])
			{
				int hold = data[i];
				data[i] = data[i + 1];
				data[i + 1] = hold;

				swapped = true;
			}
		}
	}
	while (swapped);
}

void SortingAlgorithmDispatcher::InsertionSort(int* data, unsigned long total)
{
	for (unsigned long i = 1; i < total; i++)
	{
		for (unsigned long j = i; j > 0; j--)
		{
			if (data[j - 1] > data[j])
			{
				int hold = data[j];
				data[j] = data[j - 1];
				data[j - 1] = hold;
			}
		}
	}
}

void MergeSubArrays(int* data, unsigned long left, unsigned long mid, unsigned long right, unsigned long end)
{
	unsigned long leftTotal = right - left;
	unsigned long rightTotal = end - mid;

	int* leftSub = new int[leftTotal];
	int* rightSub = new int[rightTotal];

	memcpy(leftSub, data + left, sizeof(int) * leftTotal);
	memcpy(rightSub, data + right, sizeof(int) * rightTotal);

	unsigned long leftSubIndex = 0;
	unsigned long rightSubIndex = 0;

	while (leftSubIndex < leftTotal && rightSubIndex < rightTotal)
	{
		if (leftSub[leftSubIndex] < rightSub[rightSubIndex])
		{
			data[left++] = leftSub[leftSubIndex++];
		}
		else
		{
			data[left++] = rightSub[rightSubIndex++];
		}
	}

	if (leftSubIndex < leftTotal)
	{
		memcpy(data + left, leftSub + leftSubIndex, sizeof(int) * (leftTotal - leftSubIndex));
		left += (leftTotal - leftSubIndex);
	}

	if (rightSubIndex < rightTotal)
	{
		memcpy(data + left, rightSub + rightSubIndex, sizeof(int) * (rightTotal - rightSubIndex));
		left += (rightTotal - rightSubIndex);
	}

	delete[] leftSub;
	delete[] rightSub;
}

void MergeSortRecursive(int* data, int left, int end)
{
	if (left < end)
	{
		int mid = left + (end - left) / 2;
		int right = mid + 1;

		MergeSortRecursive(data, left, mid);
		MergeSortRecursive(data, right, end);

		MergeSubArrays(data, left, mid, right, end);
	}
}

void SortingAlgorithmDispatcher::MergeSort(int* data, unsigned long total)
{
	MergeSortRecursive(data, 0, total - 1);
}

AlgorithmFunction SortingAlgorithmDispatcher::getAlgorithm(SortingAlgorithmType type)
{
	switch (type)
	{
		case BUBBLE:
			return &(SortingAlgorithmDispatcher::BubbleSort);
		case MERGE:
			return &(SortingAlgorithmDispatcher::MergeSort);
		case INSERTION:
			return &(SortingAlgorithmDispatcher::InsertionSort);
		default:
			return nullptr;
	}
}

string SortingAlgorithmDispatcher::getAlgorithmName(SortingAlgorithmType type)
{
	switch (type)
	{
		case BUBBLE:
			return "BubbleSort";
		case MERGE:
			return "MergeSort";
		case INSERTION:
			return "InsertionSort";
		default:
			return "NoSort";
	}
}

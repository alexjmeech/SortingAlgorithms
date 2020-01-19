#ifndef SORT_H_
#define SORT_H_

#include "Algorithm.h"
#include "SortingAlgorithmDispatcher.h"

class Sort : public Algorithm
{
private:
	string fileName;
	int* data;
	unsigned long totalData;

	string algorithmName;
	void(*algorithm)(int*, unsigned long) = nullptr;

	long executionTime = -1;
public:
	virtual void Load(string);
	virtual void Execute();
	virtual void Display();
	virtual void Stats();
	virtual void Select(int);
	virtual void Save();
	virtual void Configure();
};

#endif /* SORT_H_ */

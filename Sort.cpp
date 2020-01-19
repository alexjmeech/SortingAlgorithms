#include "Sort.h"
#include "SortingAlgorithmDispatcher.h"
#include "FileIOUtil.hpp"
#include <iostream>
#include <chrono>

void Sort::Load(string fileName)
{
	this->fileName = fileName;

	if (this->data != nullptr)
	{
		delete[] data;
		this->data = nullptr;
		this->totalData = 0;
	}

	FileIOUtil<int>::readData("input/", fileName, this->data, this->totalData);
}

void Sort::Execute()
{
	if (this->algorithm == nullptr)
	{
		return;
	}

	auto start = std::chrono::high_resolution_clock::now();
	(*algorithm)(this->data, this->totalData);
	auto end = std::chrono::high_resolution_clock::now();

	this->executionTime = (end - start).count();
}

void Sort::Display()
{
	for (unsigned long i = 0; i < this->totalData; i++)
	{
		cout << this->data[i] << '\n';
	}

	cout.flush();
}

void Sort::Stats()
{
	if (this->algorithm == nullptr || this->executionTime == -1)
	{
		return;
	}

	cout << "Algorithm: " << this->algorithmName << endl;
	cout << "File Name: " << this->fileName << endl;
	cout << "Number of Records: " << this->totalData << endl;
	cout << "Execution Time: " << this->executionTime << " nanoseconds" << endl;
}

void Sort::Select(int algorithm)
{
	if (algorithm < 0 || algorithm >= SortingAlgorithmType::END_SORTS)
	{
		return;
	}

	this->algorithmName = SortingAlgorithmDispatcher::getAlgorithmName((SortingAlgorithmType)algorithm);
	this->algorithm = SortingAlgorithmDispatcher::getAlgorithm((SortingAlgorithmType)algorithm);
	this->executionTime = -1;
}

void Sort::Save()
{
	if (this->data == nullptr || this->totalData == 0 || this->executionTime == -1)
	{
		return;
	}

	FileIOUtil<int>::writeData("output/", this->algorithmName + "_" + this->fileName, this->data, this->totalData);
	delete[] data;
	this->data = nullptr;
	this->totalData = 0;
	this->executionTime = -1;
}

void Sort::Configure() {}

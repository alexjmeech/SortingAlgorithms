#include "Sort.h"
#include "SortingAlgorithmDispatcher.h"
#include "FileIOUtil.hpp"
#include "DataGenerator.h"
#include <iostream>

int main(int argv, char** argc)
{
	if (argv > 1)
	{
		cout << "GENERATING DATA" << endl;

		DataGenerator::generateRandom(10);
		DataGenerator::generateRandom(1000);
		DataGenerator::generateRandom(10000);
		DataGenerator::generateRandom(100000);

		DataGenerator::generateReversed(10);
		DataGenerator::generateReversed(1000);
		DataGenerator::generateReversed(10000);
		DataGenerator::generateReversed(100000);

		DataGenerator::generate20(10);
		DataGenerator::generate20(1000);
		DataGenerator::generate20(10000);
		DataGenerator::generate20(100000);

		DataGenerator::generate30(10);
		DataGenerator::generate30(1000);
		DataGenerator::generate30(10000);
		DataGenerator::generate30(100000);

		cout << "GENERATED DATA" << endl;
	}
	else
	{
		list<string> files = FileIOUtil<int>::listFiles("input/", ".txt");

		Algorithm* a = new Sort();

		for (int i = SortingAlgorithmType::BUBBLE; i < SortingAlgorithmType::END_SORTS; i++)
		{
			a->Select(i);

			for (string& file : files)
			{
				a->Load(file);
				a->Execute();
				a->Stats();
				a->Save();
				cout << endl;
			}
		}
	}

	return 0;
}

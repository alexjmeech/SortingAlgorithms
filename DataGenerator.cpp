#include "DataGenerator.h"
#include "FileIOUtil.hpp"
#include <stdlib.h>
#include <time.h>
using namespace std;

string DataGenerator::getFileName(string type, unsigned long total)
{
	string fileName = type + "_" + to_string(total) + ".txt";

	return fileName;
}

void DataGenerator::generateRandom(unsigned long total)
{
	srand(time(NULL));

	int* data = new int[total];

	for (unsigned long i = 0; i < total; i++)
	{
		data[i] = rand() % 27431;
	}

	FileIOUtil<int>::writeData("input/", getFileName("random", total), data, total);
}

void DataGenerator::generateReversed(unsigned long total)
{
	srand(time(NULL));

	int* data = new int[total];
	int r = 5939 + (rand() % 27431 + 1);

	for (unsigned long i = 0; i < total; i++)
	{
		data[i] = r--;
	}

	FileIOUtil<int>::writeData("input/", getFileName("reversed", total), data, total);
}

void DataGenerator::generate20(unsigned long total)
{
	srand(time(NULL));

	int* data = new int[total];

	unsigned long max = .20 * total;

	int v = 143;

	for (unsigned long i = 0; i < max; i++)
	{
		data[i] = v;

		if (v < 0)
		{
			v = (v * -1) + 5;
		}
		else
		{
			v = (v + 3) * -1;
		}
	}

	for (unsigned long i = max; i < total; i++)
	{
		data[i] = data[rand() % max];
	}

	FileIOUtil<int>::writeData("input/", getFileName("20pct", total), data, total);
}

void DataGenerator::generate30(unsigned long total)
{
	srand(time(NULL));

	int* data = new int[total];

	unsigned long max = .30 * total;

	int last = 0;

	for (unsigned long i = 0; i < max; i++)
	{
		last = rand() % 27431 + 1;
		data[i] = last;
	}

	last /= 2;

	for (unsigned long i = max; i < total; i++)
	{
		data[i] = last;
		last += 15;
	}

	FileIOUtil<int>::writeData("input/", getFileName("30pct", total), data, total);
}

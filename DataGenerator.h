#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <string>
using namespace std;

class DataGenerator
{
private:
	static string getFileName(string, unsigned long);
public:
	static void generateRandom(unsigned long);
	static void generateReversed(unsigned long);
	static void generate20(unsigned long);
	static void generate30(unsigned long);
};

#endif /* DATAGENERATOR_H_ */

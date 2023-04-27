#include "header.h"

int main()
{
	std::cout << "threadDemo v0.0.0" << std::endl;

	unsigned int threadCount = std::thread::hardware_concurrency();
	std::cout << "Supported threads: " << threadCount << std::endl;
	start();

	system("pause");
}
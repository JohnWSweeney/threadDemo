#include "header.h"
#include <atomic>
#include <thread>
#include <Windows.h>

extern std::atomic<bool> testThreadStatus;
extern std::atomic<bool> counterThreadStatus;

void supportedThreads()
{
	unsigned int threadCount = std::thread::hardware_concurrency();
	std::cout << "Supported threads: " << threadCount << std::endl;
}

void test()
{
	std::cout << "testThread started." << std::endl;
	while (testThreadStatus) {}
	std::cout << "testThread stopped." << std::endl;
}

void counter(int j)
{
	std::cout << "counterThread started." << std::endl;
	int i = 0;
	while (counterThreadStatus) {
		if (i < j)
		{
			std::cout << i << std::endl;
			++i;
			Sleep(5000);
		}
	}
	std::cout << "counterThread stopped." << std::endl;
}
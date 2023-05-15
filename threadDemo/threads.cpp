#include "threadDemo.h"
#include <atomic>
#include <thread>
#include <Windows.h>

extern std::atomic<bool> testThreadStatus;
extern std::atomic<bool> counterThreadStatus;

void test()
{
	// Dummy thread.
	std::cout << "testThread started." << std::endl;
	while (testThreadStatus) {/* do nothing. */ }
	std::cout << "testThread stopped." << std::endl;
}

void counter(int j)
{
	// Thread counting up to a user-specified number.
	std::cout << "counterThread started." << std::endl;
	int i = 0;
	while (counterThreadStatus && i < j)
	{
		std::cout << i << std::endl;
		++i;
		Sleep(5000);
	}
	std::cout << "counterThread stopped." << std::endl;
}
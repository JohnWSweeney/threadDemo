#include "header.h"

extern std::atomic<bool> testThreadStatus;

void testThread()
{
	std::cout << "testThread started." << std::endl;
	while (testThreadStatus) {}
	std::cout << "testThread stopped." << std::endl;
}
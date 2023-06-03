#include "functions.h"
#include "atomicBool.h"

void dummy()
{
	// Dummy thread.
	std::cout << "dummyThread started.\n";
	std::cout << "hello, world\n";
	while (testThreadStatus) {/* do nothing. */}
	std::cout << "dummyThread stopped.\n";
}

void counter(int counterMAX)
{
	// Thread counting up to a user-specified number.
	std::cout << "counterThread started.\n";
	int i = 0;
	while (counterThreadStatus && i < counterMAX)
	{
		std::cout << i << '\n';
		++i;
		Sleep(5000);
	}
	counterThreadStatus = false;
	std::cout << "counterThread stopped.\n";
}
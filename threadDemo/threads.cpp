#include "threads.h"
#include "functions.h"
#include "atomicBool.h"

void supportedThreads()
{
	// Return the MAX number of threads supported on user's computer.
	unsigned int threadCount = std::thread::hardware_concurrency();
	std::cout << "Supported threads: " << threadCount << '\n';
}

void startDummyThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "start")
	{
		testThreadStatus = true;
		std::thread testThread(dummy);
		testThread.detach();
	}
	else if (tokens[1] == "stop")
	{
		testThreadStatus = false;
	}
	else
	{
		std::cout << "Invalid command. Try again." << '\n';
	}
}

void startCounterThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "start")
	{
		try {
			int counterMAX = std::stoi(tokens[2]);
			counterThreadStatus = true;
			std::thread counterThread(counter, counterMAX);
			counterThread.detach();
		}
		catch (std::invalid_argument)
		{
			std::cout << "Counter limit is not a number. Try again.\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "Counter limit is out of range. Try again.\n	";
		}
	}
	else if (tokens[1] == "stop")
	{
		counterThreadStatus = false;
	}
	else
	{
		std::cout << "Invalid command. Try again." << '\n';
	}
}
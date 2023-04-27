#include "header.h"

std::atomic<bool> testThreadStatus;

void threadCount()
{
	unsigned int threadCount = std::thread::hardware_concurrency();
	std::cout << "Supported threads: " << threadCount << std::endl;
}

void start()
{
	threadCount();
	std::string input;
	bool running = true;
	while (running)
	{
		std::getline(std::cin, input);
		while (input != "start" && input != "stop"
			&& input != "exit")
		{
			std::cin.clear();
			std::cout << "Invalid input. Try again." << std::endl;
			std::getline(std::cin, input);
		}
		if (input == "start")
		{
			testThreadStatus = true;
			std::thread makeThread(testThread);
			makeThread.detach();
		}
		else if (input == "stop")
		{
			testThreadStatus = false;
		}
		else if(input == "exit")
		{
			testThreadStatus = false;
			running = false;
		}
	}
}
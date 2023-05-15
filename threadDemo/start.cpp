#include "threadDemo.h"
#include <string>
#include <sstream>
#include <atomic>
#include <thread>
#include <Windows.h>

std::atomic<bool> testThreadStatus;
std::atomic<bool> counterThreadStatus;

void supportedThreads()
{
	// Return the MAX number of threads supported on user's computer.
	unsigned int threadCount = std::thread::hardware_concurrency();
	std::cout << "Supported threads: " << threadCount << std::endl;
}

void getInput(std::vector<std::string> &tokens)
{
	// Copy each word in user input to vector (tokenize).
	do{
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void selectThread(bool &running, std::vector<std::string> &tokens)
{
	// Start thread running dummy "test" thread, with no parameters.
	if (tokens[0] == "test")
	{
		if (tokens[1] == "start")
		{
			testThreadStatus = true;
			std::thread testThread(test);
			testThread.detach();
		}
		else if (tokens[1] == "stop")
		{
			testThreadStatus = false;
		}
		else
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
	}
	// Start thread running "counter" function with int parameter.
	else if (tokens[0] == "counter")
	{
		if (tokens[1] == "start")
		{
			try {
				int j = std::stoi(tokens[2]);
				counterThreadStatus = true;
				std::thread counterThread(counter, j);
				counterThread.detach();
				//throw exception_code;
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
			std::cout << "Invalid command. Try again." << std::endl;
		}
	}
	// Terminate all threads and program.
	else if (tokens[0] == "exit")
	{
		testThreadStatus = false;
		counterThreadStatus = false;
		running = false;
		Sleep(1000);
	}
	// Reject all other inputs.
	else
	{
		std::cout << "Invalid command. Try again." << std::endl;
	}
	tokens.clear();
}
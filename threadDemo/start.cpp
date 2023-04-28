#include "header.h"
#include <string>
#include <sstream>
#include <atomic>
#include <thread>
#include <Windows.h>

std::atomic<bool> testThreadStatus;
std::atomic<bool> counterThreadStatus;

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
			std::cout << "Invalid input. Try again." << std::endl;
		}
	}
	// Start thread running "counter" function with int parameter.
	else if (tokens[0] == "counter")
	{
		if (tokens[1] == "start")
		{
			int j = std::stoi(tokens[2]);
			counterThreadStatus = true;
			std::thread counterThread(counter, j);
			counterThread.detach();
		}
		else if (tokens[1] == "stop")
		{
			counterThreadStatus = false;
		}
		else
		{
			std::cout << "Invalid input. Try again." << std::endl;
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
		std::cout << "Invalid input. Try again." << std::endl;
	}
	tokens.clear();
}

void start()
{
	supportedThreads();
	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		selectThread(running, tokens);
	}
}
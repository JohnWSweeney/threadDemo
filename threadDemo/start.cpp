#include "start.h"
#include "threads.h"
#include "atomicBool.h"

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

void startMenu(bool &running, std::vector<std::string> &tokens)
{
	// Start thread running dummy "test" thread, with no parameters.
	if (tokens[0] == "dummy")
	{
		startDummyThread(tokens);
	}
	// Start thread running "counter" function with int parameter.
	else if (tokens[0] == "counter")
	{
		startCounterThread(tokens);
	}
	// Stop all active threads.
	else if (tokens[0] == "stop")
	{
		if (tokens[1] == "all")
		{
			testThreadStatus = false;
			counterThreadStatus = false;
			std::cout << "All threads stopped.\n";
		}
		else
		{
			std::cout << "Invalid command. Try again.\n";
		}
	}
	// Terminate all threads and program.
	else if (tokens[0] == "exit")
	{
		testThreadStatus = false;
		counterThreadStatus = false;
		running = false;
		Sleep(1500);
	}
	// Reject all other inputs.
	else
	{
		std::cout << "Invalid command. Try again.\n";
	}
	tokens.clear();
}
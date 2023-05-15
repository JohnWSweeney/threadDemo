#include "threadDemo.h"

int main()
{
	std::cout << "threadDemo v1.1.1" << std::endl;
	supportedThreads();
	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		selectThread(running, tokens);
	}
}
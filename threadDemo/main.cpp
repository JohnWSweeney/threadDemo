#include "start.h"
#include "threads.h"

int main()
{
	std::cout << "threadDemo v1.1.2\n\n";
	supportedThreads();
	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		startMenu(running, tokens);
	}
}
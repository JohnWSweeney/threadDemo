#include "header.h"

void start()
{
	std::string input;
	bool running = true;
	while (running)
	{
		std::getline(std::cin, input);
		while (input != "start" && input != "stop"
			&& input != "exit")
		{
			std::cin.clear();
			std::cout << "Try again dummy." << std::endl;
			std::getline(std::cin, input);
		}
	}
}
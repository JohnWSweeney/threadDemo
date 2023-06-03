#pragma once
#include <iostream>
#include <Windows.h>

struct data
{
	int x;
	float y;
	std::string z;
	bool w;
};

void dummy();
void counter(int counterMAX);
int test(int testInt, int delay, data &mydata);
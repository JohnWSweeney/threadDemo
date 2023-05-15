#pragma once
#include <iostream>
#include <vector>

// start.cpp
void supportedThreads();
void getInput(std::vector<std::string> &tokens);
void selectThread(bool &running, std::vector<std::string> &tokens);

// threads.cpp
void test();
void counter(int j);
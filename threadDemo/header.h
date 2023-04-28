#pragma once
#include <iostream>
#include <vector>

// start.cpp
void getInput(std::vector<std::string> &tokens);
void selectThread(bool &running, std::vector<std::string> &tokens);
void start();

// threads.cpp
void supportedThreads();
void test();
void counter(int j);
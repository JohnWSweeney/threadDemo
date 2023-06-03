#pragma once
#include <string>
#include <vector>
#include <thread>

void supportedThreads();
void startDummyThread(std::vector<std::string> &tokens);
void startCounterThread(std::vector<std::string> &tokens);
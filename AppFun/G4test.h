#pragma once
#include <fstream>
#include <string>

void makeG4testFile(std::ofstream &file, std::ofstream &judgefile);

extern "C" __declspec(dllexport) void g4testFileOutput();
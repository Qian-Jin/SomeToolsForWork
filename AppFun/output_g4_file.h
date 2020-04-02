#pragma once
#include <fstream>
#include <string>

extern "C" __declspec(dllexport) void output_g4_file();

void print_g4_file(std::ofstream& file, std::ofstream& judge_file);

std::string output_g4(int which, int line_number, double pos, int& flat, double radium, int& relative);

std::string output_g4_judge(int which, int line_number, double pos, int flat, bool choose);
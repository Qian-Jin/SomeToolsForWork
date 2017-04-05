#pragma once
#include <fstream>

struct circle_point
{
	double x;
	double y;
};

extern "C" __declspec(dllexport) void gcodecirclefileoutput(int curvetype);

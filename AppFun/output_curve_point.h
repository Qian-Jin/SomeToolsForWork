#pragma once
#include <fstream>
#include "curve_func.h"

extern "C" __declspec(dllexport) void output_curve_point_g1_file(int curve_type);

extern "C" __declspec(dllexport) double output_curve_point_value(double i, typ_xy_C typ, int curve_type);

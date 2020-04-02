#pragma once
#include <fstream>

struct circle_point
{
    double x;
    double y;
};

extern "C" __declspec(dllexport) void output_gcode_circle_file(int curve_type, int flat, int method);

circle_point get_circle_end_point(circle_point start_point);
circle_point get_circle_center_point(circle_point start_point, circle_point end_point);
circle_point get_random_center_point(circle_point start_point);
circle_point get_circle_end_point_by_angle(circle_point start_point, circle_point center_point, double turn_angle);
void output_circle_file(std::ofstream& file, int curve_type, int flat, int method);

#pragma once
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <corecrt_math_defines.h>

const double single_axis_factor = 12.3456;

const double x_factor = -2.7;
const double y_factor = 6.3;
const double z_factor = 2.333;
const double a_factor = 1.289;
const double b_factor = 3.412;
const double c_factor = 1.34;
const double p_factor = 4.347;
const double q_factor = 2.34;

const double g2_angle = 37.0 / 180.0 * M_PI;
const double chord_long = 25;
const double radius = 15;

const int32_t line_sum = 49;

struct point
{
    double x;
    double y;
};

extern "C" __declspec(dllexport) void output_blend_gcode_file();

void analyze_parameter(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, std::ofstream& judge_pass);

void output_g0_single_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode, int axis);
void output_g0_multiple_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode);

void output_g1_single_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode, int axis);
void output_g1_multiple_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode);

void output_g2_g3_single_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, std::ofstream& judge_pass, int code, int mode, int flat, int method);
void output_g2_g3_multiple_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, std::ofstream& judge_pass, int code, int mode, int flat, int method);

double get_single_line_value(int32_t line_number);
point get_center_point(point start_point, point end_point, double radius, int which_side);
point get_pass_point(point start_point, point end_point, double radius, int code, int which_side);

void output_pass_judge(std::ofstream& judge_pass, point pass_point, int32_t line_number);

void output_first_gcode_is_g0_file(int second_gcode, std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int relative);

void output_first_gcode_is_g1_file(int second_gcode, std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int relative);

void output_first_gcode_is_circle_file(int second_gcode, std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int relative, int code, int type);

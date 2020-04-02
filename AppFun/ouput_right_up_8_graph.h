#pragma once
#include <fstream>
#include <cmath>

struct base_pointer
{
    double x;
    double y;
};

double angle = 90;
double first_angle = 45;
double line_long = 5;
int32_t flat_global = 17;
const double m_code_factor = 10.2;

int m_code_type = 0;
int m_code_value = 0;

void output_g1(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q);
void output_g2_center(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double flat_i, double flat_j, int32_t t);
void output_g2_radius(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double r, int32_t t);
void output_g3_center(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double flat_i, double flat_j, int32_t t);
void output_g3_radius(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double r, int32_t t);

void output_mcode_judge(std::ofstream& file, int32_t line_number, int i);
void output_gcode_judge(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q);
void output_gcode_file(std::ofstream& file, std::ofstream& judge_file);

base_pointer get_circle_center_point(base_pointer start_point, base_pointer end_point);
base_pointer f_right_up_trapezium_8(int x);

extern "C" __declspec(dllexport) void output_right_up_8_graph_g_code_file();

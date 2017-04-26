#pragma once
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#using <System.Xml.dll>

struct base_pointer
{
	double x;
	double y;
};

double angle = 90;
double firstangle = 45;
double line_long = 5;
int32_t flat_global = 17;


void writeG1(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q);
void writeG2_center(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double flot_i, double flot_j, int32_t t);
void writeG2_radius(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double r, int32_t t);
void writeG3_center(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double flot_i, double flot_j, int32_t t);
void writeG3_radius(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double r, int32_t t);

void writeGcode_judge(std::ofstream &file, int32_t linume, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q);
void makeMixFile(std::ofstream &file, std::ofstream &judgefile);

base_pointer getCircleCenterPoint(base_pointer startpoint, base_pointer endpoint);
base_pointer f_rightup_trapezium_8(int x);

extern "C" __declspec(dllexport) void gCodeMixFileOutput();


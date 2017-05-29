#pragma once
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#using <System.Xml.dll>


const double singleAxisFactor = 12.3456;

const double x_factor = -2.7;
const double y_factor = 6.3;
const double z_factor = 2.333;
const double a_factor = 1.289;
const double b_factor = 3.412;
const double c_factor = 1.34;
const double p_factor = 4.347;
const double q_factor = 2.34;

const double G2angle = 37.0 / 180.0 * M_PI;
const double chordlong = 25;
const double radius = 15;

const int32_t linesum = 49;

struct point
{
	double x;
	double y;
};


extern "C" __declspec(dllexport) void makeGfile();

void makesomefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, std::ofstream &judgepass);

void makeG0singlefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode, int axis);
void makeG0multiplefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode);

void makeG1singlefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode, int axis);
void makeG1multiplefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode);

void makeG2G3singlefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, std::ofstream &judgepass,int code, int mode, int flat, int method);
void makeG2G3multiplefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, std::ofstream &judgepass, int code, int mode, int flat, int method);

double getSingleLineValue(int32_t linenum);
point getcenter(point startpoint, point endpoint, double radius, int whichside);
point getpasspoint(point startpoint, point endpoint, double radius, int code, int whichside);

void printpassjudge(std::ofstream &judgepass, point passpoint, int32_t linenum);

void makeFirstGcodeisG0file(int SecendGcode, std::ofstream & file, std::ofstream & judgefile, std::ofstream & judgefile_var, int relative);

void makeFirstGcodeisG1file(int SecendGcode, std::ofstream & file, std::ofstream & judgefile, std::ofstream & judgefile_var, int relative);

void makeFirstGcodeisCirclefile(int SecendGcode, std::ofstream & file, std::ofstream & judgefile, std::ofstream & judgefile_var, int relative, int code, int type);





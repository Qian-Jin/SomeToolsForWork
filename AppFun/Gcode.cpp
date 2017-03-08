
#include <fstream>
#include "GcodeFun.h"
#include "Gcode.h"


const double for_time = 100;
const double for_step = 1;


double outfunction(double i, typ_xy_C typ)
{
	switch (typ)
	{
	case X_C:
		return f_sin(i, X_C);
	case Y_C:
		return f_sin(i, Y_C);
	default:
		return -1;
	}

}

void outfilefunc_xy(std::ofstream &file)
{
	file.precision(10);
	auto linenum = 0;
	file << "N0 G52" << std::endl;
	for (double i = 0; i <= for_time; i = i + for_step)
	{
		linenum++;
		file << "N" << linenum << " ";
		file << "G1 ";
		file << "X" << outfunction(i, X_C) << " ";
		file << "Y" << outfunction(i, Y_C) << " ";
		if (linenum == 1)
		{
			file << "E5 E-5 F5" << std::endl;
		}
		else
		{
			file << std::endl;
		}
	}

}


void gcodefileoutput()
{
	std::ofstream outfile;
	outfile.open("E:\\TextOut\\G_code.txt",std::ios::out,std::ios::trunc);
	outfilefunc_xy(outfile);
	outfile.close();
}
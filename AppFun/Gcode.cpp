
#include <fstream>
#include "GcodeFun.h"
#include "Gcode.h"


const double for_time = 200;
const double for_step = 1;

//G1
double outfunction(double i, typ_xy_C typ, int curvetype)
{
	switch (curvetype)
	{
		case 0:
			switch (typ)
			{
				case X_C:
					return f_spline(i, X_C);
				case Y_C:
					return f_spline(i, Y_C);
				default:
					return -1;
			}
			break;
		case 1:
			switch (typ)
			{
				case X_C:
					return f_rightup_trapezium_8(i, X_C);
				case Y_C:
					return f_rightup_trapezium_8(i, Y_C);
				default:
					return -1;
			}
			break;
		case 2:			
			switch (typ)
			{
				case X_C:
					return f_Rose(i, X_C);
				case Y_C:
					return f_Rose(i, Y_C);
				default:
					return -1;
			}
			break;

		case 3:			
			switch (typ)
			{
				case X_C:
					return f_Lemniscate_of_Bernoulli(i, X_C);
				case Y_C:
					return f_Lemniscate_of_Bernoulli(i, Y_C);
				default:
					return -1;
			}
			break;

		case 4:			
			switch (typ)
			{
				case X_C:
					return f_cycloid(i, X_C);
				case Y_C:
					return f_cycloid(i, Y_C);
				default:
					return -1;
			}
			break;

		case 5:			
			switch (typ)
			{
				case X_C:
					return f_Folium_of_Descartes(i, X_C);
				case Y_C:
					return f_Folium_of_Descartes(i, Y_C);
				default:
					return -1;
			}
			break;

		case 6:			
			switch (typ)
			{
				case X_C:
					return f_Witch_of_Agnesi(i, X_C);
				case Y_C:
					return f_Witch_of_Agnesi(i, Y_C);
				default:
					return -1;
			}
			break;

		case 7:			
			switch (typ)
			{
				case X_C:
					return f_Archimedeanspiral(i, X_C);
				case Y_C:
					return f_Archimedeanspiral(i, Y_C);
				default:
					return -1;
			}
			break;

		case 8:			
			switch (typ)
			{
				case X_C:
					return f_sin(i, X_C);
				case Y_C:
					return f_sin(i, Y_C);
				default:
					return -1;
			}
			break;

		case 9:			
			switch (typ)
			{
				case X_C:
					return f_line(i, X_C);
				case Y_C:
					return f_line(i, Y_C);
				default:
					return -1;
			}
			break;

		case 10:			
			switch (typ)
			{
				case X_C:
					return f_ellipse(i, X_C);
				case Y_C:
					return f_ellipse(i, Y_C);
				default:
					return -1;
			}
			break;

		case 11:			
			switch (typ)
			{
				case X_C:
					return f_Reuleaux_Triangle(i, X_C);
				case Y_C:
					return f_Reuleaux_Triangle(i, Y_C);
				default:
					return -1;
			}
			break;

		case 12:			
			switch (typ)
			{
				case X_C:
					return f_Cardioid(i, X_C);
				case Y_C:
					return f_Cardioid(i, Y_C);
				default:
					return -1;
			}
			break;
		case 13:
			switch (typ)
			{
			case X_C:
				return f_Involute_of_a_circle(i, X_C);
			case Y_C:
				return f_Involute_of_a_circle(i, Y_C);
			default:
				return -1;
			}
			break;
		case 14:
			switch (typ)
			{
			case X_C:
				return f_Astroid(i, X_C);
			case Y_C:
				return f_Astroid(i, Y_C);
			default:
				return -1;
			}
			break;
		case 15:
			switch (typ)
			{
			case X_C:
				return f_Hypocycloid(i, X_C);
			case Y_C:
				return f_Hypocycloid(i, Y_C);
			default:
				return -1;
			}
			break;
		case 16:
			switch (typ)
			{
			case X_C:
				return f_Parabola(i, X_C);
			case Y_C:
				return f_Parabola(i, Y_C);
			default:
				return -1;
			}
			break;
		case 17:
			switch (typ)
			{
			case X_C:
				return f_Hyperbola(i, X_C);
			case Y_C:
				return f_Hyperbola(i, Y_C);
			default:
				return -1;
			}
			break;
		case 18:
			switch (typ)
			{
			case X_C:
				return f_Cubic_function(i, X_C);
			case Y_C:
				return f_Cubic_function(i, Y_C);
			default:
				return -1;
			}
			break;
		case 19:
			switch (typ)
			{
			case X_C:
				return f_Cissoid_of_Diocles(i, X_C);
			case Y_C:
				return f_Cissoid_of_Diocles(i, Y_C);
			default:
				return -1;
			}
			break;
		case 20:
			switch (typ)
			{
			case X_C:
				return f_Semicubical_parabola(i, X_C);
			case Y_C:
				return f_Semicubical_parabola(i, Y_C);
			default:
				return -1;
			}
			break;
		case 21:
			switch (typ)
			{
			case X_C:
				return f_Serpentine_curve(i, X_C);
			case Y_C:
				return f_Serpentine_curve(i, Y_C);
			default:
				return -1;
			}
			break;
		case 22:
			switch (typ)
			{
			case X_C:
				return f_Bicorn(i, X_C);
			case Y_C:
				return f_Bicorn(i, Y_C);
			default:
				return -1;
			}
			break;
	}

}

void outfilefunc_xy(std::ofstream &file, int curvetype)
{
	file.precision(10);
	auto linenum = 0;
	file << "N0 G52" << std::endl;
	for (double i = 0; i <= for_time; i = i + for_step)
	{
		linenum++;
		file << "N" << linenum << " ";
		file << "G1 ";
		file << "X" << outfunction(i, X_C, curvetype) << " ";
		file << "Y" << outfunction(i, Y_C, curvetype) << " ";
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

void gcodefileoutput(int curvetype)
{
	std::ofstream outfile;
	outfile.open("E:\\TextOut\\G_code.txt",std::ios::out,std::ios::trunc);
	outfilefunc_xy(outfile, curvetype);
	outfile.close();
}


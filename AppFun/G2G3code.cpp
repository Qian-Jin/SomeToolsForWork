#include "G2G3code.h"

const double for_time = 100;
const double for_step = 1;
//G2&G3

//得到园的末端点
circle_point getCircleEndPoint(circle_point startpoint)
{
	circle_point endpoint;
	double random = fmod(rand(),10)+1.0;
	endpoint.x = startpoint.x + random;
	endpoint.y = 10*sin(endpoint.x);
	return endpoint;
}

//得到园心点
circle_point getCircleCenterPoint(circle_point startpoint,circle_point endpoint)
{
	circle_point centerpoint;
	double random = fmod(rand(), 4.5) + 2.5;
	centerpoint.x = startpoint.x + random;
	centerpoint.y = (-(endpoint.x - startpoint.x) / (endpoint.y - startpoint.y))*(centerpoint.x - (startpoint.x + endpoint.x) / 2) + (startpoint.y + endpoint.y) / 2;
	return centerpoint;
}

void outcirclefilefunc_xy(std::ofstream &file, int curvetype)
{
	file.precision(10);
	auto linenum = 0;
	circle_point startpoint, centerpoint, endpoint;
	startpoint.x = 0;
	startpoint.y = 0;
	for (double i = 0; i <= for_time; i = i + for_step)
	{
		linenum++;
		endpoint = getCircleEndPoint(startpoint);
		centerpoint = getCircleCenterPoint(startpoint, endpoint);
		file << "N" << linenum << " ";
		if (curvetype == 0)
		{
			file << "G2 ";
		}
		else if (curvetype == 1)
		{
			file << "G3 ";
		}
		file << "X" << endpoint.x << " ";
		file << "Y" << endpoint.y << " ";
		file << "I" << centerpoint.x << " ";
		file << "J" << centerpoint.y << " ";
 		if (linenum == 1)
		{
			file << "E5 E-5 F5" << std::endl;
		}
		else
		{
			file << std::endl;
		}
		startpoint = endpoint;
	}
}



void gcodecirclefileoutput(int curvetype)
{
	std::ofstream outfile;
	outfile.open("E:\\TextOut\\G_code.txt", std::ios::out, std::ios::trunc);
	outcirclefilefunc_xy(outfile, curvetype);
	outfile.close();
}


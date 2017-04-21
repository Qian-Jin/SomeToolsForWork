#include "G2G3code.h"
#define _USE_MATH_DEFINES
#include <math.h>


const double for_time = 361;
const double for_step = 0.5;

//circleType 
//0:sin曲线随机取结束点，之后随机取圆心
//1:圆心在X轴上，半径固定
//2:向右上画弧
//3:画半径不同的圆
//4:根据给定角度画圆
const int circleType = 4;


//G2&G3

//得到圆的末端点
circle_point getCircleEndPoint(circle_point startpoint)
{
	circle_point endpoint;
	double offset;
	switch (circleType)
	{
	case 0:
		offset = fmod(rand(), 10) + 1.0;
		endpoint.x = startpoint.x + offset;
		endpoint.y = 10 * sin(endpoint.x);
		break;
	case 1:
		offset = 1.0 * 2;
		endpoint.x = startpoint.x + offset;
		endpoint.y = startpoint.y;
		break;
	case 2:
		endpoint.x = startpoint.x + 1.0;
		endpoint.y = sqrt(pow(startpoint.y,2)+pow(1.0,2));
		break;
	case 3:
		endpoint = startpoint;
		break;
	default:
		offset = fmod(rand(), 10) + 1.0;
		endpoint.x = startpoint.x + offset;
		endpoint.y = 10 * sin(endpoint.x);
		break;
	}
	return endpoint;
}

//得到园心点
circle_point getCircleCenterPoint(circle_point startpoint,circle_point endpoint)
{
	circle_point centerpoint;
	double offset;
	static int times = 0;

	times++;
	switch (circleType)
	{
	case 0:
		offset = fmod(rand(), 4.5) + 2.5;
		centerpoint.x = startpoint.x + offset;
		centerpoint.y = (-(endpoint.x - startpoint.x) / (endpoint.y - startpoint.y))*(centerpoint.x - (startpoint.x + endpoint.x) / 2) + (startpoint.y + endpoint.y) / 2;
		break;
	case 1:
		offset = (endpoint.x - startpoint.x)/2;
		centerpoint.x = startpoint.x + offset;
		centerpoint.y = startpoint.y;
		break;
	case 2:
		centerpoint.x = startpoint.x + 1.0;
		centerpoint.y = 0.0;
		break;
	case 3:
		centerpoint.x = startpoint.x + 0.5 * times;
		centerpoint.y = startpoint.y;
		break;
	default:
		offset = fmod(rand(), 4.5) + 2.5;
		centerpoint.x = startpoint.x + offset;
		centerpoint.y = (-(endpoint.x - startpoint.x) / (endpoint.y - startpoint.y))*(centerpoint.x - (startpoint.x + endpoint.x) / 2) + (startpoint.y + endpoint.y) / 2;
		break;
	}
	return centerpoint;
}




//根据起点产生圆心位置
circle_point getRandomCenterPoint(circle_point startpoint)
{
	circle_point centerpoint;
	double circleRadius = 1000.0;
	double angle = 0.0/180.0 * M_PI;
	centerpoint.x = startpoint.x + circleRadius * cos(angle);
	centerpoint.y = startpoint.y + circleRadius * sin(angle);
	return centerpoint;
}

//根据圆的起始点，圆心和转过角度计算结束点的位置
circle_point getCircleEndPointByAngle(circle_point startpoint, circle_point centerpoint, double turnangle)
{
	double startAndCenterPointAngle = atan2(startpoint.y - centerpoint.y, startpoint.x - centerpoint.x);
	double turnangleRoll = turnangle / 180.0 * M_PI;//转过的弧度值
	double vectorangle;//结束点的角度
	if (startAndCenterPointAngle <= M_PI && startAndCenterPointAngle >= 0)
	{
		if (startAndCenterPointAngle > turnangleRoll)
		{
			vectorangle = startAndCenterPointAngle - turnangleRoll;
		}
		else
		{
			vectorangle = -(turnangleRoll - startAndCenterPointAngle);
		}
	}
	else
	{
		if (startAndCenterPointAngle - turnangleRoll < -M_PI)
		{
			vectorangle = M_PI - (turnangleRoll - (startAndCenterPointAngle + M_PI));
		}
		else
		{
			vectorangle = startAndCenterPointAngle - turnangleRoll;
		}
	}

	double circleRadius = sqrt(pow(startpoint.x - centerpoint.x, 2) + pow(startpoint.y - centerpoint.y, 2));//半径
	circle_point endpoint;
	endpoint.x = centerpoint.x + circleRadius * cos(vectorangle);
	endpoint.y = centerpoint.y + circleRadius * sin(vectorangle);
	return endpoint;
}



void outcirclefilefunc_xy(std::ofstream &file, int curvetype, int flat, int method)
{
	std::ofstream judgefile;
	judgefile.open("E:\\TextOut\\G_code_posjudge.txt", std::ios::out, std::ios::trunc);

	judgefile.precision(10);
	file.precision(10);
	auto linenum = 0;
	circle_point startpoint, centerpoint, endpoint;
	startpoint.x = 0;
	startpoint.y = 0;
	for (double i = 0.5; i <= for_time; i = i + for_step)
	{
		linenum++;
		if (circleType==4)
		{

			//centerpoint = getRandomCenterPoint(startpoint);
			centerpoint.x = 100.0;
			centerpoint.y = 0.0;
			endpoint = getCircleEndPointByAngle(startpoint, centerpoint, i);
		}
		else
		{
			endpoint = getCircleEndPoint(startpoint);
			centerpoint = getCircleCenterPoint(startpoint, endpoint);
		}


		if (linenum == 1)
		{
			switch (flat)
			{
				case 0:
					file << "N0 G17" << std::endl;
					break;
				case 1:
					file << "N0 G18" << std::endl;
					break;
				case 2:
					file << "N0 G19" << std::endl;
					break;
				default:
					file << "N0 G17" << std::endl;
					break;
			}
			
		}
		else
		{
			;
		}

		file << "N" << linenum << " ";
		if (curvetype == 0)
		{
			file << "G2 ";
			endpoint.y = endpoint.y;
		}
		else if (curvetype == 1)
		{
			file << "G3 ";
			endpoint.y = -endpoint.y;
		}
		switch (flat)
		{
		case 0:
			file << "X" << endpoint.x << " ";
			file << "Y" << endpoint.y << " ";
			file << "Z" << linenum << " ";

			break;
		case 1:
			file << "Z" << endpoint.x << " ";
			file << "X" << endpoint.y << " ";
			file << "Y" << linenum << " ";

			break;
		case 2:
			file << "Y" << endpoint.x << " ";
			file << "Z" << endpoint.y << " ";
			file << "X" << linenum << " ";

			break;
		default:
			file << "X" << endpoint.x << " ";
			file << "Y" << endpoint.y << " ";
			file << "Z" << linenum << " ";

			break;
		}

		file << "A" << linenum << " ";
		file << "B" << linenum << " ";
		file << "C" << linenum << " ";
		file << "P" << linenum << " ";
		file << "Q" << linenum << " ";
		if (method ==0 )
		{
			switch (flat)
			{
			case 0:
				file << "I" << centerpoint.x - startpoint.x << " ";
				if (curvetype == 0)
				{
					file << "J" << centerpoint.y - startpoint.y << " ";
				}
				else if (curvetype == 1)
				{
					file << "J" << centerpoint.y + startpoint.y << " ";
				}
				break;
			case 1:
				file << "K" << centerpoint.x - startpoint.x << " ";
				if (curvetype == 0)
				{
					file << "I" << centerpoint.y - startpoint.y << " ";
				}
				else if (curvetype == 1)
				{
					file << "I" << centerpoint.y + startpoint.y << " ";
				}
				break;
			case 2:
				file << "J" << centerpoint.x - startpoint.x << " ";
				if (curvetype == 0)
				{
					file << "K" << centerpoint.y - startpoint.y << " ";
				}
				else if (curvetype == 1)
				{
					file << "K" << centerpoint.y + startpoint.y << " ";
				}
				break;
			default:
				file << "I" << centerpoint.x - startpoint.x << " ";
				if (curvetype == 0)
				{
					file << "J" << centerpoint.y - startpoint.y << " ";
				}
				else if (curvetype == 1)
				{
					file << "J" << centerpoint.y + startpoint.y << " ";
				}
				break;
			}
		}
		else if (method==1)
		{
			if (i <= 180.0)
			{
				file << "R100.0" << " ";
			}
			else
			{
				file << "R-100.0" << " ";
			}
		}
 		if (linenum == 1)
		{
			file << "E10 E-10 F10" << std::endl;
		}
		else
		{
			file << std::endl;
		}

		judgefile << "IF EDGEPOS(NC_Currentline = " << linenum+1 << ") THEN\n";
		switch (flat)
		{
		case 0:
			judgefile << "\t IF NOT ((ABS(Axis[1].cmdpos - (" << endpoint.x << ")) < 0.01) & (ABS(Axis[2].cmdpos - (" << endpoint.y << ")) < 0.01) & (ABS(Axis[3].cmdpos - (" << linenum;

			break;
		case 1:
			judgefile << "\t IF NOT ((ABS(Axis[3].cmdpos - (" << endpoint.x << ")) < 0.01) & (ABS(Axis[1].cmdpos - (" << endpoint.y << ")) < 0.01) & (ABS(Axis[2].cmdpos - (" << linenum;

			break;
		case 2:
			judgefile << "\t IF NOT ((ABS(Axis[2].cmdpos - (" << endpoint.x << ")) < 0.01) & (ABS(Axis[3].cmdpos - (" << endpoint.y << ")) < 0.01) & (ABS(Axis[1].cmdpos - (" << linenum;

			break;
		default:
			judgefile << "\t IF NOT ((ABS(Axis[1].cmdpos - (" << endpoint.x << ")) < 0.01) & (ABS(Axis[2].cmdpos - (" << endpoint.y << ")) < 0.01) & (ABS(Axis[3].cmdpos - (" << linenum;

			break;
		}
				
		judgefile << ")) < 0.01) & (ABS(Axis[4].cmdpos - " << linenum  << ") < 0.01) & (ABS(Axis[5].cmdpos - " << linenum  << ") < 0.01) & (ABS(Axis[6].cmdpos - " << linenum  << ") < 0.01) & (ABS(Axis[7].cmdpos - " << linenum << ") < 0.01) & (ABS(Axis[8].cmdpos - " << linenum << ") < 0.01)) THEN\n";
		judgefile << "\t\tError := TRUE;\n\t\tlineError := NC_Currentline;\n";
		judgefile << "\tEND_IF;\n";
		judgefile << "END_IF;\n";
		//judgefile << "IF (NC_Currentline = " << linenum << ") THEN\n";
		//judgefile << "\tdiff := judgeCircle(nowPointX := NC_X,nowPointY := NC_Y, startPointX:= " << startpoint.x << ", startPointY:= " << startpoint.y << ", centerPointX:= " << centerpoint.x  << ", centerPointY:= " << centerpoint.y << ");\n";
		//judgefile << "\tIF (diff > 0.1) THEN\n";
		//judgefile << "\t\tError_pos := TRUE;\n";
		//judgefile << "\t\tlineError_pos := NC_Currentline; \n";
		//judgefile << "\t\tdiff_pos := MAX(diff,diff_pos); \n";
		//judgefile << "\tEND_IF;\n";
		//judgefile << "END_IF;\n";

		if (curvetype == 0)
		{
			
			endpoint.y = endpoint.y;
		}
		else if (curvetype == 1)
		{
			
			endpoint.y = -endpoint.y;
		}
		startpoint = endpoint;
	}

	judgefile.close();

}



void gcodecirclefileoutput(int curvetype, int flat, int method)
{
	std::ofstream outfile;
	outfile.open("E:\\TextOut\\G_code.txt", std::ios::out, std::ios::trunc);
	outcirclefilefunc_xy(outfile, curvetype, flat, method);
	outfile.close();
}


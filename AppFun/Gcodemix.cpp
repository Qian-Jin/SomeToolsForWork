#include "Gcodemix.h"


void writeG1(std::ofstream &file,int32_t linenum, double x,double y,double z,double a,double b,double c,double p,double q)
{
	file << "N" << linenum << " G1 ";
	file << "X" << x << " ";
	file << "Y" << y << " ";
	file << "Z" << z << " ";
	file << "A" << a << " ";
	file << "B" << b << " ";
	file << "C" << c << " ";
	file << "P" << p << " ";
	file << "Q" << q << std::endl;

}

void writeG2_center(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q,double flot_i,double flot_j, int32_t t)
{
	switch (flot)
	{
	case 17:
		file << "N" << linenum << " G2 ";
		file << "X" << flot_x << " ";
		file << "Y" << flot_y << " ";
		file << "Z" << flot_z << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "I" << flot_i << " ";
		file << "J" << flot_j << " ";
		if (t<=0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}
		break;
	case 18:
		file << "N" << linenum << " G2 ";
		file << "X" << flot_y << " ";
		file << "Y" << flot_z << " ";
		file << "Z" << flot_x << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "I" << flot_j << " ";
		file << "K" << flot_i << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}
		break;
	case 19:
		file << "N" << linenum << " G2 ";
		file << "X" << flot_z << " ";
		file << "Y" << flot_x << " ";
		file << "Z" << flot_y << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "J" << flot_i << " ";
		file << "K" << flot_j << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}
		break;
	default:
		break;
	}
}

void writeG2_radius(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double r, int32_t t)
{
	switch (flot)
	{
	case 17:
		file << "N" << linenum << " G2 ";
		file << "X" << flot_x << " ";
		file << "Y" << flot_y << " ";
		file << "Z" << flot_z << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "R" << r << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	case 18:
		file << "N" << linenum << " G2 ";
		file << "X" << flot_y << " ";
		file << "Y" << flot_z << " ";
		file << "Z" << flot_x << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "R" << r << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	case 19:
		file << "N" << linenum << " G2 ";
		file << "X" << flot_z << " ";
		file << "Y" << flot_x << " ";
		file << "Z" << flot_y << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "R" << r << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	default:
		break;
	}
}

void writeG3_center(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double flot_i, double flot_j, int32_t t)
{
	switch (flot)
	{
	case 17:
		file << "N" << linenum << " G3 ";
		file << "X" << flot_x << " ";
		file << "Y" << flot_y << " ";
		file << "Z" << flot_z << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "I" << flot_i << " ";
		file << "J" << flot_j << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	case 18:
		file << "N" << linenum << " G3 ";
		file << "X" << flot_y << " ";
		file << "Y" << flot_z << " ";
		file << "Z" << flot_x << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "I" << flot_j << " ";
		file << "K" << flot_i << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	case 19:
		file << "N" << linenum << " G3 ";
		file << "X" << flot_z << " ";
		file << "Y" << flot_x << " ";
		file << "Z" << flot_y << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "J" << flot_i << " ";
		file << "K" << flot_j << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	default:
		break;
	}
}

void writeG3_radius(std::ofstream &file, int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q, double r, int32_t t)
{
	switch (flot)
	{
	case 17:
		file << "N" << linenum << " G3 ";
		file << "X" << flot_x << " ";
		file << "Y" << flot_y << " ";
		file << "Z" << flot_z << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "R" << r << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	case 18:
		file << "N" << linenum << " G3 ";
		file << "X" << flot_y << " ";
		file << "Y" << flot_z << " ";
		file << "Z" << flot_x << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "R" << r << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	case 19:
		file << "N" << linenum << " G3 ";
		file << "X" << flot_z << " ";
		file << "Y" << flot_x << " ";
		file << "Z" << flot_y << " ";
		file << "A" << a << " ";
		file << "B" << b << " ";
		file << "C" << c << " ";
		file << "P" << p << " ";
		file << "Q" << q << " ";
		file << "R" << r << " ";
		if (t <= 0)
		{
			file << std::endl;
		}
		else
		{
			file << "T" << t << std::endl;
		}

		break;
	default:
		break;
	}
}

void writeGcode_judge(std::ofstream &file,int32_t linume, int flot, double flot_x, double flot_y, double flot_z, double a, double b, double c, double p, double q)
{
	file << "IF EDGEPOS(NC_Currentline = " << linume << ") THEN\n";
	file << "\tIF NOT ((ABS(Axis[1].cmdpos - (";
	switch (flot)
	{
	case 17:
		file << flot_x;
		break;
	case 18:
		file << flot_y;
		break;
	case 19:
		file << flot_z;

		break;
	default:
		break;
	}
	file << ")) < 0.01) & (ABS(Axis[2].cmdpos - (";
	switch (flot)
	{
	case 17:
		file << flot_y;
		break;
	case 18:
		file << flot_z;
		break;
	case 19:
		file << flot_x;

		break;
	default:
		break;
	}
	file << ")) < 0.01) & (ABS(Axis[3].cmdpos - (";
	switch (flot)
	{
	case 17:
		file << flot_z;
		break;
	case 18:
		file << flot_x;
		break;
	case 19:
		file << flot_y;
		break;
	default:
		break;
	}
	file << ")) < 0.01) & (ABS(Axis[4].cmdpos - (";
	file << a;
	file << ")) < 0.01) & (ABS(Axis[5].cmdpos - (";
	file << b;
	file << ")) < 0.01) & (ABS(Axis[6].cmdpos - (";
	file << c;
	file << ")) < 0.01) & (ABS(Axis[7].cmdpos - (";
	file << p;
	file << ")) < 0.01) & (ABS(Axis[8].cmdpos - (";
	file << q;
	file << ")) < 0.01)) THEN\n";
	file << "\t\tError := TRUE;\n\t\tlineError := NC_Currentline;\n";
	file << "\tEND_IF;\n";
	file << "END_IF;" << std::endl;

}

void makeMixFile(std::ofstream &file, std::ofstream &judgefile)
{
	base_pointer startpoint;
	base_pointer endpoint;
	base_pointer centerpoint;
	startpoint.x = 0.0;
	startpoint.y = 0.0;

	

	file << "N0 G50\nN1 G" << flat_global << std::endl;
	file << "N2 G1 X0 Y0 Z0 A0 B0 C0 P0 Q0 E10 E-10 F10\n";

	int32_t linenum = 3;
	for (int32_t i = 0; i <=100;i++)
	{
		endpoint = f_rightup_trapezium_8(i);

		if ((endpoint.x < 1e-5) && (endpoint.x > -1e-5))
		{
			endpoint.x = 0.0;
		}
		if ((endpoint.y < 1e-5) && (endpoint.y > -1e-5))
		{
			endpoint.y = 0.0;
		}

		switch (i%8)
		{
		case 0:
			centerpoint = getCircleCenterPoint(startpoint, endpoint);
			writeG2_center(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i, centerpoint.x, centerpoint.y, i / 8);
			break;
		case 1:
			centerpoint = getCircleCenterPoint(startpoint, endpoint);
			writeG3_center(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i, centerpoint.x, centerpoint.y, i / 8);
			break;
		case 2:
			writeG2_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i, line_long + i, i / 8);
			break;
		case 3:
			writeG1(file, linenum, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 4:
			writeG3_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i, line_long + i, i / 8);
			break;
		case 5:
			writeG3_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i, -(line_long + i), i / 8);
			break;
		case 6:
			writeG1(file, linenum, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 7:
			writeG2_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i, -(line_long + i), i / 8);
			break;
		default:
			break;
		}
		writeGcode_judge(judgefile, linenum + 1, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
		linenum++;
		startpoint = endpoint;
	}
}



void gCodeMixFileOutput()
{
	System::Xml::XmlDocument^ doc = gcnew System::Xml::XmlDocument;
	doc->Load("E:\\TextOut\\G_code_Para.xml");

	System::Xml::XmlNode^ rootnode = doc->SelectSingleNode("Parameters");
	System::Xml::XmlNode^ linelong_node = rootnode->SelectSingleNode("LineLong");
	System::Xml::XmlNode^ firstangle_node = rootnode->SelectSingleNode("FirstAngle");
	System::Xml::XmlNode^ eachangle_node = rootnode->SelectSingleNode("EachAngle");
	System::Xml::XmlNode^ flat_node = rootnode->SelectSingleNode("Flat");

	
	char* linelong_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(linelong_node->ChildNodes[0]->InnerText);
	char* firstangle_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(firstangle_node->ChildNodes[0]->InnerText);
	char* eachangle_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(eachangle_node->ChildNodes[0]->InnerText);
	char* flat_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(flat_node->ChildNodes[0]->InnerText);

	line_long = atof(linelong_char);
	firstangle = atof(firstangle_char);
	angle = atof(eachangle_char);
	flat_global = atoi(flat_char);

	std::ofstream outfile , outfileJudge;
	outfile.open("E:\\TextOut\\G_code.txt", std::ios::out, std::ios::trunc);
	outfileJudge.open("E:\\TextOut\\G_code_posjudge.txt", std::ios::out, std::ios::trunc);
	outfile.precision(10);
	outfileJudge.precision(10);
	makeMixFile(outfile,outfileJudge);
	outfile.close();
	outfileJudge.close();
}

//得到园心点 返回一个在x轴上的圆心点
base_pointer getCircleCenterPoint(base_pointer startpoint, base_pointer endpoint)
{
	base_pointer centerpoint;
	double centerAbsoluteX = (-(startpoint.y + endpoint.y) / 2) / (-(endpoint.x - startpoint.x) / (endpoint.y - startpoint.y)) + (startpoint.x + endpoint.x) / 2;
	double centerAbsoluteY = 0.0;
	centerpoint.x = centerAbsoluteX - startpoint.x;
	centerpoint.y = centerAbsoluteY - startpoint.y;
 	return centerpoint;
}


base_pointer f_rightup_trapezium_8(int x)
{
	base_pointer pointer[4];
	base_pointer outpoint;
	if ((angle >= 90) && (angle <= 180))
	{
		if (angle == 180)
		{
			outpoint.x = line_long * (x + 1);
			outpoint.y = line_long * (x + 1);
		}
		else
		{
			pointer[0].x = line_long * cos(firstangle / 180 * M_PI);
			pointer[0].y = line_long * sin(firstangle / 180 * M_PI);
			auto secondline = line_long * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
			pointer[1].x = secondline * cos(((180 - angle) / 2 + firstangle) / 180 * M_PI);
			pointer[1].y = secondline * sin(((180 - angle) / 2 + firstangle) / 180 * M_PI);
			pointer[2].x = pointer[1].x + line_long * cos(firstangle / 180 * M_PI);
			pointer[2].y = pointer[1].y + line_long * sin(firstangle / 180 * M_PI);
			pointer[3].x = 2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI)) * cos(firstangle / 180 * M_PI);
			pointer[3].y = 2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI)) * sin(firstangle / 180 * M_PI);

			outpoint.x = pointer[x % 4].x + (x / 4) * (2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI))) * cos(firstangle / 180 * M_PI);
			outpoint.y = pointer[x % 4].y + (x / 4) * (2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI))) * sin(firstangle / 180 * M_PI);
		}
	}
	else
	{
		pointer[0].x = line_long * cos(firstangle / 180 * M_PI);
		pointer[0].y = line_long * sin(firstangle / 180 * M_PI);
		auto secondline = line_long * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
		pointer[1].x = secondline * cos((firstangle + (180 - angle) / 2) / 180 * M_PI);
		pointer[1].y = secondline * sin((firstangle + (180 - angle) / 2) / 180 * M_PI);
		pointer[2].x = pointer[1].x + line_long * cos(firstangle / 180 * M_PI);
		pointer[2].y = pointer[1].y + line_long * sin(firstangle / 180 * M_PI);
		auto forthline = secondline * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
		pointer[3].x = forthline * cos(firstangle / 180 * M_PI);
		pointer[3].y = forthline * sin(firstangle / 180 * M_PI);

		outpoint.x = pointer[x % 4].x + (x / 4) * forthline * cos(firstangle / 180 * M_PI);
		outpoint.y = pointer[x % 4].y + (x / 4) * forthline * sin(firstangle / 180 * M_PI);
	}
	return outpoint;
}
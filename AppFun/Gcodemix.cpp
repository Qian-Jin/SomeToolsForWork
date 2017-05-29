#include "Gcodemix.h"


void writeG1(std::ofstream &file,int32_t linenum, int flot, double flot_x, double flot_y, double flot_z, double a,double b,double c,double p,double q)
{
	//M代码只能放到后面
	//if (McodeType == 0)
	//{
	//	if (McodeValue == 0)
	//	{
	//		file << "N" << linenum << " M" << a << " D" << a*mCodeFactor << " G1 ";

	//	}
	//	else if (McodeValue == 1)
	//	{
	//		file << "N" << linenum << " M" << a <<  " G1 ";
	//	}
	//}
	//else if (McodeType == 1)
	//{
	//	file << "N" << linenum << " G1 ";
	//}

	
	file << "N" << linenum << " G1 ";
	
	switch (flot)
	{
	case 17:
		file << "X" << flot_x << " ";
		file << "Y" << flot_y << " ";
		file << "Z" << flot_z << " ";
		break;
	case 18:
		file << "X" << flot_y << " ";
		file << "Y" << flot_z << " ";
		file << "Z" << flot_x << " ";
		break;
	case 19:
		file << "X" << flot_z << " ";
		file << "Y" << flot_x << " ";
		file << "Z" << flot_y << " ";
		break;
	default:
		break;
	}

	file << "A" << a << " ";
	file << "B" << b << " ";
	file << "C" << c << " ";
	file << "P" << p << " ";
	file << "Q" << q << " ";
	if (McodeType == 0)
	{
		if (McodeValue == 0)
		{
			file << "M" << a << " D" << (a + 1)*mCodeFactor;

		}
		else if (McodeValue == 1)
		{
			file << "M" << a ;
		}
	}
	else if (McodeType == 1)
	{
		;
	}

	file << std::endl;

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
	file << "\tA:=0;\n";
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



void writeMcode_judge(std::ofstream &file,int32_t linenum,int i)
{
	if (McodeType == 0)
	{
		file << "IF (NC_Currentline = " << linenum << ") THEN\n";
	}
	else if (McodeType == 1)
	{
		file << "IF (NC_Currentline = " << linenum + 1 << ") THEN\n";
	}
	
//	file << "\tA:=0;\n";
	file << "\tA:=A+1;\n";
	file << "\tIF A=2 THEN\n";

	if (McodeValue == 0)
	{
		file << "\t\tIF (AxesGroup[1].M_Function[" << i << "] = 1) & (ABS(AxesGroup[1].M_Value[" << i << "] - " << (i + 1) * mCodeFactor << ")<1E-3 ) & (\n";
		if (McodeType == 0)
		{
			for (int j = i; j < 100; j++)
			{
				if (j == i)
				{
					;
				}
				else
				{
					file << "\t\t(AxesGroup[1].M_Function[" << j << "] = 0) & \n";
				}
			}
		}
		else if (McodeType == 1)
		{
			for (int j = 0; j < 100; j++)
			{
				if (j == i)
				{
					;
				}
				else
				{
					file << "\t\t(AxesGroup[1].M_Function[" << j << "] = 0) & \n";
				}
			}
		}
			
		file << "\t\tTRUE )THEN\n";
	}
	else if (McodeValue == 1)
	{
		file << "\t\tIF (AxesGroup[1].M_Function[" << i << "] = 1) & (\n";
		if (McodeType == 0)
		{
			for (int j = i; j < 100; j++)
			{
				if (j == i)
				{
					;
				}
				else
				{
					file << "\t\t(AxesGroup[1].M_Function[" << j << "] = 0) & \n";
				}
			}
		}
		else if (McodeType == 1)
		{
			for (int j = 0; j < 100; j++)
			{
				if (j == i)
				{
					;
				}
				else
				{
					file << "\t\t(AxesGroup[1].M_Function[" << j << "] = 0) & \n";
				}
			}
		}
		file << "\t\tTRUE )THEN\n";
	}
	
	if (McodeType == 0)
	{
		file << "\t\t\t;\n";

	}
	else if (McodeType == 1)
	{
		file << "\t\t\tAxesGroup[1].M_Function[" << i << "] := 0;\n";
	}
	
	file << "\t\tELSE\n\t\t\tError1 := TRUE;\n";
	file << "\t\t\tMError[" << i << "] := AxesGroup[1].M_Function;\n";
	file <<	"\t\t\tlineError1[" << i << "] := NC_Currentline;\n";
	file << "\t\t\tErrorValue[" << i << "]:=ABS(AxesGroup[1].M_Value[" << i << "] - " << i * mCodeFactor << ");\n";
	file << "\t\tEND_IF;\n";
	file << "\tEND_IF;\n";
	file << "END_IF;\n";

}



void makeMixFile(std::ofstream &file, std::ofstream &judgefile)
{
	base_pointer startpoint;
	base_pointer endpoint;
//	base_pointer centerpoint;
	startpoint.x = 0.0;
	startpoint.y = 0.0;

	

	file << "N0 G50\nN1 G" << flat_global << std::endl;

	int32_t linenum = 2;
	for (int32_t i = 0; i <=99;i++)
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

//		writeMcode_judge(judgefile, linenum, i);

		int32_t judgelinenum = linenum + 1;
		switch (i%8)
		{
		case 0:
//			centerpoint = getCircleCenterPoint(startpoint, endpoint);
//			writeG2_center(file, linenum, flat_global, endpoint.x, endpoint.y, i*10, i*50, i*30, i*70, i*100, i*115, centerpoint.x, centerpoint.y, i / 8);
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 1:
//			centerpoint = getCircleCenterPoint(startpoint, endpoint);
//			writeG3_center(file, linenum, flat_global, endpoint.x, endpoint.y, i*23, i*85, i*46, i*76, i*12, i*130, centerpoint.x, centerpoint.y, i / 8);
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 2:
//			writeG2_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i*121, i*25, i*49, i*63, i*42, i*28, line_long + i, i / 8);
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 3:
			writeG1(file, linenum,flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 4:
//			writeG3_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i*99, i*84, i*73, i*27, i*78, i*42, line_long + i, i / 8);
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 5:
//			writeG3_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i*88, i*37, i*72, i*44, i*63, i*82, -(line_long + i), i / 8);
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 6:
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		case 7:
//			writeG2_radius(file, linenum, flat_global, endpoint.x, endpoint.y, i*45, i*62, i*49, i*73, i*61, i*85, -(line_long + i), i / 8);
			writeG1(file, linenum, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);
			break;
		default:
			break;
		}
		writeGcode_judge(judgefile, judgelinenum +1, flat_global, endpoint.x, endpoint.y, i, i, i, i, i, i);

		linenum++;

		if (McodeType == 0)
		{
			;
			writeMcode_judge(judgefile, linenum, i);
		}
		else if (McodeType == 1)
		{
			if (McodeValue == 0)
			{
				file << "N" << linenum << " M" << i << " D" << (i + 1) * mCodeFactor <<std::endl;

			}
			else if (McodeValue == 1)
			{
				file << "N" << linenum << " M" << i << std::endl;
			}
			writeMcode_judge(judgefile, linenum, i);
			linenum++;
		}
		
		
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
	System::Xml::XmlNode^ McodeType_node = rootnode->SelectSingleNode("McodeType");
	System::Xml::XmlNode^ McodeValue_node = rootnode->SelectSingleNode("McodeIsValue");

	
	char* linelong_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(linelong_node->ChildNodes[0]->InnerText);
	char* firstangle_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(firstangle_node->ChildNodes[0]->InnerText);
	char* eachangle_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(eachangle_node->ChildNodes[0]->InnerText);
	char* flat_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(flat_node->ChildNodes[0]->InnerText);
	char* McodeType_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(McodeType_node->ChildNodes[0]->InnerText);
	char* McodeValue_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(McodeValue_node->ChildNodes[0]->InnerText);


	line_long = atof(linelong_char);
	firstangle = atof(firstangle_char);
	angle = atof(eachangle_char);
	flat_global = atoi(flat_char);

	McodeType = atoi(McodeType_char);
	McodeValue = atoi(McodeValue_char);

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
#include "MakeGFile.h"

void makeGfile()
{
	std::ofstream outfile, outfileJudge, outfileJudge_var,outfileJudgePasspoint;
	outfile.open("E:\\TextOut\\G_code.txt", std::ios::out, std::ios::trunc);
	outfileJudge.open("E:\\TextOut\\G_code_posjudge.txt", std::ios::out, std::ios::trunc);
	outfileJudge_var.open("E:\\TextOut\\G_code_posjudge_var.txt", std::ios::out, std::ios::trunc);
	outfileJudgePasspoint.open("E:\\TextOut\\G_code_passpointJudge.txt", std::ios::out, std::ios::trunc);
	outfile.precision(10);
	outfileJudge.precision(10);
	outfileJudge_var.precision(10);
	outfileJudgePasspoint.precision(10);
	makesomefile(outfile, outfileJudge,outfileJudge_var,outfileJudgePasspoint);
	outfile.close();
	outfileJudge.close();
	outfileJudge_var.close();
	outfileJudgePasspoint.close();
}

void makesomefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, std::ofstream &judgepass)
{
	System::Xml::XmlDocument^ doc = gcnew System::Xml::XmlDocument;
	doc->Load("E:\\TextOut\\G_code_Para.xml");

	System::Xml::XmlNode^ rootnode = doc->SelectSingleNode("Parameters");
	System::Xml::XmlNode^ Type_node = rootnode->SelectSingleNode("Type");
	char* Type_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Type_node->ChildNodes[0]->InnerText);
	int outGcodetype = atoi(Type_char);

	if (outGcodetype == 0)
	{
		System::Xml::XmlNode^ Axis_node = rootnode->SelectSingleNode("Axis");
		System::Xml::XmlNode^ isRelative_node = rootnode->SelectSingleNode("isRelative");
		System::Xml::XmlNode^ Gcode_node = rootnode->SelectSingleNode("Gcode");
		System::Xml::XmlNode^ G2method_node = rootnode->SelectSingleNode("G2method");
		System::Xml::XmlNode^ flat_node = rootnode->SelectSingleNode("flat");


		char* Axis_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Axis_node->ChildNodes[0]->InnerText);
		char* isRelative_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(isRelative_node->ChildNodes[0]->InnerText);
		char* Gcode_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Gcode_node->ChildNodes[0]->InnerText);
		char* G2method_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(G2method_node->ChildNodes[0]->InnerText);
		char* flat_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(flat_node->ChildNodes[0]->InnerText);

		int whichAxis = atoi(Axis_char);
		int isRelative = atoi(isRelative_char);
		int Gcode = atoi(Gcode_char);
		int G2method = atoi(G2method_char);
		int flat = atoi(flat_char);

		switch (whichAxis)
		{
		case 0:
			switch (isRelative)
			{
			case 0:
				switch (Gcode)
				{
				case 0:
					makeG0singlefile(file, judgefile, judgefile_var, 90, 1);
					break;
				case 1:
					makeG1singlefile(file, judgefile, judgefile_var, 90, 1);
					break;
				case 2:
					switch (flat)
					{
					case 0:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 2, 90, 17, G2method);
						break;
					case 1:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 2, 90, 18, G2method);
						break;
					case 2:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 2, 90, 19, G2method);
						break;
					default:
						break;
					}
					break;
				case 3:
					switch (flat)
					{
					case 0:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 3, 90, 17, G2method);
						break;
					case 1:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 3, 90, 18, G2method);
						break;
					case 2:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 3, 90, 19, G2method);
						break;
					default:
						break;
					}

					break;
				default:
					break;
				}
				break;
			case 1:
				switch (Gcode)
				{
				case 0:
					makeG0singlefile(file, judgefile, judgefile_var, 91, 1);
					break;
				case 1:
					makeG1singlefile(file, judgefile, judgefile_var, 91, 1);
					break;
				case 2:
					switch (flat)
					{
					case 0:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 2, 91, 17, G2method);
						break;
					case 1:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 2, 91, 18, G2method);
						break;
					case 2:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 2, 91, 19, G2method);
						break;
					default:
						break;
					}

					break;
				case 3:
					switch (flat)
					{
					case 0:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 3, 91, 17, G2method);
						break;
					case 1:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 3, 91, 18, G2method);
						break;
					case 2:
						makeG2G3singlefile(file, judgefile, judgefile_var, judgepass, 3, 91, 19, G2method);
						break;
					default:
						break;
					}

					break;
				default:
					break;
				}

				break;
			default:
				break;
			}
			break;
		case 1:
			switch (isRelative)
			{
			case 0:
				switch (Gcode)
				{
				case 0:
					makeG0multiplefile(file, judgefile, judgefile_var, 90);
					break;
				case 1:
					makeG1multiplefile(file, judgefile, judgefile_var, 90);
					break;
				case 2:
					switch (flat)
					{
					case 0:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 2, 90, 17, G2method);
						break;
					case 1:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 2, 90, 18, G2method);
						break;
					case 2:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 2, 90, 19, G2method);
						break;
					default:
						break;
					}
					break;
				case 3:
					switch (flat)
					{
					case 0:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 3, 90, 17, G2method);
						break;
					case 1:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 3, 90, 18, G2method);
						break;
					case 2:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 3, 90, 19, G2method);
						break;
					default:
						break;
					}

					break;
				default:
					break;
				}

				break;
			case 1:
				switch (Gcode)
				{
				case 0:
					makeG0multiplefile(file, judgefile, judgefile_var, 91);
					break;
				case 1:
					makeG1multiplefile(file, judgefile, judgefile_var, 91);
					break;
				case 2:
					switch (flat)
					{
					case 0:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 2, 91, 17, G2method);
						break;
					case 1:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 2, 91, 18, G2method);
						break;
					case 2:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 2, 91, 19, G2method);
						break;
					default:
						break;
					}

					break;
				case 3:
					switch (flat)
					{
					case 0:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 3, 91, 17, G2method);
						break;
					case 1:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 3, 91, 18, G2method);
						break;
					case 2:
						makeG2G3multiplefile(file, judgefile, judgefile_var, judgepass, 3, 91, 19, G2method);
						break;
					default:
						break;
					}

					break;
				default:
					break;
				}

				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}

	if (outGcodetype == 1)
	{
		System::Xml::XmlNode^ isRelative_node = rootnode->SelectSingleNode("isRelative");
		char* isRelative_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(isRelative_node->ChildNodes[0]->InnerText);
		int isRelative = atoi(isRelative_char);
		if (isRelative == 0)
		{
			isRelative = 90;
		}
		else if (isRelative == 1)
		{
			isRelative = 91;
		}


		System::Xml::XmlNode^ FirstGcode_node = rootnode->SelectSingleNode("FirstGcode");
		char* FirstGcode_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(FirstGcode_node->ChildNodes[0]->InnerText);
		int FirstGcode = atoi(FirstGcode_char);

		System::Xml::XmlNode^ SeconddGcode_node = rootnode->SelectSingleNode("SecondGcode");
		char* SecondGcode_char = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(SeconddGcode_node->ChildNodes[0]->InnerText);
		int SecondGcode = atoi(SecondGcode_char);

		switch (FirstGcode)
		{
		case 0:
			makeFirstGcodeisG0file(SecondGcode, file, judgefile, judgefile_var, isRelative);
			break;
		case 1:
			makeFirstGcodeisG1file(SecondGcode, file, judgefile, judgefile_var, isRelative);
			break;
		case 2:
			makeFirstGcodeisCirclefile(SecondGcode, file, judgefile, judgefile_var, isRelative,2,0);
			break;
		case 3:
			makeFirstGcodeisCirclefile(SecondGcode, file, judgefile, judgefile_var, isRelative, 2, 1);
			break;
		case 4:
			makeFirstGcodeisCirclefile(SecondGcode, file, judgefile, judgefile_var, isRelative, 2, 2);
			break;
		case 5:
			makeFirstGcodeisCirclefile(SecondGcode, file, judgefile, judgefile_var, isRelative, 3, 0);
			break;
		case 6:
			makeFirstGcodeisCirclefile(SecondGcode, file, judgefile, judgefile_var, isRelative, 3, 1);
			break;
		case 7:
			makeFirstGcodeisCirclefile(SecondGcode, file, judgefile, judgefile_var, isRelative, 3, 2);
			break;
		default:
			break;
		}
	}


}

void makeG0singlefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode, int axis)
{
	int32_t linenum = 0;

	switch (mode)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		break;
	default:
		break;
	}

	for (int32_t i = 0; i < linesum; i++)
	{
		file << "N" << linenum << " G0";
		switch (axis)
		{
		case 1:
			file << " X";
			break;
		case 2:
			file << " Y";
			break;
		case 3:
			file << " Z";
			break;
		case 4:
			file << " A";
			break;
		case 5:
			file << " B";
			break;
		case 6:
			file << " C";
			break;
		case 7:
			file << " P";
			break;
		case 8:
			file << " Q";
			break;
		default:
			break;
		}

		switch (mode)
		{
		case 90:
			file << getSingleLineValue(linenum) << std::endl;
			break;
		case 91:
			file << singleAxisFactor << std::endl;
			break;
		default:
			break;
		}
		

		//judge
		judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
		judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001) THEN\n";
		judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
		judgefile << "\t\t%QX0.0:=TRUE;\n";
		judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
		judgefile << "\tEND_IF;\n";
		judgefile << "END_IF;\n";

		linenum++;
	}

	judgefile_var << "VAR\tError\t\tARRAY [0.." << linenum << "] OF BOOL\t\t\n";
	judgefile_var << "VAR\tErrorLine\t\tARRAY [0.." << linenum << "] OF UDINT\t\t\n";

}

void makeG0multiplefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode)
{
	int32_t linenum = 0;
	
	switch (mode)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			file << "N" << linenum << " G0 X" << getSingleLineValue(linenum) << " Y" << getSingleLineValue(linenum)
				<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
				<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
				<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[2].cmdpos - " << getSingleLineValue(linenum)
				<< ")<0.0001 & ABS(Axis[3].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[4].cmdpos - " << getSingleLineValue(linenum)
				<< ")<0.0001 & ABS(Axis[5].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[6].cmdpos - " << getSingleLineValue(linenum)
				<< ")<0.0001 & ABS(Axis[7].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[8].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";



			linenum++;
		}
		
		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			file << "N" << linenum << " G0 X" << singleAxisFactor << " Y" << singleAxisFactor
				<< " Z" << singleAxisFactor << " A" << singleAxisFactor
				<< " B" << singleAxisFactor << " C" << singleAxisFactor
				<< " P" << singleAxisFactor << " Q" << singleAxisFactor << "\n";


			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[2].cmdpos - " << getSingleLineValue(linenum)
				<< ")<0.0001 & ABS(Axis[3].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[4].cmdpos - " << getSingleLineValue(linenum)
				<< ")<0.0001 & ABS(Axis[5].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[6].cmdpos - " << getSingleLineValue(linenum)
				<< ")<0.0001 & ABS(Axis[7].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001 & ABS(Axis[8].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";		
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";


			linenum++;
		}

		break;
	default:
		break;
	}

	judgefile_var << "VAR\tError\t\tARRAY [0.." << linenum << "] OF BOOL\t\t\n";
	judgefile_var << "VAR\tErrorLine\t\tARRAY [0.." << linenum << "] OF UDINT\t\t\n";

}


void makeG1singlefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode, int axis)
{
	int32_t linenum = 0;

switch (mode)
{
case 90:
	file << "N" << linenum << " G90\n";
	linenum++;
	break;
case 91:
	file << "N" << linenum << " G91\n";
	linenum++;
	break;
default:
	break;
}

for (int32_t i = 0; i < linesum; i++)
{
	file << "N" << linenum << " G1";
	switch (axis)
	{
	case 1:
		file << " X";
		break;
	case 2:
		file << " Y";
		break;
	case 3:
		file << " Z";
		break;
	case 4:
		file << " A";
		break;
	case 5:
		file << " B";
		break;
	case 6:
		file << " C";
		break;
	case 7:
		file << " P";
		break;
	case 8:
		file << " Q";
		break;
	default:
		break;
	}

	switch (mode)
	{
	case 90:
		file << getSingleLineValue(linenum) << std::endl;
		break;
	case 91:
		file << singleAxisFactor << std::endl;
		break;
	default:
		break;
	}


	//judge
	judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
	judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - " << getSingleLineValue(linenum) << ")<0.0001) THEN\n";
	judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
	judgefile << "\t\t%QX0.0:=TRUE;\n";
	judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
	judgefile << "\tEND_IF;\n";
	judgefile << "END_IF;\n";

	linenum++;
}

judgefile_var << "VAR\tError\t\tARRAY [0.." << linenum << "] OF BOOL\t\t\n";
judgefile_var << "VAR\tErrorLine\t\tARRAY [0.." << linenum << "] OF UDINT\t\t\n";

}

void makeG1multiplefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int mode)
{
	int32_t linenum = 0;

	switch (mode)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			file << "N" << linenum << " G1 X" << getSingleLineValue(linenum) * x_factor << " Y" << getSingleLineValue(linenum) * y_factor
				<< " Z" << getSingleLineValue(linenum) * z_factor << " A" << getSingleLineValue(linenum) * a_factor
				<< " B" << getSingleLineValue(linenum) * b_factor << " C" << getSingleLineValue(linenum) * c_factor
				<< " P" << getSingleLineValue(linenum) * p_factor << " Q" << getSingleLineValue(linenum) * q_factor << "\n";

			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << getSingleLineValue(linenum) * x_factor << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << getSingleLineValue(linenum) * y_factor
				<< "))<0.0002 & ABS(Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum) * z_factor << "))<0.0002 & ABS(Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum) * a_factor
				<< "))<0.0002 & ABS(Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum) * b_factor << "))<0.0002 & ABS(Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum) * c_factor
				<< "))<0.0002 & ABS(Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum) * p_factor << "))<0.0002 & ABS(Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum) * q_factor << "))<0.0002) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n"	;
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",1]:=Axis[1].cmdpos - (LREAL#" << getSingleLineValue(linenum) * x_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",2]:=Axis[2].cmdpos - (LREAL#" << getSingleLineValue(linenum) * y_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",3]:=Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum) * z_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",4]:=Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum) * a_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",5]:=Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum) * b_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",6]:=Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum) * c_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",7]:=Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum) * p_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",8]:=Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum) * q_factor << ");\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";



			linenum++;
		}

		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			file << "N" << linenum << " G1 X" << singleAxisFactor * x_factor << " Y" << singleAxisFactor * y_factor
				<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
				<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
				<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor << "\n";


			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << getSingleLineValue(linenum) * x_factor << "))<0.0001 & ABS(Axis[2].cmdpos - (LREAL#" << getSingleLineValue(linenum) * y_factor
				<< "))<0.0001 & ABS(Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum) * z_factor << "))<0.0001 & ABS(Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum) * a_factor
				<< "))<0.0001 & ABS(Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum) * b_factor << "))<0.0001 & ABS(Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum) * c_factor
				<< "))<0.0001 & ABS(Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum) * p_factor << "))<0.0001 & ABS(Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum) * q_factor << "))<0.0001) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",1]:=Axis[1].cmdpos - (LREAL#" << getSingleLineValue(linenum) * x_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",2]:=Axis[2].cmdpos - (LREAL#" << getSingleLineValue(linenum) * y_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",3]:=Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum) * z_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",4]:=Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum) * a_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",5]:=Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum) * b_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",6]:=Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum) * c_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",7]:=Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum) * p_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",8]:=Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum) * q_factor << ");\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";


			linenum++;
		}

		break;
	default:
		break;
	}

	judgefile_var << "VAR\tError\t\tARRAY [0.." << linenum << "] OF BOOL\t\t\n";
	judgefile_var << "VAR\tErrorLine\t\tARRAY [0.." << linenum << "] OF UDINT\t\t\n";
	judgefile_var << "VAR\tErrorLinePos\t\tARRAY [0.." << linenum << ",1..8] OF LREAL\t\t\n";
	judgefile_var << "VAR\tErrorLinePosdiff\t\tARRAY [0.." << linenum << ",1..8] OF LREAL\t\t\n";


}

void makeG2G3singlefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, std::ofstream &judgepass, int code, int mode, int flat, int method)
{
	int32_t linenum = 0, side = 0;
	point startpoint, endpoint, centerpoint, passpoint;
	startpoint.x = 0;
	startpoint.y = 0;

	file << "N" << linenum << " G" << flat << "\n";
	linenum++;

	judgepass << "X_Pos_before := X_Pos_now;\n";
	judgepass << "Y_Pos_before := Y_Pos_now;\n";
	judgepass << "X_Pos_now := Axis[1].cmdpos;\n";
	judgepass << "Y_Pos_now := Axis[2].cmdpos;\n";

	switch (mode)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			switch (method)
			{
			case 0:
				if (side == 0)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			case 1:
				if(code==2)
				{
					side = 0;
				}
				else
				{
					side = 1;
				}
				break;
			case 2:
				if (code == 2)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			default:
				break;
			} 


			centerpoint = getcenter(startpoint, endpoint, radius, side);
			passpoint = getpasspoint(startpoint, endpoint, radius, code, side);


		

			

			switch (method)
			{
			case 0:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y << " I" << centerpoint.x << " J" << centerpoint.y << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << endpoint.x << " X" << endpoint.y << " K" << centerpoint.x << " I" << centerpoint.y << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << endpoint.x << " Z" << endpoint.y << " J" << centerpoint.x << " K" << centerpoint.y << "\n";
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y << " R" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << endpoint.x << " X" << endpoint.y << " R" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << endpoint.x << " Z" << endpoint.y << " R" << radius << "\n";
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y << " R-" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << endpoint.x << " X" << endpoint.y << " R-" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << endpoint.x << " Z" << endpoint.y << " R-" << radius << "\n";
					break;
				default:
					break;
				}

				break;
			default:
				break;
			}

			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << endpoint.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << endpoint.y << "))<0.0002) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",1]:=Axis[1].cmdpos - (LREAL#" << endpoint.x << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",2]:=Axis[2].cmdpos - (LREAL#" << endpoint.y << ");\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			//pass
			printpassjudge(judgepass, passpoint, linenum);
			
			startpoint = endpoint;
			linenum++;
		}

		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			switch (method)
			{
			case 0:
				if (side == 0)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			case 1:
				if (code == 2)
				{
					side = 0;
				}
				else
				{
					side = 1;
				}
				break;
			case 2:
				if (code == 2)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			default:
				break;
			}

			centerpoint = getcenter(startpoint, endpoint, radius, side);
			passpoint = getpasspoint(startpoint, endpoint, radius, code, side);

		

			switch (method)
			{
			case 0:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << chordlong * cos(G2angle) << " Y" << chordlong * sin(G2angle) << " I" << centerpoint.x << " J" << centerpoint.y << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << chordlong * cos(G2angle) << " X" << chordlong * sin(G2angle) << " K" << centerpoint.x << " I" << centerpoint.y << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << chordlong * cos(G2angle) << " Z" << chordlong * sin(G2angle) << " J" << centerpoint.x << " K" << centerpoint.y << "\n";
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << chordlong * cos(G2angle) << " Y" << chordlong * sin(G2angle) << " R" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << chordlong * cos(G2angle) << " X" << chordlong * sin(G2angle) << " R" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << chordlong * cos(G2angle) << " Z" << chordlong * sin(G2angle) << " R" << radius << "\n";
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << chordlong * cos(G2angle) << " Y" << chordlong * sin(G2angle) << " R-" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << chordlong * cos(G2angle) << " X" << chordlong * sin(G2angle) << " R-" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << chordlong * cos(G2angle) << " Z" << chordlong * sin(G2angle) << " R-" << radius << "\n";
					break;
				default:
					break;
				}

				break;
			default:
				break;
			}

			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << endpoint.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << endpoint.y << "))<0.0002) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",1]:=Axis[1].cmdpos - (LREAL#" << endpoint.x << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",2]:=Axis[2].cmdpos - (LREAL#" << endpoint.y << ");\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			//pass
			printpassjudge(judgepass, passpoint, linenum);

			startpoint = endpoint;
			linenum++;
		}

		break;
	default:
		break;
	}

	judgefile_var << "VAR\tError\t\tARRAY [0.." << linenum << "] OF BOOL\t\t\n";
	judgefile_var << "VAR\tErrorLine\t\tARRAY [0.." << linenum << "] OF UDINT\t\t\n";
	judgefile_var << "VAR\tErrorLinePos\t\tARRAY [0.." << linenum << ",1..8] OF LREAL\t\t\n";
	judgefile_var << "VAR\tErrorLinePosdiff\t\tARRAY [0.." << linenum << ",1..8] OF LREAL\t\t\n";

}

void makeG2G3multiplefile(std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, std::ofstream &judgepass, int code, int mode, int flat, int method)
{
	int32_t linenum = 0, side = 0;
	point startpoint, endpoint, centerpoint, passpoint;
	startpoint.x = 0;
	startpoint.y = 0;

	file << "N" << linenum << " G" << flat << "\n";
	linenum++;

	judgepass << "X_Pos_before := X_Pos_now;\n";
	judgepass << "Y_Pos_before := Y_Pos_now;\n";
	judgepass << "X_Pos_now := Axis[1].cmdpos;\n";
	judgepass << "Y_Pos_now := Axis[2].cmdpos;\n";


	switch (mode)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);
			
			switch (method)
			{
			case 0:
				if (side == 0)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			case 1:
				if (code == 2)
				{
					side = 0;
				}
				else
				{
					side = 1;
				}
				break;
			case 2:
				if (code == 2)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			default:
				break;
			}

			centerpoint = getcenter(startpoint, endpoint, radius, side);
			passpoint = getpasspoint(startpoint, endpoint, radius, code, side);


			switch (method)
			{
			case 0:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y 
						<< " Z" << getSingleLineValue(linenum-1) * z_factor << " A" << getSingleLineValue(linenum-1) * a_factor
						<< " B" << getSingleLineValue(linenum-1) * b_factor << " C" << getSingleLineValue(linenum-1) * c_factor
						<< " P" << getSingleLineValue(linenum-1) * p_factor << " Q" << getSingleLineValue(linenum-1) * q_factor
						<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << endpoint.x << " X" << endpoint.y 
						<< " Y" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " K" << centerpoint.x << " I" << centerpoint.y << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << endpoint.x << " Z" << endpoint.y 
						<< " X" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " J" << centerpoint.x << " K" << centerpoint.y << "\n";
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y
						<< " Z" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " R" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << endpoint.x << " X" << endpoint.y 
						<< " Y" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " R" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << endpoint.x << " Z" << endpoint.y 
						<< " X" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " R" << radius << "\n";
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y 
						<< " Z" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " R-" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << endpoint.x << " X" << endpoint.y 
						<< " Y" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " R-" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << endpoint.x << " Z" << endpoint.y 
						<< " X" << getSingleLineValue(linenum - 1) * z_factor << " A" << getSingleLineValue(linenum - 1) * a_factor
						<< " B" << getSingleLineValue(linenum - 1) * b_factor << " C" << getSingleLineValue(linenum - 1) * c_factor
						<< " P" << getSingleLineValue(linenum - 1) * p_factor << " Q" << getSingleLineValue(linenum - 1) * q_factor
						<< " R-" << radius << "\n";
					break;
				default:
					break;
				}

				break;
			default:
				break;
			}

			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << endpoint.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << endpoint.y 
				<< "))<0.0002 & ABS(Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * z_factor << "))<0.0002 & ABS(Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * a_factor
				<< "))<0.0002 & ABS(Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * b_factor << "))<0.0002 & ABS(Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * c_factor
				<< "))<0.0002 & ABS(Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * p_factor << "))<0.0002 & ABS(Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * q_factor	<< "))<0.0002) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";

			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",1]:=Axis[1].cmdpos - (LREAL#" << endpoint.x << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",2]:=Axis[2].cmdpos - (LREAL#" << endpoint.y << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",3]:=Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * z_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",4]:=Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * a_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",5]:=Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * b_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",6]:=Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * c_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",7]:=Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * p_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",8]:=Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * q_factor << ");\n";

			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			printpassjudge(judgepass, passpoint, linenum);


			startpoint = endpoint;
			linenum++;
		}

		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (int32_t i = 0; i < linesum; i++)
		{
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			switch (method)
			{
			case 0:
				if (side == 0)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			case 1:
				if (code == 2)
				{
					side = 0;
				}
				else
				{
					side = 1;
				}
				break;
			case 2:
				if (code == 2)
				{
					side = 1;
				}
				else
				{
					side = 0;
				}
				break;
			default:
				break;
			}

			centerpoint = getcenter(startpoint, endpoint, radius, side);
			passpoint = getpasspoint(startpoint, endpoint, radius, code, side);

			switch (method)
			{
			case 0:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << chordlong * cos(G2angle) << " Y" << chordlong * sin(G2angle) 
						<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor 
						<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << chordlong * cos(G2angle) << " X" << chordlong * sin(G2angle) 
						<< " Y" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " K" << centerpoint.x << " I" << centerpoint.y << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << chordlong * cos(G2angle) << " Z" << chordlong * sin(G2angle) 
						<< " X" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " J" << centerpoint.x << " K" << centerpoint.y << "\n";
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << chordlong * cos(G2angle) << " Y" << chordlong * sin(G2angle) 
						<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " R" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << chordlong * cos(G2angle) << " X" << chordlong * sin(G2angle) 
						<< " Y" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " R" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << chordlong * cos(G2angle) << " Z" << chordlong * sin(G2angle) 
						<< " X" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " R" << radius << "\n";
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (flat)
				{
				case 17:
					file << "N" << linenum << " G" << code << " X" << chordlong * cos(G2angle) << " Y" << chordlong * sin(G2angle) 
						<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " R-" << radius << "\n";
					break;
				case 18:
					file << "N" << linenum << " G" << code << " Z" << chordlong * cos(G2angle) << " X" << chordlong * sin(G2angle) 
						<< " Y" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " R-" << radius << "\n";
					break;
				case 19:
					file << "N" << linenum << " G" << code << " Y" << chordlong * cos(G2angle) << " Z" << chordlong * sin(G2angle) 
						<< " X" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
						<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
						<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor
						<< " R-" << radius << "\n";
					break;
				default:
					break;
				}

				break;
			default:
				break;
			}

			//judge
			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << endpoint.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << endpoint.y 
				<< "))<0.0001 & ABS(Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum-1) * z_factor << "))<0.0001 & ABS(Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum-1) * a_factor
				<< "))<0.0001 & ABS(Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum-1) * b_factor << "))<0.0001 & ABS(Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum-1) * c_factor
				<< "))<0.0001 & ABS(Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum-1) * p_factor << "))<0.0001 & ABS(Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum-1) * q_factor << "))<0.0002) THEN\n";
			judgefile << "\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";

			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",1]:=Axis[1].cmdpos - (LREAL#" << endpoint.x << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",2]:=Axis[2].cmdpos - (LREAL#" << endpoint.y << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",3]:=Axis[3].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * z_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",4]:=Axis[4].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * a_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",5]:=Axis[5].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * b_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",6]:=Axis[6].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * c_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",7]:=Axis[7].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * p_factor << ");\n";
			judgefile << "\t\tErrorLinePosdiff[" << linenum << ",8]:=Axis[8].cmdpos - (LREAL#" << getSingleLineValue(linenum - 1) * q_factor << ");\n";

			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";


			printpassjudge(judgepass, passpoint, linenum);


			startpoint = endpoint;
			linenum++;
		}

		break;
	default:
		break;
	}

	judgefile_var << "VAR\tError\t\tARRAY [0.." << linenum << "] OF BOOL\t\t\n";
	judgefile_var << "VAR\tErrorLine\t\tARRAY [0.." << linenum << "] OF UDINT\t\t\n";
	judgefile_var << "VAR\tErrorLinePos\t\tARRAY [0.." << linenum << ",1..8] OF LREAL\t\t\n";
	judgefile_var << "VAR\tErrorLinePosdiff\t\tARRAY [0.." << linenum << ",1..8] OF LREAL\t\t\n";

}

double getSingleLineValue(int32_t linenum)
{
	return linenum * singleAxisFactor;
}


point getcenter(point startpoint, point endpoint, double radius, int whichside)
{
	point centerpoint;
	point midpoint;
	midpoint.x = startpoint.x + (endpoint.x - startpoint.x) / 2;
	midpoint.y = startpoint.y + (endpoint.y - startpoint.y) / 2;

	double onesidelinelong = sqrt(pow(radius, 2) - (pow(midpoint.x - startpoint.x, 2) + pow(midpoint.y - startpoint.y, 2)));

	double vectorx = midpoint.x - startpoint.x;
	double vectory = midpoint.y - startpoint.y;

	double offsetx = (onesidelinelong * vectory) / sqrt(pow(vectory, 2) + pow(vectorx, 2));
	double offsety = -(offsetx * vectorx) / vectory;


	switch (whichside)
	{
	case 0:
		centerpoint.x = midpoint.x + offsetx - startpoint.x;
		centerpoint.y = midpoint.y + offsety - startpoint.y;
		break;
	case 1:
		centerpoint.x = midpoint.x - offsetx - startpoint.x;
		centerpoint.y = midpoint.y - offsety - startpoint.y;
		break;
	default:
		break;
	}

	return centerpoint;
}


point getpasspoint(point startpoint, point endpoint, double radius,int code, int whichside)
{
	point center = getcenter(startpoint, endpoint, radius, whichside);

	point passpoint;

	passpoint.x = (startpoint.x + endpoint.x) / 2;

	double a = center.x + startpoint.x;
	double b = center.y + startpoint.y;
	double r = radius;
	double x = passpoint.x;

	double y1 = b - sqrt(-pow(a, 2) + 2 * a*x + pow(r, 2) - pow(x, 2));
	double y2 = sqrt(-pow(a, 2) + 2 * a*x + pow(r, 2) - pow(x, 2)) + b;

//	if(center.x <= startpoint.x)
//	{
//		if(code == 2)
//		{
//			passpoint.y = y2;
//		}
//		else if(code == 3)
//		{
//			passpoint.y = y1;
//		}
//	}
//	else
//	{
//		if (code == 2)
//		{
//			passpoint.y = y1;
//		}
//		else if (code == 3)
//		{
//			passpoint.y = y2;
//		}
//
//	}


	if (startpoint.x > a && endpoint.x > a)
	{
		//起点终点的X轴坐标都大于圆心的X坐标
		if(startpoint.y <= b && endpoint.y <= b)
		{
			//起点终点的X轴坐标都大于圆心的X坐标 且 起点终点的Y轴坐标都小于圆心的Y坐标 -->都在第四象限
			passpoint.y = y1;//Y值为负
		}
		else if (startpoint.y >= b && endpoint.y >= b)
		{
			//起点终点的X轴坐标都大于圆心的X坐标 且 起点终点的Y轴坐标都大于圆心的Y坐标 -->都在第一象限
			passpoint.y = y2;//Y值为正
		}
		else if (startpoint.y <= b && endpoint.y >= b)
		{
			//起点终点的X轴坐标都大于圆心的X坐标 且 起点Y小于圆心Y终点大于圆心
			if(code == 2 )
			{
				if(y1 < startpoint.y)
				{
					passpoint.y = y1;
				}
				else if(y1 > startpoint.y)
				{
					passpoint.y = y2;
				}
			}
			else if(code == 3)
			{
				if (y1 < startpoint.y)
				{
					passpoint.y = y2;
				}
				else if (y1 > startpoint.y)
				{
					passpoint.y = y1;
				}
			}
		}
		else if (startpoint.y >= b && endpoint.y <= b)
		{
			//起点终点的X轴坐标都大于圆心的X坐标 且 起点Y大于圆心Y终点小于圆心
			if (code == 2)
			{
				if (y2 < startpoint.y)
				{
					passpoint.y = y2;
				}
				else if (y2 > startpoint.y)
				{
					passpoint.y = y1;
				}
			}
			else if (code == 3)
			{
				if (y2 < startpoint.y)
				{
					passpoint.y = y1;
				}
				else if (y2 > startpoint.y)
				{
					passpoint.y = y2;
				}
			}

		}

	}
	else if (startpoint.x < a && endpoint.x < a)
	{
		//起点和终点X坐标都小于圆心的X坐标
		if (startpoint.y <= b && endpoint.y <= b)
		{
			//起点终点的X轴坐标都小于圆心的X坐标 且 起点终点的Y轴坐标都小于圆心的Y坐标 -->都在第三象限
			passpoint.y = y1;//Y值为负
		}
		else if (startpoint.y >= b && endpoint.y >= b)
		{
			//起点终点的X轴坐标都小于圆心的X坐标 且 起点终点的Y轴坐标都大于圆心的Y坐标 -->都在第二象限
			passpoint.y = y2;//Y值为正
		}
		else if (startpoint.y <= b && endpoint.y >= b)
		{
			//起点终点的X轴坐标都小于圆心的X坐标 且 起点Y小于圆心Y终点大于圆心
			if (code == 2)
			{
				if (y1 < startpoint.y)
				{
					passpoint.y = y2;
				}
				else if (y1 > startpoint.y)
				{
					passpoint.y = y1;
				}
			}
			else if (code == 3)
			{
				if (y1 < startpoint.y)
				{
					passpoint.y = y1;
				}
				else if (y1 > startpoint.y)
				{
					passpoint.y = y2;
				}
			}
		}
		else if (startpoint.y >= b && endpoint.y <= b)
		{
			//起点终点的X轴坐标都小于圆心的X坐标 且 起点Y大于圆心Y终点小于圆心
			if (code == 2)
			{
				if (y2 < startpoint.y)
				{
					passpoint.y = y1;
				}
				else if (y2 > startpoint.y)
				{
					passpoint.y = y2;
				}
			}
			else if (code == 3)
			{
				if (y2 < startpoint.y)
				{
					passpoint.y = y2;
				}
				else if (y2 > startpoint.y)
				{
					passpoint.y = y1;
				}
			}

		}

	}





	return passpoint;

}

void printpassjudge(std::ofstream &judgepass,point passpoint, int32_t linenum)
{
	//pass
	judgepass << "IF (NC_CurrentLine = " << linenum + 1 << ") THEN\n";
	judgepass << "\tIF ((X_Pos_before < LREAL#" << passpoint.x << ") & (X_Pos_now >= LREAL#" << passpoint.x << ")) OR ((X_Pos_before > LREAL#" << passpoint.x << ") & (X_Pos_now <= LREAL#" << passpoint.x << ")) THEN\n";
	judgepass << "\t\tIF NOT(((Y_Pos_before < LREAL#" << passpoint.y << ") & (Y_Pos_now >= LREAL#" << passpoint.y << ")) OR ((Y_Pos_before > LREAL#" << passpoint.y << ") & (Y_Pos_now <= LREAL#" << passpoint.y << ")))THEN\n";
	judgepass << "\t\t\tError[" << linenum << "]:=TRUE;\n";
	judgepass << "\t\t\t%QX0.5:=TRUE;\n";
	judgepass << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
	judgepass << "\t\t\tErrorLinePosBefore[" << linenum << ",1]:=X_Pos_before;\n";
	judgepass << "\t\t\tErrorLinePosBefore[" << linenum << ",2]:=Y_Pos_before;\n";
	judgepass << "\t\t\tErrorLinePosNow[" << linenum << ",1]:=X_Pos_now;\n";
	judgepass << "\t\t\tErrorLinePosNow[" << linenum << ",2]:=Y_Pos_now;\n";
	judgepass << "\t\tEND_IF;\n";
	judgepass << "\tEND_IF;\n";
	judgepass << "END_IF;\n";

}

void makeFirstGcodeisG0file(int SecendGcode, std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int relative)
{
	int32_t linenum = 0, side = 0;
	point startpoint, endpoint, centerpoint, passpoint;
	startpoint.x = 0;
	startpoint.y = 0;


	switch (relative)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (auto i = 0; i < linesum; i++)
		{

			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			file << "N" << linenum << " G0 X" << endpoint.x << " Y" << endpoint.y
				<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
				<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
				<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;

			startpoint = endpoint;
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);


			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}




			switch (SecendGcode)
			{
			case 0:
				file << "N" << linenum << " G0 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

				break;
			case 1:
				file << "N" << linenum << " G1 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

				break;
			case 2:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) 
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 3:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R" << radius << "\n";

				break;
			case 4:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R-" << radius << "\n";

				break;

			case 5:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 6:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R" << radius << "\n";

				break;
			case 7:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R-" << radius << "\n";
				break;

			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorVel[" << linenum << "]:=Vel;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;
			startpoint = endpoint;

		}
		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (auto i = 0; i < linesum; i++)
		{
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			file << "N" << linenum << " G0 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
				<< " Z" << singleAxisFactor * z_factor << " A" <<  singleAxisFactor * a_factor
				<< " B" << singleAxisFactor * b_factor << " C" <<  singleAxisFactor * c_factor
				<< " P" << singleAxisFactor * p_factor << " Q" <<  singleAxisFactor * q_factor << "\n";

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y 
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" <<getSingleLineValue(linenum) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum) * a_factor
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" <<getSingleLineValue(linenum) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum) * c_factor
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" <<getSingleLineValue(linenum) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) * q_factor << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;

			startpoint = endpoint;
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);


			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}




			switch (SecendGcode)
			{
			case 0:
				file << "N" << linenum << " G0 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" <<singleAxisFactor * z_factor << " A" << singleAxisFactor *a_factor
					<< " B" <<singleAxisFactor * b_factor << " C" << singleAxisFactor *c_factor
					<< " P" <<singleAxisFactor * p_factor << " Q" << singleAxisFactor *q_factor << "\n";

				break;
			case 1:
				file << "N" << linenum << " G1 X" << endpoint.x - startpoint.x << " Y" << endpoint.y -startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor << "\n";

				break;
			case 2:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 3:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y -startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R" << radius << "\n";

				break;
			case 4:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R-" << radius << "\n";

				break;

			case 5:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y -startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 6:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" <<singleAxisFactor * a_factor
					<< " B" << singleAxisFactor *b_factor << " C" <<singleAxisFactor * c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" <<singleAxisFactor * q_factor
					<< " R" << radius << "\n";

				break;
			case 7:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R-" << radius << "\n";
				break;

			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum) * a_factor
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum) * c_factor
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) * q_factor << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorVel[" << linenum << "]:=Vel;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;
			startpoint = endpoint;

		}

			

		

		break;
	default:
		break;
	}

}

void makeFirstGcodeisG1file(int SecendGcode, std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int relative)
{
	int32_t linenum = 0, side = 0;
	point startpoint, endpoint, centerpoint, passpoint;
	startpoint.x = 0;
	startpoint.y = 0;


	switch (relative)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (auto i = 0; i < linesum; i++)
		{

			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			file << "N" << linenum << " G1 X" << endpoint.x << " Y" << endpoint.y
				<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
				<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
				<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;

			startpoint = endpoint;
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);


			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}




			switch (SecendGcode)
			{
			case 0:
				file << "N" << linenum << " G0 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

				break;
			case 1:
				file << "N" << linenum << " G1 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

				break;
			case 2:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 3:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R" << radius << "\n";

				break;
			case 4:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R-" << radius << "\n";

				break;

			case 5:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 6:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R" << radius << "\n";

				break;
			case 7:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R-" << radius << "\n";
				break;

			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorVel[" << linenum << "]:=Vel;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;
			startpoint = endpoint;

		}
		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (auto i = 0; i < linesum; i++)
		{
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);

			file << "N" << linenum << " G1 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
				<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
				<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
				<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor << "\n";

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum) * a_factor
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum) * c_factor
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) * q_factor << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;

			startpoint = endpoint;
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);


			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}




			switch (SecendGcode)
			{
			case 0:
				file << "N" << linenum << " G0 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor *q_factor << "\n";

				break;
			case 1:
				file << "N" << linenum << " G1 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor << "\n";

				break;
			case 2:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 3:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R" << radius << "\n";

				break;
			case 4:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R-" << radius << "\n";

				break;

			case 5:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 6:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor * a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor * c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor * q_factor
					<< " R" << radius << "\n";

				break;
			case 7:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R-" << radius << "\n";
				break;

			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum) * a_factor
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum) * c_factor
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) * q_factor << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorVel[" << linenum << "]:=Vel;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;
			startpoint = endpoint;

		}





		break;
	default:
		break;
	}

}

void makeFirstGcodeisCirclefile(int SecendGcode, std::ofstream &file, std::ofstream &judgefile, std::ofstream &judgefile_var, int relative, int code, int type)
{
	int32_t linenum = 0, side = 0;
	point startpoint, endpoint, centerpoint, passpoint;
	startpoint.x = 0;
	startpoint.y = 0;


	switch (relative)
	{
	case 90:
		file << "N" << linenum << " G90\n";
		linenum++;
		for (auto i = 0; i < linesum; i++)
		{
			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}


			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);
			centerpoint = getcenter(startpoint, endpoint, radius, side);

			file << "N" << linenum << " G" << code << " X" << endpoint.x << " Y" << endpoint.y
				<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
				<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
				<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum);
			switch (type)
			{
			case 0:
				file << " I" << centerpoint.x << " J" << centerpoint.y << "\n";
				break;
			case 1:
				file << " R" << radius << "\n";
				break;
			case 2:
				file << " R-" << radius << "\n";
			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;

			startpoint = endpoint;
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);


			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}




			switch (SecendGcode)
			{
			case 0:
				file << "N" << linenum << " G0 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

				break;
			case 1:
				file << "N" << linenum << " G1 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum) << "\n";

				break;
			case 2:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 3:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R" << radius << "\n";

				break;
			case 4:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R-" << radius << "\n";

				break;

			case 5:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 6:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R" << radius << "\n";

				break;
			case 7:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x << " Y" << endpoint.y
					<< " Z" << getSingleLineValue(linenum) << " A" << getSingleLineValue(linenum)
					<< " B" << getSingleLineValue(linenum) << " C" << getSingleLineValue(linenum)
					<< " P" << getSingleLineValue(linenum) << " Q" << getSingleLineValue(linenum)
					<< " R-" << radius << "\n";
				break;

			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum)
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorVel[" << linenum << "]:=Vel;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;
			startpoint = endpoint;

		}
		break;
	case 91:
		file << "N" << linenum << " G91\n";
		linenum++;
		for (auto i = 0; i < linesum; i++)
		{

			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}

			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);
			centerpoint = getcenter(startpoint, endpoint, radius, side);

			file << "N" << linenum << " G" << code << " X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
				<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor * a_factor
				<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor * c_factor
				<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor * q_factor;
				switch (type)
				{
				case 0:
					file << " I" << centerpoint.x << " J" << centerpoint.y << "\n";
					break;
				case 1:
					file << " R" << radius << "\n";
					break;
				case 2:
					file << " R-" << radius << "\n";
				default:
					break;
				}


			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum) * a_factor
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum) * c_factor
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) * q_factor << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;

			startpoint = endpoint;
			endpoint.x = startpoint.x + chordlong * cos(G2angle);
			endpoint.y = startpoint.y + chordlong * sin(G2angle);


			if (side == 0)
			{
				side = 1;
			}
			else
			{
				side = 0;
			}




			switch (SecendGcode)
			{
			case 0:
				file << "N" << linenum << " G0 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor * z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor * b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor * p_factor << " Q" << singleAxisFactor *q_factor << "\n";

				break;
			case 1:
				file << "N" << linenum << " G1 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor << "\n";

				break;
			case 2:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 3:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R" << radius << "\n";

				break;
			case 4:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 2, side);

				file << "N" << linenum << " G2 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R-" << radius << "\n";

				break;

			case 5:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " I" << centerpoint.x << " J" << centerpoint.y << "\n";

				break;
			case 6:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor * a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor * c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor * q_factor
					<< " R" << radius << "\n";

				break;
			case 7:
				centerpoint = getcenter(startpoint, endpoint, radius, side);

				passpoint = getpasspoint(startpoint, endpoint, radius, 3, side);

				file << "N" << linenum << " G3 X" << endpoint.x - startpoint.x << " Y" << endpoint.y - startpoint.y
					<< " Z" << singleAxisFactor *z_factor << " A" << singleAxisFactor *a_factor
					<< " B" << singleAxisFactor *b_factor << " C" << singleAxisFactor *c_factor
					<< " P" << singleAxisFactor *p_factor << " Q" << singleAxisFactor *q_factor
					<< " R-" << radius << "\n";
				break;

			default:
				break;
			}

			judgefile << "IF EDGEPOS(NC_CurrentLine = " << linenum + 2 << ") THEN\n";
			judgefile << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << endpoint.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << endpoint.y
				<< ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << getSingleLineValue(linenum) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << getSingleLineValue(linenum) * a_factor
				<< ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << getSingleLineValue(linenum) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << getSingleLineValue(linenum) * c_factor
				<< ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << getSingleLineValue(linenum) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << getSingleLineValue(linenum) * q_factor << ")<0.001) THEN\n";
			judgefile << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
			judgefile << "\t\t\tError[" << linenum << "]:=TRUE;\n";
			judgefile << "\t\t\t%QX0.0:=TRUE;\n";
			judgefile << "\t\t\tErrorVel[" << linenum << "]:=Vel;\n";
			judgefile << "\t\t\tErrorLine[" << linenum << "]:=NC_CurrentLine;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",1]:=Axis[1].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",2]:=Axis[2].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",3]:=Axis[3].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",4]:=Axis[4].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",5]:=Axis[5].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",6]:=Axis[6].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",7]:=Axis[7].cmdpos;\n";
			judgefile << "\t\t\tErrorLinePos[" << linenum << ",8]:=Axis[8].cmdpos;\n";
			judgefile << "\t\tEND_IF;\n";
			judgefile << "\tEND_IF;\n";
			judgefile << "END_IF;\n";

			linenum++;
			startpoint = endpoint;

		}





		break;
	default:
		break;
	}

}
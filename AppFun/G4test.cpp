#include "G4test.h"


void g4testFileOutput()
{
	std::ofstream outfile, outfileJudge;
	outfile.open("E:\\TextOut\\G_code.txt", std::ios::out, std::ios::trunc);
	outfileJudge.open("E:\\TextOut\\G_code_posjudge.txt", std::ios::out, std::ios::trunc);
	outfile.precision(10);
	outfileJudge.precision(10);
	makeG4testFile(outfile, outfileJudge);
	outfile.close();
	outfileJudge.close();

}


void makeG4testFile(std::ofstream &file, std::ofstream &judgefile)
{
	std::string gcode[17],theG4code,gcode2[17];

	gcode[0] = "N0 G0 X10 Y10 Z10 A10 B10 C10 P10 Q10";
	gcode[1] = "N0 G1 X10 Y10 Z10 A10 B10 C10 P10 Q10";
	gcode[2] = "N0 G2 X10 Y10 Z10 A10 B10 C10 P10 Q10 I10 J0";
	gcode[3] = "N0 G2 X10 Y10 Z10 A10 B10 C10 P10 Q10 R10";
	gcode[4] = "N0 G2 X10 Y10 Z10 A10 B10 C10 P10 Q10 R-10";
	gcode[5] = "N0 G3 X10 Y10 Z10 A10 B10 C10 P10 Q10 I10 J0";
	gcode[6] = "N0 G3 X10 Y10 Z10 A10 B10 C10 P10 Q10 R10";
	gcode[7] = "N0 G3 X10 Y10 Z10 A10 B10 C10 P10 Q10 R-10";
	gcode[8] = "N0 G4 K10";
	gcode[9] = "N0 G17";
	gcode[10] = "N0 G18";
	gcode[11] = "N0 G19";
	gcode[12] = "N0 G50";
	gcode[13] = "N0 G51 D3";
	gcode[14] = "N0 G52";
	gcode[15] = "N0 G90";
	gcode[16] = "N0 G91";

	gcode2[0] = "N0 G0 X20 Y20 Z20 A20 B20 C20 P20 Q20";
	gcode2[1] = "N0 G1 X20 Y20 Z20 A20 B20 C20 P20 Q20";
	gcode2[2] = "N0 G2 X20 Y20 Z20 A20 B20 C20 P20 Q20 I10 J0";
	gcode2[3] = "N0 G2 X20 Y20 Z20 A20 B20 C20 P20 Q20 R10";
	gcode2[4] = "N0 G2 X20 Y20 Z20 A20 B20 C20 P20 Q20 R-10";
	gcode2[5] = "N0 G3 X20 Y20 Z20 A20 B20 C20 P20 Q20 I10 J0";
	gcode2[6] = "N0 G3 X20 Y20 Z20 A20 B20 C20 P20 Q20 R20";
	gcode2[7] = "N0 G3 X20 Y20 Z20 A20 B20 C20 P20 Q20 R-10";
	gcode2[8] = "N0 G4 K10";
	gcode2[9] = "N0 G17";
	gcode2[10] = "N0 G18";
	gcode2[11] = "N0 G19";
	gcode2[12] = "N0 G50";
	gcode2[13] = "N0 G51 D3";
	gcode2[14] = "N0 G52";
	gcode2[15] = "N0 G90";
	gcode2[16] = "N0 G91";

	


	theG4code = "N0 G4 K3";

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			file << gcode[i].c_str() << "\n";
			file << theG4code.c_str() << "\n";
			file << gcode2[j].c_str() << "\n";
			file << std::endl;
		}
		
	}


}
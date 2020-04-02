#include "output_g4_file.h"

void output_g4_file()
{
    std::ofstream outfile, outfileJudge;
    outfile.open("G_code.txt", std::ios::out, std::ios::trunc);
    outfileJudge.open("G_code_posjudge.txt", std::ios::out, std::ios::trunc);
    outfile.precision(10);
    outfileJudge.precision(10);
    print_g4_file(outfile, outfileJudge);
    outfile.close();
    outfileJudge.close();
}

std::string output_g4(int which, int line_number, double pos, int& flat, double radium, int& relative) {
    std::string str;

    if (relative == 91)
    {
        pos = 10;
    }

    switch (which) {
    case 0:
        str = "N" + std::to_string(line_number) + " G0" + " X" + std::to_string(pos) + " Y" + std::to_string(pos) +
            " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) +
            " C" + std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + "\n";
        break;
    case 1:
        str = "N" + std::to_string(line_number) + " G1" + " X" + std::to_string(pos) + " Y" + std::to_string(pos) +
            " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) +
            " C" + std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + "\n";
        break;
    case 2:
        switch (flat) {
        case 17:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " I" +
                std::to_string(radium) + " J0" + "\n";
            break;
        case 18:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " K" +
                std::to_string(radium) + " I0" + "\n";
            break;
        case 19:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " J" +
                std::to_string(radium) + " K0" + "\n";
            break;
        default: break;
        }
        break;
    case 3:
        switch (flat) {
        case 17:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R" +
                std::to_string(radium) + "\n";
            break;
        case 18:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R" +
                std::to_string(radium) + "\n";
            break;
        case 19:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R" +
                std::to_string(radium) + "\n";
            break;
        default: break;
        }
        break;
    case 4:
        switch (flat) {
        case 17:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R-" +
                std::to_string(radium) + "\n";
            break;
        case 18:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R-" +
                std::to_string(radium) + "\n";
            break;
        case 19:
            str = "N" + std::to_string(line_number) + " G2" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R-" +
                std::to_string(radium) + "\n";
            break;
        default: break;
        }
        break;
    case 5:
        switch (flat) {
        case 17:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " I" +
                std::to_string(radium) + " J0" + "\n";
            break;
        case 18:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " K" +
                std::to_string(radium) + " I0" + "\n";
            break;
        case 19:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " J" +
                std::to_string(radium) + " K0" + "\n";
            break;
        default: break;;
        }

        break;
    case 6:
        switch (flat) {
        case 17:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R" +
                std::to_string(radium) + "\n";
            break;
        case 18:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R" +
                std::to_string(radium) + "\n";
            break;
        case 19:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R" +
                std::to_string(radium) + "\n";
            break;
        default: break;
        }
        break;
    case 7:
        switch (flat) {
        case 17:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R-" +
                std::to_string(radium) + "\n";
            break;
        case 18:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R-" +
                std::to_string(radium) + "\n";
            break;
        case 19:
            str = "N" + std::to_string(line_number) + " G3" + " X" + std::to_string(pos) + " Y" +
                std::to_string(pos) +
                " Z" + std::to_string(pos) + " A" + std::to_string(pos) + " B" + std::to_string(pos) + " C" +
                std::to_string(pos) + " P" + std::to_string(pos) + " Q" + std::to_string(pos) + " R-" +
                std::to_string(radium) + "\n";
            break;
        default: break;
        }
        break;
    case 8:
        str = "N" + std::to_string(line_number) + " G4 K10\n";
        break;
    case 9:
        str = "N" + std::to_string(line_number) + " G17\n";
        flat = 17;
        break;
    case 10:
        str = "N" + std::to_string(line_number) + " G18\n";
        flat = 18;
        break;
    case 11:
        str = "N" + std::to_string(line_number) + " G19\n";
        flat = 19;
        break;
    case 12:
        str = "N" + std::to_string(line_number) + " G52\n";
        break;
    case 13:
        str = "N" + std::to_string(line_number) + " G51 D2\n";
        break;
    case 14:
        str = "N" + std::to_string(line_number) + " G50\n";
        break;
    case 15:
        str = "N" + std::to_string(line_number) + " G90\n";
        //relative = 90;
        break;
    case 16:
        str = "N" + std::to_string(line_number) + " G91\n";
        //relative = 91;
        break;
    default: break;;
    }

    return str;
}

std::string output_g4_judge(int which, int line_number, double pos, int flat, bool choose)
{
    std::string str;

    switch (which) {
    case 0:
    case 1:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" +
            "\tIF NOT ((ABS(Axis[1].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[2].cmdpos - (" + std::to_string(pos)
            + ")) < 0.01) & (ABS(Axis[3].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[4].cmdpos - (" + std::to_string(pos)
            + ")) < 0.01) & (ABS(Axis[5].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[6].cmdpos - (" + std::to_string(pos)
            + ")) < 0.01) & (ABS(Axis[7].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[8].cmdpos - (" + std::to_string(pos) + ")) < 0.01)) THEN\n"
            + "\t\tError1:=TRUE;\n" + "\tEND_IF;\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        switch (flat) {
        case 17:
            str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" +
                "\tIF NOT ((ABS(Axis[1].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[2].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[3].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[4].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[5].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[6].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[7].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[8].cmdpos - (" + std::to_string(pos) + ")) < 0.01)) THEN\n"
                + "\t\tError1:=TRUE;\n" + "\tEND_IF;\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
            break;
        case 18:
            str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" +
                "\tIF NOT ((ABS(Axis[3].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[1].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[2].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[4].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[5].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[6].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[7].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[8].cmdpos - (" + std::to_string(pos) + ")) < 0.01)) THEN\n"
                + "\t\tError1:=TRUE;\n" + "\tEND_IF;\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
            break;
        case 19:
            str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" +
                "\tIF NOT ((ABS(Axis[2].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[3].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[1].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[4].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[5].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[6].cmdpos - (" + std::to_string(pos)
                + ")) < 0.01) & (ABS(Axis[7].cmdpos - (" + std::to_string(pos) + ")) < 0.01) & (ABS(Axis[8].cmdpos - (" + std::to_string(pos) + ")) < 0.01)) THEN\n"
                + "\t\tError1:=TRUE;\n" + "\tEND_IF;\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
            break;
        }
        break;

    case 8:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    case 9:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        flat = 17;
        break;
    case 10:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        flat = 18;
        break;
    case 11:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        flat = 19;
        break;
    case 12:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    case 13:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    case 14:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    case 15:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    case 16:
        str = "IF EDGEPOS(NC_Currentline = " + std::to_string(line_number + 1) + " ) THEN\n" + "\tTON_Start := BOOL#" + std::to_string(choose) + ";\n" + "\tGetTime:=T#0s;\nEND_IF;\n";
        break;
    default: break;;
    }

    return str;
}

void print_g4_file(std::ofstream& file, std::ofstream& judge_file) {
    int flat = 17;
    int line_number = 0;
    int pos_offset = 1;
    int relative = 90;

    judge_file << "T1(EN:=TRUE,In := TON_Start,PT:= T#1H);\n";

    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            line_number = 0;
            pos_offset = 1;
            flat = 17;
            file << output_g4(i, line_number, pos_offset * 10, flat, 10, relative);
            //judge_file << output_g4_judge(i, linenum, pos_offset * 10, flat, true);
            pos_offset++;
            line_number++;
            file << "N" << line_number << " G4 K3" << "\n";
            //judge_file << "IF EDGEPOS(NC_Currentline=" + std::to_string(linenum + 1) + ") THEN\n\tGetTime := T1.ET;\n\tIF GetTime<>T#3s4ms THEN\n\t\tError2 := TRUE;\n\t\tErrorLine:=NC_Currentline;\n\tEND_IF;\nEND_IF;\n";
            line_number++;
            file << output_g4(j, line_number, pos_offset * 10, flat, 10, relative);
            //judge_file << output_g4_judge(i, linenum, pos_offset * 10, flat, false);
            pos_offset++;
            line_number++;
            file << std::endl;
        }
    }
}
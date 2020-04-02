#include "output_blend_gcode_file.h"

void output_blend_gcode_file()
{
    std::ofstream outfile, outfileJudge, outfileJudge_var, outfileJudgePasspoint;
    outfile.open("G_code.txt", std::ios::out, std::ios::trunc);
    outfileJudge.open("G_code_posjudge.txt", std::ios::out, std::ios::trunc);
    outfileJudge_var.open("G_code_posjudge_var.txt", std::ios::out, std::ios::trunc);
    outfileJudgePasspoint.open("G_code_passpointJudge.txt", std::ios::out, std::ios::trunc);
    outfile.precision(10);
    outfileJudge.precision(10);
    outfileJudge_var.precision(10);
    outfileJudgePasspoint.precision(10);
    analyze_parameter(outfile, outfileJudge, outfileJudge_var, outfileJudgePasspoint);
    outfile.close();
    outfileJudge.close();
    outfileJudge_var.close();
    outfileJudgePasspoint.close();
}

void analyze_parameter(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, std::ofstream& judge_pass)
{
    //读取参数文件
    //略

    int out_gcode_type = 1; //0：单独的G代码；1：G1 G2/G3交接；

    if (out_gcode_type == 0)
    {
        int which_axis = 0;
        int is_relative = 0;
        int gcode = 1;
        int g2_method = 90;
        int flat = 17;

        switch (which_axis)
        {
        case 0:
            switch (is_relative)
            {
            case 0:
                switch (gcode)
                {
                case 0:
                    output_g0_single_file(file, judge_file, judge_file_var, 90, 1);
                    break;
                case 1:
                    output_g1_single_file(file, judge_file, judge_file_var, 90, 1);
                    break;
                case 2:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 2, 90, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 2, 90, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 2, 90, 19, g2_method);
                        break;
                    default:
                        break;
                    }
                    break;
                case 3:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 3, 90, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 3, 90, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 3, 90, 19, g2_method);
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
                switch (gcode)
                {
                case 0:
                    output_g0_single_file(file, judge_file, judge_file_var, 91, 1);
                    break;
                case 1:
                    output_g1_single_file(file, judge_file, judge_file_var, 91, 1);
                    break;
                case 2:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 2, 91, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 2, 91, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 2, 91, 19, g2_method);
                        break;
                    default:
                        break;
                    }

                    break;
                case 3:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 3, 91, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 3, 91, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_single_file(file, judge_file, judge_file_var, judge_pass, 3, 91, 19, g2_method);
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
            switch (is_relative)
            {
            case 0:
                switch (gcode)
                {
                case 0:
                    output_g0_multiple_file(file, judge_file, judge_file_var, 90);
                    break;
                case 1:
                    output_g1_multiple_file(file, judge_file, judge_file_var, 90);
                    break;
                case 2:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 2, 90, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 2, 90, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 2, 90, 19, g2_method);
                        break;
                    default:
                        break;
                    }
                    break;
                case 3:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 3, 90, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 3, 90, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 3, 90, 19, g2_method);
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
                switch (gcode)
                {
                case 0:
                    output_g0_multiple_file(file, judge_file, judge_file_var, 91);
                    break;
                case 1:
                    output_g1_multiple_file(file, judge_file, judge_file_var, 91);
                    break;
                case 2:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 2, 91, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 2, 91, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 2, 91, 19, g2_method);
                        break;
                    default:
                        break;
                    }

                    break;
                case 3:
                    switch (flat)
                    {
                    case 0:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 3, 91, 17, g2_method);
                        break;
                    case 1:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 3, 91, 18, g2_method);
                        break;
                    case 2:
                        output_g2_g3_multiple_file(file, judge_file, judge_file_var, judge_pass, 3, 91, 19, g2_method);
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

    if (out_gcode_type == 1)
    {
        int is_relative = 0;

        if (is_relative == 0)
        {
            is_relative = 90;
        }
        else if (is_relative == 1)
        {
            is_relative = 91;
        }

        int first_gcode = 1;

        int second_gcode = 2;

        switch (first_gcode)
        {
        case 0:
            output_first_gcode_is_g0_file(second_gcode, file, judge_file, judge_file_var, is_relative);
            break;
        case 1:
            output_first_gcode_is_g1_file(second_gcode, file, judge_file, judge_file_var, is_relative);
            break;
        case 2:
            output_first_gcode_is_circle_file(second_gcode, file, judge_file, judge_file_var, is_relative, 2, 0);
            break;
        case 3:
            output_first_gcode_is_circle_file(second_gcode, file, judge_file, judge_file_var, is_relative, 2, 1);
            break;
        case 4:
            output_first_gcode_is_circle_file(second_gcode, file, judge_file, judge_file_var, is_relative, 2, 2);
            break;
        case 5:
            output_first_gcode_is_circle_file(second_gcode, file, judge_file, judge_file_var, is_relative, 3, 0);
            break;
        case 6:
            output_first_gcode_is_circle_file(second_gcode, file, judge_file, judge_file_var, is_relative, 3, 1);
            break;
        case 7:
            output_first_gcode_is_circle_file(second_gcode, file, judge_file, judge_file_var, is_relative, 3, 2);
            break;
        default:
            break;
        }
    }
}

void output_g0_single_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode, int axis)
{
    int32_t line_number = 0;

    switch (mode)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        break;
    default:
        break;
    }

    for (int32_t i = 0; i < line_sum; i++)
    {
        file << "N" << line_number << " G0";
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
            file << get_single_line_value(line_number) << std::endl;
            break;
        case 91:
            file << single_axis_factor << std::endl;
            break;
        default:
            break;
        }

        //judge
        judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
        judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - " << get_single_line_value(line_number) << ")<0.0001) THEN\n";
        judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
        judge_file << "\t\t%QX0.0:=TRUE;\n";
        judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
        judge_file << "\tEND_IF;\n";
        judge_file << "END_IF;\n";

        line_number++;
    }

    judge_file_var << "VAR\tError\t\tARRAY [0.." << line_number << "] OF BOOL\t\t\n";
    judge_file_var << "VAR\tErrorLine\t\tARRAY [0.." << line_number << "] OF UDINT\t\t\n";
}

void output_g0_multiple_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode)
{
    int32_t line_number = 0;

    switch (mode)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            file << "N" << line_number << " G0 X" << get_single_line_value(line_number) << " Y" << get_single_line_value(line_number)
                << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

            //judge
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[2].cmdpos - " << get_single_line_value(line_number)
                << ")<0.0001 & ABS(Axis[3].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[4].cmdpos - " << get_single_line_value(line_number)
                << ")<0.0001 & ABS(Axis[5].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[6].cmdpos - " << get_single_line_value(line_number)
                << ")<0.0001 & ABS(Axis[7].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[8].cmdpos - " << get_single_line_value(line_number) << ")<0.0001) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
        }

        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            file << "N" << line_number << " G0 X" << single_axis_factor << " Y" << single_axis_factor
                << " Z" << single_axis_factor << " A" << single_axis_factor
                << " B" << single_axis_factor << " C" << single_axis_factor
                << " P" << single_axis_factor << " Q" << single_axis_factor << "\n";

            //judge
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[2].cmdpos - " << get_single_line_value(line_number)
                << ")<0.0001 & ABS(Axis[3].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[4].cmdpos - " << get_single_line_value(line_number)
                << ")<0.0001 & ABS(Axis[5].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[6].cmdpos - " << get_single_line_value(line_number)
                << ")<0.0001 & ABS(Axis[7].cmdpos - " << get_single_line_value(line_number) << ")<0.0001 & ABS(Axis[8].cmdpos - " << get_single_line_value(line_number) << ")<0.0001) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
        }

        break;
    default:
        break;
    }

    judge_file_var << "VAR\tError\t\tARRAY [0.." << line_number << "] OF BOOL\t\t\n";
    judge_file_var << "VAR\tErrorLine\t\tARRAY [0.." << line_number << "] OF UDINT\t\t\n";
}

void output_g1_single_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode, int axis)
{
    int32_t line_number = 0;

    switch (mode)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        break;
    default:
        break;
    }

    for (int32_t i = 0; i < line_sum; i++)
    {
        file << "N" << line_number << " G1";
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
            file << get_single_line_value(line_number) << std::endl;
            break;
        case 91:
            file << single_axis_factor << std::endl;
            break;
        default:
            break;
        }

        //judge
        judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
        judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - " << get_single_line_value(line_number) << ")<0.0001) THEN\n";
        judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
        judge_file << "\t\t%QX0.0:=TRUE;\n";
        judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
        judge_file << "\tEND_IF;\n";
        judge_file << "END_IF;\n";

        line_number++;
    }

    judge_file_var << "VAR\tError\t\tARRAY [0.." << line_number << "] OF BOOL\t\t\n";
    judge_file_var << "VAR\tErrorLine\t\tARRAY [0.." << line_number << "] OF UDINT\t\t\n";
}

void output_g1_multiple_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int mode)
{
    int32_t line_number = 0;

    switch (mode)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            file << "N" << line_number << " G1 X" << get_single_line_value(line_number) * x_factor << " Y" << get_single_line_value(line_number) * y_factor
                << " Z" << get_single_line_value(line_number) * z_factor << " A" << get_single_line_value(line_number) * a_factor
                << " B" << get_single_line_value(line_number) * b_factor << " C" << get_single_line_value(line_number) * c_factor
                << " P" << get_single_line_value(line_number) * p_factor << " Q" << get_single_line_value(line_number) * q_factor << "\n";

            //judge
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << get_single_line_value(line_number) * x_factor << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << get_single_line_value(line_number) * y_factor
                << "))<0.0002 & ABS(Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number) * z_factor << "))<0.0002 & ABS(Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number) * a_factor
                << "))<0.0002 & ABS(Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number) * b_factor << "))<0.0002 & ABS(Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number) * c_factor
                << "))<0.0002 & ABS(Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number) * p_factor << "))<0.0002 & ABS(Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number) * q_factor << "))<0.0002) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",1]:=Axis[1].cmdpos - (LREAL#" << get_single_line_value(line_number) * x_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",2]:=Axis[2].cmdpos - (LREAL#" << get_single_line_value(line_number) * y_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",3]:=Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number) * z_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",4]:=Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number) * a_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",5]:=Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number) * b_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",6]:=Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number) * c_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",7]:=Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number) * p_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",8]:=Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number) * q_factor << ");\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
        }

        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            file << "N" << line_number << " G1 X" << single_axis_factor * x_factor << " Y" << single_axis_factor * y_factor
                << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

            //judge
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << get_single_line_value(line_number) * x_factor << "))<0.0001 & ABS(Axis[2].cmdpos - (LREAL#" << get_single_line_value(line_number) * y_factor
                << "))<0.0001 & ABS(Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number) * z_factor << "))<0.0001 & ABS(Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number) * a_factor
                << "))<0.0001 & ABS(Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number) * b_factor << "))<0.0001 & ABS(Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number) * c_factor
                << "))<0.0001 & ABS(Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number) * p_factor << "))<0.0001 & ABS(Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number) * q_factor << "))<0.0001) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",1]:=Axis[1].cmdpos - (LREAL#" << get_single_line_value(line_number) * x_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",2]:=Axis[2].cmdpos - (LREAL#" << get_single_line_value(line_number) * y_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",3]:=Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number) * z_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",4]:=Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number) * a_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",5]:=Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number) * b_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",6]:=Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number) * c_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",7]:=Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number) * p_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",8]:=Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number) * q_factor << ");\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
        }

        break;
    default:
        break;
    }

    judge_file_var << "VAR\tError\t\tARRAY [0.." << line_number << "] OF BOOL\t\t\n";
    judge_file_var << "VAR\tErrorLine\t\tARRAY [0.." << line_number << "] OF UDINT\t\t\n";
    judge_file_var << "VAR\tErrorLinePos\t\tARRAY [0.." << line_number << ",1..8] OF LREAL\t\t\n";
    judge_file_var << "VAR\tErrorLinePosdiff\t\tARRAY [0.." << line_number << ",1..8] OF LREAL\t\t\n";
}

void output_g2_g3_single_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, std::ofstream& judge_pass, int code, int mode, int flat, int method)
{
    int32_t line_number = 0, side = 0;
    point start_point{}, end_point{}, center_point{}, pass_point{};
    start_point.x = 0;
    start_point.y = 0;

    file << "N" << line_number << " G" << flat << "\n";
    line_number++;

    judge_pass << "X_Pos_before := X_Pos_now;\n";
    judge_pass << "Y_Pos_before := Y_Pos_now;\n";
    judge_pass << "X_Pos_now := Axis[1].cmdpos;\n";
    judge_pass << "Y_Pos_now := Axis[2].cmdpos;\n";

    switch (mode)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

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

            center_point = get_center_point(start_point, end_point, radius, side);
            pass_point = get_pass_point(start_point, end_point, radius, code, side);

            switch (method)
            {
            case 0:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y << " I" << center_point.x << " J" << center_point.y << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << end_point.x << " X" << end_point.y << " K" << center_point.x << " I" << center_point.y << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << end_point.x << " Z" << end_point.y << " J" << center_point.x << " K" << center_point.y << "\n";
                    break;
                default:
                    break;
                }
                break;
            case 1:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y << " R" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << end_point.x << " X" << end_point.y << " R" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << end_point.x << " Z" << end_point.y << " R" << radius << "\n";
                    break;
                default:
                    break;
                }
                break;
            case 2:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y << " R-" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << end_point.x << " X" << end_point.y << " R-" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << end_point.x << " Z" << end_point.y << " R-" << radius << "\n";
                    break;
                default:
                    break;
                }

                break;
            default:
                break;
            }

            //judge
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << end_point.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << end_point.y << "))<0.0002) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",1]:=Axis[1].cmdpos - (LREAL#" << end_point.x << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",2]:=Axis[2].cmdpos - (LREAL#" << end_point.y << ");\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            //pass
            output_pass_judge(judge_pass, pass_point, line_number);

            start_point = end_point;
            line_number++;
        }

        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

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

            center_point = get_center_point(start_point, end_point, radius, side);
            pass_point = get_pass_point(start_point, end_point, radius, code, side);

            switch (method)
            {
            case 0:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << chord_long * cos(g2_angle) << " Y" << chord_long * sin(g2_angle) << " I" << center_point.x << " J" << center_point.y << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << chord_long * cos(g2_angle) << " X" << chord_long * sin(g2_angle) << " K" << center_point.x << " I" << center_point.y << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << chord_long * cos(g2_angle) << " Z" << chord_long * sin(g2_angle) << " J" << center_point.x << " K" << center_point.y << "\n";
                    break;
                default:
                    break;
                }
                break;
            case 1:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << chord_long * cos(g2_angle) << " Y" << chord_long * sin(g2_angle) << " R" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << chord_long * cos(g2_angle) << " X" << chord_long * sin(g2_angle) << " R" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << chord_long * cos(g2_angle) << " Z" << chord_long * sin(g2_angle) << " R" << radius << "\n";
                    break;
                default:
                    break;
                }
                break;
            case 2:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << chord_long * cos(g2_angle) << " Y" << chord_long * sin(g2_angle) << " R-" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << chord_long * cos(g2_angle) << " X" << chord_long * sin(g2_angle) << " R-" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << chord_long * cos(g2_angle) << " Z" << chord_long * sin(g2_angle) << " R-" << radius << "\n";
                    break;
                default:
                    break;
                }

                break;
            default:
                break;
            }

            //judge
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << end_point.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << end_point.y << "))<0.0002) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",1]:=Axis[1].cmdpos - (LREAL#" << end_point.x << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",2]:=Axis[2].cmdpos - (LREAL#" << end_point.y << ");\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            //pass
            output_pass_judge(judge_pass, pass_point, line_number);

            start_point = end_point;
            line_number++;
        }

        break;
    default:
        break;
    }

    judge_file_var << "VAR\tError\t\tARRAY [0.." << line_number << "] OF BOOL\t\t\n";
    judge_file_var << "VAR\tErrorLine\t\tARRAY [0.." << line_number << "] OF UDINT\t\t\n";
    judge_file_var << "VAR\tErrorLinePos\t\tARRAY [0.." << line_number << ",1..8] OF LREAL\t\t\n";
    judge_file_var << "VAR\tErrorLinePosdiff\t\tARRAY [0.." << line_number << ",1..8] OF LREAL\t\t\n";
}

void output_g2_g3_multiple_file(std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, std::ofstream& judge_pass, int code, int mode, int flat, int method)
{
    int32_t line_number = 0, side = 0;
    point start_point{}, end_point{}, center_point{}, pass_point{};
    start_point.x = 0;
    start_point.y = 0;

    file << "N" << line_number << " G" << flat << "\n";
    line_number++;

    judge_pass << "X_Pos_before := X_Pos_now;\n";
    judge_pass << "Y_Pos_before := Y_Pos_now;\n";
    judge_pass << "X_Pos_now := Axis[1].cmdpos;\n";
    judge_pass << "Y_Pos_now := Axis[2].cmdpos;\n";

    switch (mode)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

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

            center_point = get_center_point(start_point, end_point, radius, side);
            pass_point = get_pass_point(start_point, end_point, radius, code, side);

            switch (method)
            {
            case 0:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y
                        << " Z" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " I" << center_point.x << " J" << center_point.y << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << end_point.x << " X" << end_point.y
                        << " Y" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " K" << center_point.x << " I" << center_point.y << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << end_point.x << " Z" << end_point.y
                        << " X" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " J" << center_point.x << " K" << center_point.y << "\n";
                    break;
                default:
                    break;
                }
                break;
            case 1:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y
                        << " Z" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " R" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << end_point.x << " X" << end_point.y
                        << " Y" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " R" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << end_point.x << " Z" << end_point.y
                        << " X" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
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
                    file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y
                        << " Z" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " R-" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << end_point.x << " X" << end_point.y
                        << " Y" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
                        << " R-" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << end_point.x << " Z" << end_point.y
                        << " X" << get_single_line_value(line_number - 1) * z_factor << " A" << get_single_line_value(line_number - 1) * a_factor
                        << " B" << get_single_line_value(line_number - 1) * b_factor << " C" << get_single_line_value(line_number - 1) * c_factor
                        << " P" << get_single_line_value(line_number - 1) * p_factor << " Q" << get_single_line_value(line_number - 1) * q_factor
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
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << end_point.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << end_point.y
                << "))<0.0002 & ABS(Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * z_factor << "))<0.0002 & ABS(Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * a_factor
                << "))<0.0002 & ABS(Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * b_factor << "))<0.0002 & ABS(Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * c_factor
                << "))<0.0002 & ABS(Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * p_factor << "))<0.0002 & ABS(Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * q_factor << "))<0.0002) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";

            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",1]:=Axis[1].cmdpos - (LREAL#" << end_point.x << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",2]:=Axis[2].cmdpos - (LREAL#" << end_point.y << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",3]:=Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * z_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",4]:=Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * a_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",5]:=Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * b_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",6]:=Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * c_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",7]:=Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * p_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",8]:=Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * q_factor << ");\n";

            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            output_pass_judge(judge_pass, pass_point, line_number);

            start_point = end_point;
            line_number++;
        }

        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (int32_t i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

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

            center_point = get_center_point(start_point, end_point, radius, side);
            pass_point = get_pass_point(start_point, end_point, radius, code, side);

            switch (method)
            {
            case 0:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << chord_long * cos(g2_angle) << " Y" << chord_long * sin(g2_angle)
                        << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " I" << center_point.x << " J" << center_point.y << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << chord_long * cos(g2_angle) << " X" << chord_long * sin(g2_angle)
                        << " Y" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " K" << center_point.x << " I" << center_point.y << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << chord_long * cos(g2_angle) << " Z" << chord_long * sin(g2_angle)
                        << " X" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " J" << center_point.x << " K" << center_point.y << "\n";
                    break;
                default:
                    break;
                }
                break;
            case 1:
                switch (flat)
                {
                case 17:
                    file << "N" << line_number << " G" << code << " X" << chord_long * cos(g2_angle) << " Y" << chord_long * sin(g2_angle)
                        << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " R" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << chord_long * cos(g2_angle) << " X" << chord_long * sin(g2_angle)
                        << " Y" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " R" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << chord_long * cos(g2_angle) << " Z" << chord_long * sin(g2_angle)
                        << " X" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
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
                    file << "N" << line_number << " G" << code << " X" << chord_long * cos(g2_angle) << " Y" << chord_long * sin(g2_angle)
                        << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " R-" << radius << "\n";
                    break;
                case 18:
                    file << "N" << line_number << " G" << code << " Z" << chord_long * cos(g2_angle) << " X" << chord_long * sin(g2_angle)
                        << " Y" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                        << " R-" << radius << "\n";
                    break;
                case 19:
                    file << "N" << line_number << " G" << code << " Y" << chord_long * cos(g2_angle) << " Z" << chord_long * sin(g2_angle)
                        << " X" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                        << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                        << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
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
            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - (LREAL#" << end_point.x << "))<0.0002 & ABS(Axis[2].cmdpos - (LREAL#" << end_point.y
                << "))<0.0001 & ABS(Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * z_factor << "))<0.0001 & ABS(Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * a_factor
                << "))<0.0001 & ABS(Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * b_factor << "))<0.0001 & ABS(Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * c_factor
                << "))<0.0001 & ABS(Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * p_factor << "))<0.0001 & ABS(Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * q_factor << "))<0.0002) THEN\n";
            judge_file << "\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";

            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",1]:=Axis[1].cmdpos - (LREAL#" << end_point.x << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",2]:=Axis[2].cmdpos - (LREAL#" << end_point.y << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",3]:=Axis[3].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * z_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",4]:=Axis[4].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * a_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",5]:=Axis[5].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * b_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",6]:=Axis[6].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * c_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",7]:=Axis[7].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * p_factor << ");\n";
            judge_file << "\t\tErrorLinePosdiff[" << line_number << ",8]:=Axis[8].cmdpos - (LREAL#" << get_single_line_value(line_number - 1) * q_factor << ");\n";

            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            output_pass_judge(judge_pass, pass_point, line_number);

            start_point = end_point;
            line_number++;
        }

        break;
    default:
        break;
    }

    judge_file_var << "VAR\tError\t\tARRAY [0.." << line_number << "] OF BOOL\t\t\n";
    judge_file_var << "VAR\tErrorLine\t\tARRAY [0.." << line_number << "] OF UDINT\t\t\n";
    judge_file_var << "VAR\tErrorLinePos\t\tARRAY [0.." << line_number << ",1..8] OF LREAL\t\t\n";
    judge_file_var << "VAR\tErrorLinePosdiff\t\tARRAY [0.." << line_number << ",1..8] OF LREAL\t\t\n";
}

double get_single_line_value(int32_t line_number)
{
    return line_number * single_axis_factor;
}

point get_center_point(point start_point, point end_point, double radius, int which_side)
{
    point center_point{};
    point middle_point{};
    middle_point.x = start_point.x + (end_point.x - start_point.x) / 2;
    middle_point.y = start_point.y + (end_point.y - start_point.y) / 2;

    double one_side_line_long = sqrt(pow(radius, 2) - (pow(middle_point.x - start_point.x, 2) + pow(middle_point.y - start_point.y, 2)));

    double vector_x = middle_point.x - start_point.x;
    double vector_y = middle_point.y - start_point.y;

    double offset_x = (one_side_line_long * vector_y) / sqrt(pow(vector_y, 2) + pow(vector_x, 2));
    double offset_y = -(offset_x * vector_x) / vector_y;

    switch (which_side)
    {
    case 0:
        center_point.x = middle_point.x + offset_x - start_point.x;
        center_point.y = middle_point.y + offset_y - start_point.y;
        break;
    case 1:
        center_point.x = middle_point.x - offset_x - start_point.x;
        center_point.y = middle_point.y - offset_y - start_point.y;
        break;
    default:
        center_point.x = middle_point.x + offset_x - start_point.x;
        center_point.y = middle_point.y + offset_y - start_point.y;
        break;
    }

    return center_point;
}

point get_pass_point(point start_point, point end_point, double radius, int code, int which_side)
{
    point center_point = get_center_point(start_point, end_point, radius, which_side);

    point pass_point;

    pass_point.x = (start_point.x + end_point.x) / 2;
    pass_point.y = 0;

    double a = center_point.x + start_point.x;
    double b = center_point.y + start_point.y;
    double r = radius;
    double x = pass_point.x;

    double y1 = b - sqrt(-pow(a, 2) + 2 * a * x + pow(r, 2) - pow(x, 2));
    double y2 = sqrt(-pow(a, 2) + 2 * a * x + pow(r, 2) - pow(x, 2)) + b;

    if (start_point.x > a && end_point.x > a)
    {
        //起点终点的X轴坐标都大于圆心的X坐标
        if (start_point.y <= b && end_point.y <= b)
        {
            //起点终点的X轴坐标都大于圆心的X坐标 且 起点终点的Y轴坐标都小于圆心的Y坐标 -->都在第四象限
            pass_point.y = y1;//Y值为负
        }
        else if (start_point.y >= b && end_point.y >= b)
        {
            //起点终点的X轴坐标都大于圆心的X坐标 且 起点终点的Y轴坐标都大于圆心的Y坐标 -->都在第一象限
            pass_point.y = y2;//Y值为正
        }
        else if (start_point.y <= b && end_point.y >= b)
        {
            //起点终点的X轴坐标都大于圆心的X坐标 且 起点Y小于圆心Y终点大于圆心
            if (code == 2)
            {
                if (y1 < start_point.y)
                {
                    pass_point.y = y1;
                }
                else if (y1 > start_point.y)
                {
                    pass_point.y = y2;
                }
            }
            else if (code == 3)
            {
                if (y1 < start_point.y)
                {
                    pass_point.y = y2;
                }
                else if (y1 > start_point.y)
                {
                    pass_point.y = y1;
                }
            }
        }
        else if (start_point.y >= b && end_point.y <= b)
        {
            //起点终点的X轴坐标都大于圆心的X坐标 且 起点Y大于圆心Y终点小于圆心
            if (code == 2)
            {
                if (y2 < start_point.y)
                {
                    pass_point.y = y2;
                }
                else if (y2 > start_point.y)
                {
                    pass_point.y = y1;
                }
            }
            else if (code == 3)
            {
                if (y2 < start_point.y)
                {
                    pass_point.y = y1;
                }
                else if (y2 > start_point.y)
                {
                    pass_point.y = y2;
                }
            }
        }
    }
    else if (start_point.x < a && end_point.x < a)
    {
        //起点和终点X坐标都小于圆心的X坐标
        if (start_point.y <= b && end_point.y <= b)
        {
            //起点终点的X轴坐标都小于圆心的X坐标 且 起点终点的Y轴坐标都小于圆心的Y坐标 -->都在第三象限
            pass_point.y = y1;//Y值为负
        }
        else if (start_point.y >= b && end_point.y >= b)
        {
            //起点终点的X轴坐标都小于圆心的X坐标 且 起点终点的Y轴坐标都大于圆心的Y坐标 -->都在第二象限
            pass_point.y = y2;//Y值为正
        }
        else if (start_point.y <= b && end_point.y >= b)
        {
            //起点终点的X轴坐标都小于圆心的X坐标 且 起点Y小于圆心Y终点大于圆心
            if (code == 2)
            {
                if (y1 < start_point.y)
                {
                    pass_point.y = y2;
                }
                else if (y1 > start_point.y)
                {
                    pass_point.y = y1;
                }
            }
            else if (code == 3)
            {
                if (y1 < start_point.y)
                {
                    pass_point.y = y1;
                }
                else if (y1 > start_point.y)
                {
                    pass_point.y = y2;
                }
            }
        }
        else if (start_point.y >= b && end_point.y <= b)
        {
            //起点终点的X轴坐标都小于圆心的X坐标 且 起点Y大于圆心Y终点小于圆心
            if (code == 2)
            {
                if (y2 < start_point.y)
                {
                    pass_point.y = y1;
                }
                else if (y2 > start_point.y)
                {
                    pass_point.y = y2;
                }
            }
            else if (code == 3)
            {
                if (y2 < start_point.y)
                {
                    pass_point.y = y2;
                }
                else if (y2 > start_point.y)
                {
                    pass_point.y = y1;
                }
            }
        }
    }

    return pass_point;
}

void output_pass_judge(std::ofstream& judge_pass, point pass_point, int32_t line_number)
{
    //pass
    judge_pass << "IF (NC_CurrentLine = " << line_number + 1 << ") THEN\n";
    judge_pass << "\tIF ((X_Pos_before < LREAL#" << pass_point.x << ") & (X_Pos_now >= LREAL#" << pass_point.x << ")) OR ((X_Pos_before > LREAL#" << pass_point.x << ") & (X_Pos_now <= LREAL#" << pass_point.x << ")) THEN\n";
    judge_pass << "\t\tIF NOT(((Y_Pos_before < LREAL#" << pass_point.y << ") & (Y_Pos_now >= LREAL#" << pass_point.y << ")) OR ((Y_Pos_before > LREAL#" << pass_point.y << ") & (Y_Pos_now <= LREAL#" << pass_point.y << ")))THEN\n";
    judge_pass << "\t\t\tError[" << line_number << "]:=TRUE;\n";
    judge_pass << "\t\t\t%QX0.5:=TRUE;\n";
    judge_pass << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
    judge_pass << "\t\t\tErrorLinePosBefore[" << line_number << ",1]:=X_Pos_before;\n";
    judge_pass << "\t\t\tErrorLinePosBefore[" << line_number << ",2]:=Y_Pos_before;\n";
    judge_pass << "\t\t\tErrorLinePosNow[" << line_number << ",1]:=X_Pos_now;\n";
    judge_pass << "\t\t\tErrorLinePosNow[" << line_number << ",2]:=Y_Pos_now;\n";
    judge_pass << "\t\tEND_IF;\n";
    judge_pass << "\tEND_IF;\n";
    judge_pass << "END_IF;\n";
}

void output_first_gcode_is_g0_file(int second_gcode, std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int relative)
{
    int32_t line_number = 0, side = 0;
    point start_point{}, end_point{}, center_point{}, pass_point{};
    start_point.x = 0;
    start_point.y = 0;

    switch (relative)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (auto i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            file << "N" << line_number << " G0 X" << end_point.x << " Y" << end_point.y
                << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;

            start_point = end_point;
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            switch (second_gcode)
            {
            case 0:
                file << "N" << line_number << " G0 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

                break;
            case 1:
                file << "N" << line_number << " G1 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

                break;
            case 2:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 3:
                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R" << radius << "\n";

                break;
            case 4:
                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R-" << radius << "\n";

                break;

            case 5:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 6:
                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R" << radius << "\n";

                break;
            case 7:
                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R-" << radius << "\n";
                break;

            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorVel[" << line_number << "]:=Vel;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
            start_point = end_point;
        }
        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (auto i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            file << "N" << line_number << " G0 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number) * a_factor
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number) * c_factor
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) * q_factor << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;

            start_point = end_point;
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            switch (second_gcode)
            {
            case 0:
                file << "N" << line_number << " G0 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

                break;
            case 1:
                file << "N" << line_number << " G1 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

                break;
            case 2:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 3:
                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R" << radius << "\n";

                break;
            case 4:
                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R-" << radius << "\n";

                break;

            case 5:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 6:
                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R" << radius << "\n";

                break;
            case 7:
                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R-" << radius << "\n";
                break;

            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number) * a_factor
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number) * c_factor
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) * q_factor << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorVel[" << line_number << "]:=Vel;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
            start_point = end_point;
        }

        break;
    default:
        break;
    }
}

void output_first_gcode_is_g1_file(int second_gcode, std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int relative)
{
    int32_t line_number = 0, side = 0;
    point start_point{}, end_point{}, center_point{}, pass_point{};
    start_point.x = 0;
    start_point.y = 0;

    switch (relative)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (auto i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            file << "N" << line_number << " G1 X" << end_point.x << " Y" << end_point.y
                << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;

            start_point = end_point;
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            switch (second_gcode)
            {
            case 0:
                file << "N" << line_number << " G0 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

                break;
            case 1:
                file << "N" << line_number << " G1 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

                break;
            case 2:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 3:
                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R" << radius << "\n";

                break;
            case 4:
                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R-" << radius << "\n";

                break;

            case 5:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 6:
                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R" << radius << "\n";

                break;
            case 7:
                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R-" << radius << "\n";
                break;

            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorVel[" << line_number << "]:=Vel;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
            start_point = end_point;
        }
        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (auto i = 0; i < line_sum; i++)
        {
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            file << "N" << line_number << " G1 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number) * a_factor
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number) * c_factor
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) * q_factor << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;

            start_point = end_point;
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            switch (second_gcode)
            {
            case 0:
                file << "N" << line_number << " G0 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

                break;
            case 1:
                file << "N" << line_number << " G1 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

                break;
            case 2:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 3:
                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R" << radius << "\n";

                break;
            case 4:
                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R-" << radius << "\n";

                break;

            case 5:
                center_point = get_center_point(start_point, end_point, radius, side);

                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 6:
                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R" << radius << "\n";

                break;
            case 7:
                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R-" << radius << "\n";
                break;

            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number) * a_factor
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number) * c_factor
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) * q_factor << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorVel[" << line_number << "]:=Vel;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
            start_point = end_point;
        }

        break;
    default:
        break;
    }
}

void output_first_gcode_is_circle_file(int second_gcode, std::ofstream& file, std::ofstream& judge_file, std::ofstream& judge_file_var, int relative, int code, int type)
{
    int32_t line_number = 0, side = 0;
    point start_point{}, end_point{}, center_point{}, pass_point{};
    start_point.x = 0;
    start_point.y = 0;

    switch (relative)
    {
    case 90:
        file << "N" << line_number << " G90\n";
        line_number++;
        for (auto i = 0; i < line_sum; i++)
        {
            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);
            center_point = get_center_point(start_point, end_point, radius, side);

            file << "N" << line_number << " G" << code << " X" << end_point.x << " Y" << end_point.y
                << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number);
            switch (type)
            {
            case 0:
                file << " I" << center_point.x << " J" << center_point.y << "\n";
                break;
            case 1:
                file << " R" << radius << "\n";
                break;
            case 2:
                file << " R-" << radius << "\n";
            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;

            start_point = end_point;
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            switch (second_gcode)
            {
            case 0:
                file << "N" << line_number << " G0 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

                break;
            case 1:
                file << "N" << line_number << " G1 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number) << "\n";

                break;
            case 2:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 2, side);

                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 3:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 2, side);

                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R" << radius << "\n";

                break;
            case 4:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 2, side);

                file << "N" << line_number << " G2 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R-" << radius << "\n";

                break;

            case 5:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 3, side);

                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 6:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 3, side);

                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R" << radius << "\n";

                break;
            case 7:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 3, side);

                file << "N" << line_number << " G3 X" << end_point.x << " Y" << end_point.y
                    << " Z" << get_single_line_value(line_number) << " A" << get_single_line_value(line_number)
                    << " B" << get_single_line_value(line_number) << " C" << get_single_line_value(line_number)
                    << " P" << get_single_line_value(line_number) << " Q" << get_single_line_value(line_number)
                    << " R-" << radius << "\n";
                break;

            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number)
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorVel[" << line_number << "]:=Vel;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
            start_point = end_point;
        }
        break;
    case 91:
        file << "N" << line_number << " G91\n";
        line_number++;
        for (auto i = 0; i < line_sum; i++)
        {
            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);
            center_point = get_center_point(start_point, end_point, radius, side);

            file << "N" << line_number << " G" << code << " X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor;
            switch (type)
            {
            case 0:
                file << " I" << center_point.x << " J" << center_point.y << "\n";
                break;
            case 1:
                file << " R" << radius << "\n";
                break;
            case 2:
                file << " R-" << radius << "\n";
            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number) * a_factor
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number) * c_factor
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) * q_factor << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;

            start_point = end_point;
            end_point.x = start_point.x + chord_long * cos(g2_angle);
            end_point.y = start_point.y + chord_long * sin(g2_angle);

            if (side == 0)
            {
                side = 1;
            }
            else
            {
                side = 0;
            }

            switch (second_gcode)
            {
            case 0:
                file << "N" << line_number << " G0 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

                break;
            case 1:
                file << "N" << line_number << " G1 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor << "\n";

                break;
            case 2:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 2, side);

                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 3:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 2, side);

                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R" << radius << "\n";

                break;
            case 4:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 2, side);

                file << "N" << line_number << " G2 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R-" << radius << "\n";

                break;

            case 5:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 3, side);

                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " I" << center_point.x << " J" << center_point.y << "\n";

                break;
            case 6:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 3, side);

                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R" << radius << "\n";

                break;
            case 7:
                center_point = get_center_point(start_point, end_point, radius, side);

                pass_point = get_pass_point(start_point, end_point, radius, 3, side);

                file << "N" << line_number << " G3 X" << end_point.x - start_point.x << " Y" << end_point.y - start_point.y
                    << " Z" << single_axis_factor * z_factor << " A" << single_axis_factor * a_factor
                    << " B" << single_axis_factor * b_factor << " C" << single_axis_factor * c_factor
                    << " P" << single_axis_factor * p_factor << " Q" << single_axis_factor * q_factor
                    << " R-" << radius << "\n";
                break;

            default:
                break;
            }

            judge_file << "IF EDGEPOS(NC_CurrentLine = " << line_number + 2 << ") THEN\n";
            judge_file << "\tIF NOT (ABS(Axis[1].cmdpos - LREAL#" << end_point.x << ")<0.001 & ABS(Axis[2].cmdpos - LREAL#" << end_point.y
                << ")<0.001 & ABS(Axis[3].cmdpos - LREAL#" << get_single_line_value(line_number) * z_factor << ")<0.001 & ABS(Axis[4].cmdpos - LREAL#" << get_single_line_value(line_number) * a_factor
                << ")<0.001 & ABS(Axis[5].cmdpos - LREAL#" << get_single_line_value(line_number) * b_factor << ")<0.001 & ABS(Axis[6].cmdpos - LREAL#" << get_single_line_value(line_number) * c_factor
                << ")<0.001 & ABS(Axis[7].cmdpos - LREAL#" << get_single_line_value(line_number) * p_factor << ")<0.001 & ABS(Axis[8].cmdpos - LREAL#" << get_single_line_value(line_number) * q_factor << ")<0.001) THEN\n";
            judge_file << "\t\tIF NOT(ABS(vel-0)<0.01) THEN\n";
            judge_file << "\t\t\tError[" << line_number << "]:=TRUE;\n";
            judge_file << "\t\t\t%QX0.0:=TRUE;\n";
            judge_file << "\t\t\tErrorVel[" << line_number << "]:=Vel;\n";
            judge_file << "\t\t\tErrorLine[" << line_number << "]:=NC_CurrentLine;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",1]:=Axis[1].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",2]:=Axis[2].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",3]:=Axis[3].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",4]:=Axis[4].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",5]:=Axis[5].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",6]:=Axis[6].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",7]:=Axis[7].cmdpos;\n";
            judge_file << "\t\t\tErrorLinePos[" << line_number << ",8]:=Axis[8].cmdpos;\n";
            judge_file << "\t\tEND_IF;\n";
            judge_file << "\tEND_IF;\n";
            judge_file << "END_IF;\n";

            line_number++;
            start_point = end_point;
        }

        break;
    default:
        break;
    }
}
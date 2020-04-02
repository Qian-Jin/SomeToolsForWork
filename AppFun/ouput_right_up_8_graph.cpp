#include "ouput_right_up_8_graph.h"

#include <corecrt_math_defines.h>

void output_right_up_8_graph_g_code_file()
{
    line_long = 5;
    first_angle = 45;
    angle = 90;
    flat_global = 17;

    m_code_type = 0;
    m_code_value = 0;

    std::ofstream outfile, outfileJudge;
    outfile.open("G_code.txt", std::ios::out, std::ios::trunc);
    outfileJudge.open("G_code_posjudge.txt", std::ios::out, std::ios::trunc);
    outfile.precision(10);
    outfileJudge.precision(10);
    output_gcode_file(outfile, outfileJudge);
    outfile.close();
    outfileJudge.close();
}

void output_g1(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q)
{
    //M代码只能放到后面
    //if (m_code_type == 0)
    //{
    //	if (m_code_value == 0)
    //	{
    //		file << "N" << line_number << " M" << a << " D" << a*m_code_factor << " G1 ";

    //	}
    //	else if (m_code_value == 1)
    //	{
    //		file << "N" << line_number << " M" << a <<  " G1 ";
    //	}
    //}
    //else if (m_code_type == 1)
    //{
    //	file << "N" << line_number << " G1 ";
    //}

    file << "N" << line_number << " G1 ";

    switch (flat)
    {
    case 17:
        file << "X" << flat_x << " ";
        file << "Y" << flat_y << " ";
        file << "Z" << flat_z << " ";
        break;
    case 18:
        file << "X" << flat_y << " ";
        file << "Y" << flat_z << " ";
        file << "Z" << flat_x << " ";
        break;
    case 19:
        file << "X" << flat_z << " ";
        file << "Y" << flat_x << " ";
        file << "Z" << flat_y << " ";
        break;
    default:
        break;
    }

    file << "A" << a << " ";
    file << "B" << b << " ";
    file << "C" << c << " ";
    file << "P" << p << " ";
    file << "Q" << q << " ";
    if (m_code_type == 0)
    {
        if (m_code_value == 0)
        {
            file << "M" << a << " D" << (a + 1) * m_code_factor;
        }
        else if (m_code_value == 1)
        {
            file << "M" << a;
        }
    }
    else if (m_code_type == 1)
    {
        ;
    }

    file << std::endl;
}

void output_g2_center(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double flat_i, double flat_j, int32_t t)
{
    switch (flat)
    {
    case 17:
        file << "N" << line_number << " G2 ";
        file << "X" << flat_x << " ";
        file << "Y" << flat_y << " ";
        file << "Z" << flat_z << " ";
        file << "A" << a << " ";
        file << "B" << b << " ";
        file << "C" << c << " ";
        file << "P" << p << " ";
        file << "Q" << q << " ";
        file << "I" << flat_i << " ";
        file << "J" << flat_j << " ";
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
        file << "N" << line_number << " G2 ";
        file << "X" << flat_y << " ";
        file << "Y" << flat_z << " ";
        file << "Z" << flat_x << " ";
        file << "A" << a << " ";
        file << "B" << b << " ";
        file << "C" << c << " ";
        file << "P" << p << " ";
        file << "Q" << q << " ";
        file << "I" << flat_j << " ";
        file << "K" << flat_i << " ";
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
        file << "N" << line_number << " G2 ";
        file << "X" << flat_z << " ";
        file << "Y" << flat_x << " ";
        file << "Z" << flat_y << " ";
        file << "A" << a << " ";
        file << "B" << b << " ";
        file << "C" << c << " ";
        file << "P" << p << " ";
        file << "Q" << q << " ";
        file << "J" << flat_i << " ";
        file << "K" << flat_j << " ";
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

void output_g2_radius(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double r, int32_t t)
{
    switch (flat)
    {
    case 17:
        file << "N" << line_number << " G2 ";
        file << "X" << flat_x << " ";
        file << "Y" << flat_y << " ";
        file << "Z" << flat_z << " ";
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
        file << "N" << line_number << " G2 ";
        file << "X" << flat_y << " ";
        file << "Y" << flat_z << " ";
        file << "Z" << flat_x << " ";
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
        file << "N" << line_number << " G2 ";
        file << "X" << flat_z << " ";
        file << "Y" << flat_x << " ";
        file << "Z" << flat_y << " ";
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

void output_g3_center(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double flat_i, double flat_j, int32_t t)
{
    switch (flat)
    {
    case 17:
        file << "N" << line_number << " G3 ";
        file << "X" << flat_x << " ";
        file << "Y" << flat_y << " ";
        file << "Z" << flat_z << " ";
        file << "A" << a << " ";
        file << "B" << b << " ";
        file << "C" << c << " ";
        file << "P" << p << " ";
        file << "Q" << q << " ";
        file << "I" << flat_i << " ";
        file << "J" << flat_j << " ";
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
        file << "N" << line_number << " G3 ";
        file << "X" << flat_y << " ";
        file << "Y" << flat_z << " ";
        file << "Z" << flat_x << " ";
        file << "A" << a << " ";
        file << "B" << b << " ";
        file << "C" << c << " ";
        file << "P" << p << " ";
        file << "Q" << q << " ";
        file << "I" << flat_j << " ";
        file << "K" << flat_i << " ";
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
        file << "N" << line_number << " G3 ";
        file << "X" << flat_z << " ";
        file << "Y" << flat_x << " ";
        file << "Z" << flat_y << " ";
        file << "A" << a << " ";
        file << "B" << b << " ";
        file << "C" << c << " ";
        file << "P" << p << " ";
        file << "Q" << q << " ";
        file << "J" << flat_i << " ";
        file << "K" << flat_j << " ";
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

void output_g3_radius(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q, double r, int32_t t)
{
    switch (flat)
    {
    case 17:
        file << "N" << line_number << " G3 ";
        file << "X" << flat_x << " ";
        file << "Y" << flat_y << " ";
        file << "Z" << flat_z << " ";
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
        file << "N" << line_number << " G3 ";
        file << "X" << flat_y << " ";
        file << "Y" << flat_z << " ";
        file << "Z" << flat_x << " ";
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
        file << "N" << line_number << " G3 ";
        file << "X" << flat_z << " ";
        file << "Y" << flat_x << " ";
        file << "Z" << flat_y << " ";
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

void output_gcode_judge(std::ofstream& file, int32_t line_number, int flat, double flat_x, double flat_y, double flat_z, double a, double b, double c, double p, double q)
{
    file << "IF EDGEPOS(NC_Currentline = " << line_number << ") THEN\n";
    file << "\tA:=0;\n";
    file << "\tIF NOT ((ABS(Axis[1].cmdpos - (";
    switch (flat)
    {
    case 17:
        file << flat_x;
        break;
    case 18:
        file << flat_y;
        break;
    case 19:
        file << flat_z;

        break;
    default:
        break;
    }
    file << ")) < 0.01) & (ABS(Axis[2].cmdpos - (";
    switch (flat)
    {
    case 17:
        file << flat_y;
        break;
    case 18:
        file << flat_z;
        break;
    case 19:
        file << flat_x;

        break;
    default:
        break;
    }
    file << ")) < 0.01) & (ABS(Axis[3].cmdpos - (";
    switch (flat)
    {
    case 17:
        file << flat_z;
        break;
    case 18:
        file << flat_x;
        break;
    case 19:
        file << flat_y;
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

void output_mcode_judge(std::ofstream& file, int32_t line_number, int i)
{
    if (m_code_type == 0)
    {
        file << "IF (NC_Currentline = " << line_number << ") THEN\n";
    }
    else if (m_code_type == 1)
    {
        file << "IF (NC_Currentline = " << line_number + 1 << ") THEN\n";
    }

    //	file << "\tA:=0;\n";
    file << "\tA:=A+1;\n";
    file << "\tIF A=2 THEN\n";

    if (m_code_value == 0)
    {
        file << "\t\tIF (AxesGroup[1].M_Function[" << i << "] = 1) & (ABS(AxesGroup[1].M_Value[" << i << "] - " << (i + 1) * m_code_factor << ")<1E-3 ) & (\n";
        if (m_code_type == 0)
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
        else if (m_code_type == 1)
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
    else if (m_code_value == 1)
    {
        file << "\t\tIF (AxesGroup[1].M_Function[" << i << "] = 1) & (\n";
        if (m_code_type == 0)
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
        else if (m_code_type == 1)
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

    if (m_code_type == 0)
    {
        file << "\t\t\t;\n";
    }
    else if (m_code_type == 1)
    {
        file << "\t\t\tAxesGroup[1].M_Function[" << i << "] := 0;\n";
    }

    file << "\t\tELSE\n\t\t\tError1 := TRUE;\n";
    file << "\t\t\tMError[" << i << "] := AxesGroup[1].M_Function;\n";
    file << "\t\t\tlineError1[" << i << "] := NC_Currentline;\n";
    file << "\t\t\tErrorValue[" << i << "]:=ABS(AxesGroup[1].M_Value[" << i << "] - " << i * m_code_factor << ");\n";
    file << "\t\tEND_IF;\n";
    file << "\tEND_IF;\n";
    file << "END_IF;\n";
}

void output_gcode_file(std::ofstream& file, std::ofstream& judge_file)
{
    base_pointer start_point{};
    base_pointer end_point{};
    //	base_pointer center_point;
    start_point.x = 0.0;
    start_point.y = 0.0;

    file << "N0 G50\nN1 G" << flat_global << std::endl;

    int32_t line_number = 2;
    for (int32_t i = 0; i <= 99; i++)
    {
        end_point = f_right_up_trapezium_8(i);

        if ((end_point.x < 1e-5) && (end_point.x > -1e-5))
        {
            end_point.x = 0.0;
        }
        if ((end_point.y < 1e-5) && (end_point.y > -1e-5))
        {
            end_point.y = 0.0;
        }

        //		output_mcode_judge(judge_file, line_number, i);

        int32_t judge_line_number = line_number + 1;
        switch (i % 8)
        {
        case 0:
            //			center_point = get_circle_center_point(start_point, end_point);
            //			output_g2_center(file, line_number, flat_global, end_point.x, end_point.y, i*10, i*50, i*30, i*70, i*100, i*115, center_point.x, center_point.y, i / 8);
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 1:
            //			center_point = get_circle_center_point(start_point, end_point);
            //			output_g3_center(file, line_number, flat_global, end_point.x, end_point.y, i*23, i*85, i*46, i*76, i*12, i*130, center_point.x, center_point.y, i / 8);
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 2:
            //			output_g2_radius(file, line_number, flat_global, end_point.x, end_point.y, i*121, i*25, i*49, i*63, i*42, i*28, line_long + i, i / 8);
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 3:
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 4:
            //			output_g3_radius(file, line_number, flat_global, end_point.x, end_point.y, i*99, i*84, i*73, i*27, i*78, i*42, line_long + i, i / 8);
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 5:
            //			output_g3_radius(file, line_number, flat_global, end_point.x, end_point.y, i*88, i*37, i*72, i*44, i*63, i*82, -(line_long + i), i / 8);
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 6:
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        case 7:
            //			output_g2_radius(file, line_number, flat_global, end_point.x, end_point.y, i*45, i*62, i*49, i*73, i*61, i*85, -(line_long + i), i / 8);
            output_g1(file, line_number, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);
            break;
        default:
            break;
        }
        output_gcode_judge(judge_file, judge_line_number + 1, flat_global, end_point.x, end_point.y, i, i, i, i, i, i);

        line_number++;

        if (m_code_type == 0)
        {
            output_mcode_judge(judge_file, line_number, i);
        }
        else if (m_code_type == 1)
        {
            if (m_code_value == 0)
            {
                file << "N" << line_number << " M" << i << " D" << (i + 1) * m_code_factor << std::endl;
            }
            else if (m_code_value == 1)
            {
                file << "N" << line_number << " M" << i << std::endl;
            }
            output_mcode_judge(judge_file, line_number, i);
            line_number++;
        }

        start_point = end_point;
    }
}

//得到园心点 返回一个在x轴上的圆心点
base_pointer get_circle_center_point(base_pointer start_point, base_pointer end_point)
{
    base_pointer center_point;
    double center_absolute_X = (-(start_point.y + end_point.y) / 2) / (-(end_point.x - start_point.x) / (end_point.y - start_point.y)) + (start_point.x + end_point.x) / 2;
    double center_absolute_Y = 0.0;
    center_point.x = center_absolute_X - start_point.x;
    center_point.y = center_absolute_Y - start_point.y;
    return center_point;
}

base_pointer f_right_up_trapezium_8(int x)
{
    base_pointer pointer[4];
    base_pointer outpoint{};
    if ((angle >= 90) && (angle <= 180))
    {
        if (angle == 180)
        {
            outpoint.x = line_long * (x + 1);
            outpoint.y = line_long * (x + 1);
        }
        else
        {
            pointer[0].x = line_long * cos(first_angle / 180 * M_PI);
            pointer[0].y = line_long * sin(first_angle / 180 * M_PI);
            auto second_line = line_long * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
            pointer[1].x = second_line * cos(((180 - angle) / 2 + first_angle) / 180 * M_PI);
            pointer[1].y = second_line * sin(((180 - angle) / 2 + first_angle) / 180 * M_PI);
            pointer[2].x = pointer[1].x + line_long * cos(first_angle / 180 * M_PI);
            pointer[2].y = pointer[1].y + line_long * sin(first_angle / 180 * M_PI);
            pointer[3].x = 2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI)) * cos(first_angle / 180 * M_PI);
            pointer[3].y = 2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI)) * sin(first_angle / 180 * M_PI);

            outpoint.x = pointer[x % 4].x + (x / 4) * (2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI))) * cos(first_angle / 180 * M_PI);
            outpoint.y = pointer[x % 4].y + (x / 4) * (2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI))) * sin(first_angle / 180 * M_PI);
        }
    }
    else
    {
        pointer[0].x = line_long * cos(first_angle / 180 * M_PI);
        pointer[0].y = line_long * sin(first_angle / 180 * M_PI);
        auto second_line = line_long * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
        pointer[1].x = second_line * cos((first_angle + (180 - angle) / 2) / 180 * M_PI);
        pointer[1].y = second_line * sin((first_angle + (180 - angle) / 2) / 180 * M_PI);
        pointer[2].x = pointer[1].x + line_long * cos(first_angle / 180 * M_PI);
        pointer[2].y = pointer[1].y + line_long * sin(first_angle / 180 * M_PI);
        auto forth_line = second_line * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
        pointer[3].x = forth_line * cos(first_angle / 180 * M_PI);
        pointer[3].y = forth_line * sin(first_angle / 180 * M_PI);

        outpoint.x = pointer[x % 4].x + (x / 4) * forth_line * cos(first_angle / 180 * M_PI);
        outpoint.y = pointer[x % 4].y + (x / 4) * forth_line * sin(first_angle / 180 * M_PI);
    }
    return outpoint;
}
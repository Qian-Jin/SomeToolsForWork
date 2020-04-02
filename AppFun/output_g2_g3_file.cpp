#include "output_g2_g3_file.h"
#include <cmath>
#include <corecrt_math_defines.h>

const double for_time = 361;
const double for_step = 0.5;
const int circle_time = 2;

void output_gcode_circle_file(int curve_type, int flat, int method)
{
    std::ofstream outfile;
    outfile.open("G_code.txt", std::ios::out, std::ios::trunc);
    output_circle_file(outfile, curve_type, flat, method);
    outfile.close();
}

//circle_type
//0:sin曲线随机取结束点，之后随机取圆心
//1:圆心在X轴上，半径固定
//2:向右上画弧
//3:画半径不同的圆
//4:根据给定角度画圆
const int circle_type = 4;

//G2&G3

//得到圆的末端点
circle_point get_circle_end_point(circle_point start_point)
{
    circle_point endpoint{};
    double offset;
    switch (circle_type)
    {
    case 0:
        offset = fmod(rand(), 10) + 1.0;
        endpoint.x = start_point.x + offset;
        endpoint.y = 10 * sin(endpoint.x);
        break;
    case 1:
        offset = 1.0 * 2;
        endpoint.x = start_point.x + offset;
        endpoint.y = start_point.y;
        break;
    case 2:
        endpoint.x = start_point.x + 1.0;
        endpoint.y = sqrt(pow(start_point.y, 2) + pow(1.0, 2));
        break;
    case 3:
        endpoint = start_point;
        break;
    default:
        offset = fmod(rand(), 10) + 1.0;
        endpoint.x = start_point.x + offset;
        endpoint.y = 10 * sin(endpoint.x);
        break;
    }
    return endpoint;
}

//得到园心点
circle_point get_circle_center_point(circle_point start_point, circle_point end_point)
{
    circle_point center_point{};
    double offset;
    static int times = 0;

    times++;
    switch (circle_type)
    {
    case 0:
        offset = fmod(rand(), 4.5) + 2.5;
        center_point.x = start_point.x + offset;
        center_point.y = (-(end_point.x - start_point.x) / (end_point.y - start_point.y)) * (center_point.x - (start_point.x + end_point.x) / 2) + (start_point.y + end_point.y) / 2;
        break;
    case 1:
        offset = (end_point.x - start_point.x) / 2;
        center_point.x = start_point.x + offset;
        center_point.y = start_point.y;
        break;
    case 2:
        center_point.x = start_point.x + 1.0;
        center_point.y = 0.0;
        break;
    case 3:
        center_point.x = start_point.x + 0.5 * times;
        center_point.y = start_point.y;
        break;
    default:
        offset = fmod(rand(), 4.5) + 2.5;
        center_point.x = start_point.x + offset;
        center_point.y = (-(end_point.x - start_point.x) / (end_point.y - start_point.y)) * (center_point.x - (start_point.x + end_point.x) / 2) + (start_point.y + end_point.y) / 2;
        break;
    }
    return center_point;
}

//根据起点产生圆心位置
circle_point get_random_center_point(circle_point start_point)
{
    circle_point center_point{};
    double circle_radius = 1000.0;
    double angle = 0.0 / 180.0 * M_PI;
    center_point.x = start_point.x + circle_radius * cos(angle);
    center_point.y = start_point.y + circle_radius * sin(angle);
    return center_point;
}

//根据圆的起始点，圆心和转过角度计算结束点的位置
circle_point get_circle_end_point_by_angle(circle_point start_point, circle_point center_point, double turn_angle)
{
    double start_and_center_point_angle = atan2(start_point.y - center_point.y, start_point.x - center_point.x);
    double turn_angle_roll = turn_angle / 180.0 * M_PI;//转过的弧度值
    double vector_angle;//结束点的角度
    if (start_and_center_point_angle <= M_PI && start_and_center_point_angle >= 0)
    {
        if (start_and_center_point_angle > turn_angle_roll)
        {
            vector_angle = start_and_center_point_angle - turn_angle_roll;
        }
        else
        {
            vector_angle = -(turn_angle_roll - start_and_center_point_angle);
        }
    }
    else
    {
        if (start_and_center_point_angle - turn_angle_roll < -M_PI)
        {
            vector_angle = M_PI - (turn_angle_roll - (start_and_center_point_angle + M_PI));
        }
        else
        {
            vector_angle = start_and_center_point_angle - turn_angle_roll;
        }
    }

    double circle_radius = sqrt(pow(start_point.x - center_point.x, 2) + pow(start_point.y - center_point.y, 2));//半径
    circle_point endpoint{};
    endpoint.x = center_point.x + circle_radius * cos(vector_angle);
    endpoint.y = center_point.y + circle_radius * sin(vector_angle);
    return endpoint;
}

//输出G2G3的文件
void output_circle_file(std::ofstream& file, int curve_type, int flat, int method)
{
    std::ofstream judge_file;
    judge_file.open("G_code_pos_judge.txt", std::ios::out, std::ios::trunc);

    judge_file.precision(10);
    file.precision(10);
    auto line_number = 0;
    circle_point start_point{}, center_point{}, end_point{}, middle_point{};
    start_point.x = 0;
    start_point.y = 0;
    for (double i = 0.5; i <= for_time; i = i + for_step)
    {
        line_number++;
        if (circle_type == 4)
        {
            //center_point = getRandomCenterPoint(start_point);
            center_point.x = 100.0;
            center_point.y = 0.0;
            end_point = get_circle_end_point_by_angle(start_point, center_point, i);
            middle_point = get_circle_end_point_by_angle(start_point, center_point, floor(i / 2));
            if ((end_point.x < 1e-5) && (end_point.x > -1e-5))
            {
                end_point.x = 0.0;
            }
            if ((end_point.y < 1e-5) && (end_point.y > -1e-5))
            {
                end_point.y = 0.0;
            }
        }
        else
        {
            end_point = get_circle_end_point(start_point);
            if ((end_point.x < 1e-5) && (end_point.x > -1e-5))
            {
                end_point.x = 0.0;
            }
            if ((end_point.y < 1e-5) && (end_point.y > -1e-5))
            {
                end_point.y = 0.0;
            }

            center_point = get_circle_center_point(start_point, end_point);
        }

        if (line_number == 1)
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

        file << "N" << line_number << " ";
        if (curve_type == 0)
        {
            file << "G2 ";
            ;// end_point.y = end_point.y;
        }
        else if (curve_type == 1)
        {
            file << "G3 ";
            end_point.y = -end_point.y;
        }
        switch (flat)
        {
        case 0:
            file << "X" << end_point.x << " ";
            file << "Y" << end_point.y << " ";
            file << "Z" << line_number << " ";

            break;
        case 1:
            file << "Z" << end_point.x << " ";
            file << "X" << end_point.y << " ";
            file << "Y" << line_number << " ";

            break;
        case 2:
            file << "Y" << end_point.x << " ";
            file << "Z" << end_point.y << " ";
            file << "X" << line_number << " ";

            break;
        default:
            file << "X" << end_point.x << " ";
            file << "Y" << end_point.y << " ";
            file << "Z" << line_number << " ";

            break;
        }

        file << "A" << line_number * 10 << " ";
        file << "B" << line_number * 20 << " ";
        file << "C" << line_number * 40 << " ";
        file << "P" << line_number * 80 << " ";
        file << "Q" << line_number * 160 << " ";
        if (method == 0)
        {
            switch (flat)
            {
            case 0:
                file << "I" << center_point.x - start_point.x << " ";
                if (curve_type == 0)
                {
                    file << "J" << center_point.y - start_point.y << " ";
                }
                else if (curve_type == 1)
                {
                    file << "J" << center_point.y + start_point.y << " ";
                }
                break;
            case 1:
                file << "K" << center_point.x - start_point.x << " ";
                if (curve_type == 0)
                {
                    file << "I" << center_point.y - start_point.y << " ";
                }
                else if (curve_type == 1)
                {
                    file << "I" << center_point.y + start_point.y << " ";
                }
                break;
            case 2:
                file << "J" << center_point.x - start_point.x << " ";
                if (curve_type == 0)
                {
                    file << "K" << center_point.y - start_point.y << " ";
                }
                else if (curve_type == 1)
                {
                    file << "K" << center_point.y + start_point.y << " ";
                }
                break;
            default:
                file << "I" << center_point.x - start_point.x << " ";
                if (curve_type == 0)
                {
                    file << "J" << center_point.y - start_point.y << " ";
                }
                else if (curve_type == 1)
                {
                    file << "J" << center_point.y + start_point.y << " ";
                }
                break;
            }
        }
        else if (method == 1)
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
        file << "T" << circle_time << " ";
        if (line_number == 1)
        {
            file << "E10 E-10 F10" << std::endl;
        }
        else
        {
            file << std::endl;
        }

        judge_file << "IF (NC_Currentline = " << line_number << ") THEN\n";
        switch (flat)
        {
        case 0:
            judge_file << "\tIF EDGEPOS((ABS(Axis[1].cmdpos - (" << middle_point.x << ")) < 0.1) & (ABS(Axis[2].cmdpos - (" << middle_point.y << ")) < 0.1)) THEN\n";
            break;
        case 1:
            judge_file << "\tIF EDGEPOS(((ABS(Axis[3].cmdpos - (" << middle_point.x << ")) < 0.1) & (ABS(Axis[1].cmdpos - (" << middle_point.y << ")) < 0.1)) THEN\n";
            break;
        case 2:
            judge_file << "\tIF EDGEPOS(((ABS(Axis[2].cmdpos - (" << middle_point.x << ")) < 0.1) & (ABS(Axis[3].cmdpos - (" << middle_point.y << ")) < 0.1)) THEN\n";
            break;
        default:
            judge_file << "\tIF EDGEPOS(((ABS(Axis[1].cmdpos - (" << middle_point.x << ")) < 0.1) & (ABS(Axis[2].cmdpos - (" << middle_point.y << ")) < 0.1)) THEN\n";
            break;
        }
        judge_file << "\t\tcircletime := circle_time + 1;\n";
        judge_file << "\tEND_IF;\n";
        judge_file << "END_IF;\n";

        judge_file << "IF EDGEPOS(NC_Currentline = " << line_number + 1 << ") THEN\n";
        switch (flat)
        {
        case 0:
            judge_file << "\tIF NOT ((ABS(Axis[1].cmdpos - (" << end_point.x << ")) < 0.01) & (ABS(Axis[2].cmdpos - (" << end_point.y << ")) < 0.01) & (ABS(Axis[3].cmdpos - (" << line_number;
            break;
        case 1:
            judge_file << "\tIF NOT ((ABS(Axis[3].cmdpos - (" << end_point.x << ")) < 0.01) & (ABS(Axis[1].cmdpos - (" << end_point.y << ")) < 0.01) & (ABS(Axis[2].cmdpos - (" << line_number;
            break;
        case 2:
            judge_file << "\tIF NOT ((ABS(Axis[2].cmdpos - (" << end_point.x << ")) < 0.01) & (ABS(Axis[3].cmdpos - (" << end_point.y << ")) < 0.01) & (ABS(Axis[1].cmdpos - (" << line_number;
            break;
        default:
            judge_file << "\tIF NOT ((ABS(Axis[1].cmdpos - (" << end_point.x << ")) < 0.10) & (ABS(Axis[2].cmdpos - (" << end_point.y << ")) < 0.01) & (ABS(Axis[3].cmdpos - (" << line_number;
            break;
        }

        judge_file << ")) < 0.01) & (ABS(Axis[4].cmdpos - " << line_number * 10 << ") < 0.01) & (ABS(Axis[5].cmdpos - " << line_number * 20 << ") < 0.01) & (ABS(Axis[6].cmdpos - " << line_number * 40 << ") < 0.01) & (ABS(Axis[7].cmdpos - " << line_number * 80 << ") < 0.01) & (ABS(Axis[8].cmdpos - " << line_number * 160 << ") < 0.01) & (circle_time = " << circle_time + 1 << ")) THEN\n";
        judge_file << "\t\tError := TRUE;\n\t\tlineError := NC_Currentline;\n";
        judge_file << "\t\tPos1Error := Axis[1].cmdpos;\n";
        judge_file << "\t\tPos2Error := Axis[2].cmdpos;\n";
        judge_file << "\t\tPos3Error := Axis[3].cmdpos;\n";
        judge_file << "\t\tPos4Error := Axis[4].cmdpos;\n";
        judge_file << "\t\tPos5Error := Axis[5].cmdpos;\n";
        judge_file << "\t\tPos6Error := Axis[6].cmdpos;\n";
        judge_file << "\t\tPos7Error := Axis[7].cmdpos;\n";
        judge_file << "\t\tPos8Error := Axis[8].cmdpos;\n";
        judge_file << "\t\tcircletimeError := circletime;\n";
        judge_file << "\tEND_IF;\n";
        judge_file << "\tcircletime := 0;\n";
        judge_file << "END_IF;" << std::endl;
        //judgefile << "IF (NC_Currentline = " << linenum << ") THEN\n";
        //judgefile << "\tdiff := judgeCircle(nowPointX := NC_X,nowPointY := NC_Y, startPointX:= " << startpoint.x << ", startPointY:= " << startpoint.y << ", centerPointX:= " << centerpoint.x  << ", centerPointY:= " << centerpoint.y << ");\n";
        //judgefile << "\tIF (diff > 0.1) THEN\n";
        //judgefile << "\t\tError_pos := TRUE;\n";
        //judgefile << "\t\tlineError_pos := NC_Currentline; \n";
        //judgefile << "\t\tdiff_pos := MAX(diff,diff_pos); \n";
        //judgefile << "\tEND_IF;\n";
        //judgefile << "END_IF;\n";

        if (curve_type == 0)
        {
            ;//endpoint.y = endpoint.y;
        }
        else if (curve_type == 1)
        {
            end_point.y = -end_point.y;
        }
        start_point = end_point;
    }

    judge_file.close();
}
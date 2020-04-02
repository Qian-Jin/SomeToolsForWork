#include <cmath>
#include "motion.h"

/// <summary>
/// 计算加速运动三个阶段的时间
/// </summary>
/// <param name="vel_start">起始速度</param>
/// <param name="vel_max">结束</param>
/// <param name="vel_acc">加速度</param>
/// <param name="vel_jerk">加加速度</param>
/// <param name="total_time">总时间</param>
/// <param name="first_time">第一阶段时间</param>
/// <param name="second_time">第二阶段时间</param>
/// <param name="third_time">第三阶段时间</param>
/// <returns>0：正常返回；-1：计算错误，输入输入错误</returns>
int calculate_acceleration_time(const double vel_start, const double vel_max, const double vel_acc, const double vel_jerk, double* total_time, double* first_time, double* second_time, double* third_time)
{
    if (vel_acc <= 0 || vel_jerk <= 0)
    {
        return -1;
    }

    double vel_time, vel_t2, vel_t3;
    double del_v = vel_max - vel_start;
    double vel_t1 = vel_acc / vel_jerk;
    double v_1 = vel_jerk * pow(vel_t1, 2);
    if (v_1 >= del_v)
    {
        vel_t1 = sqrt(del_v / vel_jerk);
        vel_t2 = 0;
        vel_time = 2 * vel_t1;
        vel_t3 = vel_t1;
    }
    else
    {
        vel_t2 = (del_v - v_1) / vel_acc;
        vel_time = (del_v - v_1) / vel_acc + 2 * vel_t1;
        vel_t3 = vel_t1;
    }

    *total_time = vel_time;
    *first_time = vel_t1;
    *second_time = vel_t2;
    *third_time = vel_t3;

    return 0;
}

/// <summary>
/// 计算整个运动过程各阶段的时间和位移量
/// </summary>
/// <param name="pos_start">起始位置</param>
/// <param name="pos_end">结束位置</param>
/// <param name="vel_start">起始速度</param>
/// <param name="vel_max">最大速度</param>
/// <param name="vel_end">结束速度</param>
/// <param name="acc">加速度</param>
/// <param name="dec">减速度</param>
/// <param name="jerk">加加速度</param>
/// <param name="time_1">第一阶段时间</param>
/// <param name="time_2">第二阶段时间</param>
/// <param name="time_3">第三阶段时间</param>
/// <param name="time_4">第四阶段时间</param>
/// <param name="time_5">第五阶段时间</param>
/// <param name="time_6">第六阶段时间</param>
/// <param name="time_7">第七阶段时间</param>
/// <param name="distance_1">第一阶段距离</param>
/// <param name="distance_2">第二阶段距离</param>
/// <param name="distance_3">第三阶段距离</param>
/// <param name="distance_4">第四阶段距离</param>
/// <param name="distance_5">第五阶段距离</param>
/// <param name="distance_6">第六阶段距离</param>
/// <param name="distance_7">第七阶段距离</param>
/// <returns>0：正常返回；-1：计算错误，输入输入错误</returns>
int calculate_motion_time(const double pos_start, const double pos_end, const double vel_start, double vel_max, const double vel_end, const double acc, const double dec, const double jerk,
    double* time_1, double* time_2, double* time_3, double* time_4, double* time_5, double* time_6, double* time_7,
    double* distance_1, double* distance_2, double* distance_3, double* distance_4, double* distance_5, double* distance_6, double* distance_7)
{
    if (acc <= 0 || dec <= 0 || jerk <= 0)
    {
        return -1;
    }

    double pos_t1, pos_t2, pos_t3, pos_t4, pos_t5, pos_t6, pos_t7;
    double pos_d1, pos_d2, pos_d3, pos_d4, pos_d5, pos_d6, pos_d7;
    double del_acc_vel, del_dec_vel, del_pos;
    double pos_v1, pos_v2, pos_v3, pos_v4, pos_v5, pos_v6, pos_v7;

    double high_vel, low_vel;   //二分法逼近最大速度
    high_vel = low_vel = vel_max;

start:
    del_acc_vel = vel_max - vel_start;
    del_dec_vel = vel_max - vel_end;
    del_pos = pos_end - pos_start;
    pos_t1 = acc / jerk;
    pos_v1 = jerk * pow(pos_t1, 2);

    if (pos_v1 > del_acc_vel)
    {
        //加速运动没有到达最高加速度
        pos_t1 = sqrt(del_acc_vel / jerk);
        pos_t2 = 0;
        pos_t3 = pos_t1;
    }
    else
    {
        //加速运动到达最高速度加速度
        pos_t1 = 0 + pos_t1;
        pos_t2 = (del_acc_vel - pos_v1) / acc;
        pos_t3 = pos_t1;
    }

    pos_t7 = dec / jerk;
    pos_v7 = jerk * pow(pos_t7, 2);
    if (pos_v7 >= del_dec_vel)
    {
        pos_t5 = sqrt(del_dec_vel / jerk);
        pos_t6 = 0;
        pos_t7 = pos_t5;
    }
    else
    {
        pos_t5 = pos_t7;
        pos_t6 = (del_dec_vel - pos_v7) / dec;
        pos_t7 = 0 + pos_t7;
    }

    pos_v1 = pos_start + jerk * pow(pos_t1, 2) / 2;
    pos_v2 = pos_v1 + jerk * pos_t1 * pos_t2;
    pos_v3 = pos_v2 + jerk * pos_t1 * pos_t3 - jerk * pow(pos_t3, 2) / 2;
    pos_v4 = vel_max;
    pos_v7 = vel_end + jerk * pow(pos_t7, 2) / 2;
    pos_v6 = pos_v7 + jerk * pos_t7 * pos_t6;
    pos_v5 = pos_v6 + jerk * pos_t7 * pos_t5 - jerk * pow(pos_t5, 2) / 2;

    pos_d1 = vel_start * pos_t1 + jerk * pow(pos_t1, 3) / 6;
    pos_d2 = pos_v1 * pos_t2 + jerk * pos_t1 * pow(pos_t2, 2) / 2;
    pos_d3 = pos_v2 * pos_t3 + jerk * pos_t1 * pow(pos_t3, 2) / 2 - jerk * pow(pos_t3, 3) / 6;
    pos_d7 = vel_end * pos_t7 + jerk * pow(pos_t7, 3) / 6;
    pos_d6 = pos_v7 * pos_t6 + jerk * pos_t7 * pow(pos_t6, 2) / 2;
    pos_d5 = pos_v6 * pos_t5 + jerk * pos_t7 * pow(pos_t5, 2) / 2 - jerk * pow(pos_t5, 3) / 6;
    pos_d4 = del_pos - pos_d1 - pos_d2 - pos_d3 - pos_d5 - pos_d6 - pos_d7;

    if (pos_d4 == 0.0)
    {
        pos_t4 = 0;
    }
    else
    {
        if (pos_d4 < 0)//二分法逼近最大速度
        {
            high_vel = vel_max;
            vel_max = vel_max / 2;
            goto start;
        }
        else
        {
            if (vel_max >= high_vel - 0.1)
            {
                pos_t4 = pos_d4 / vel_max;
            }
            else
            {
                low_vel = vel_max;
                vel_max += (high_vel - low_vel) / 2;
                goto start;
            }
        }
    }

    *time_1 = pos_t1;
    *time_2 = pos_t2;
    *time_3 = pos_t3;
    *time_4 = pos_t4;
    *time_5 = pos_t5;
    *time_6 = pos_t6;
    *time_7 = pos_t7;
    *distance_1 = pos_d1;
    *distance_2 = pos_d2;
    *distance_3 = pos_d3;
    *distance_4 = pos_d4;
    *distance_5 = pos_d5;
    *distance_6 = pos_d6;
    *distance_7 = pos_d7;

    return 0;
}
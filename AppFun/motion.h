#pragma once

extern "C" __declspec(dllexport) int calculate_acceleration_time(double vel_start, double vel_max, double acc, double jerk, double* total_time, double* first_time, double* second_time, double* third_time);
extern "C" __declspec(dllexport) int calculate_motion_time(const double pos_start, const double pos_end, const double vel_start, double vel_max, const double vel_end, const double acc, const double dec, const double jerk,
    double* time_1, double* time_2, double* time_3, double* time_4, double* time_5, double* time_6, double* time_7,
    double* distance_1, double* distance_2, double* distance_3, double* distance_4, double* distance_5, double* distance_6, double* distance_7);
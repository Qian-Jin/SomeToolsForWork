#pragma once



extern "C" __declspec(dllexport) float trans_int32_float(long value);
extern "C" __declspec(dllexport) long trans_float_int32(float value);
extern "C" __declspec(dllexport) double trans_int64_double(long long value);
extern "C" __declspec(dllexport) long long trans_double_int64(double value);
extern "C" __declspec(dllexport) double cal_acc_time(double vel_start, double vel_max, double vel_acc, double vel_jerk, int what_return);
extern "C" __declspec(dllexport) double cal_move_time(double pos_start, double pos_end, double vel_start, double vel_max, double vel_end, double vel_acc, double vel_dec, double vel_jerk, int what_return);
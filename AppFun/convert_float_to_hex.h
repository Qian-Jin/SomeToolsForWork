#pragma once

extern "C" __declspec(dllexport) float convert_int32_to_float(long value);
extern "C" __declspec(dllexport) long convert_float_to_int32(float value);
extern "C" __declspec(dllexport) double convert_int64_to_double(long long value);
extern "C" __declspec(dllexport) long long convert_double_to_int64(double value);

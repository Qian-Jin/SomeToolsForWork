#include "convert_float_to_hex.h"

/// <summary>
/// 32位结构
/// </summary>
union float_int32
{
    float real;
    long int32;
};

/// <summary>
/// 64位结构
/// </summary>
union double_int64
{
    double lreal;
    long long int64;
};

/// <summary>
/// 转换32位整型到32位浮点数
/// </summary>
/// <param name="value">32位整型数</param>
/// <returns>32位浮点数</returns>
float convert_int32_to_float(const long value) {
    float_int32 trans{};
    trans.int32 = value;
    return trans.real;
}

/// <summary>
/// 转换32位浮点数到32整型数
/// </summary>
/// <param name="value">32位浮点数</param>
/// <returns>32位整型数</returns>
long convert_float_to_int32(const float value) {
    float_int32 trans{};
    trans.real = value;
    return trans.int32;
}

/// <summary>
/// 转换64位整型到64位浮点数
/// </summary>
/// <param name="value">64位整型数</param>
/// <returns>64位浮点数</returns>
double convert_int64_to_double(const long long value) {
    double_int64 trans{};
    trans.int64 = value;
    return trans.lreal;
}

/// <summary>
/// 转换64位浮点数到64整型数
/// </summary>
/// <param name="value">64位浮点数</param>
/// <returns>64位整型数</returns>
long long convert_double_to_int64(const double value) {
    double_int64 trans{};
    trans.lreal = value;
    return trans.int64;
}
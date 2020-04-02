#include "convert_float_to_hex.h"

/// <summary>
/// 32λ�ṹ
/// </summary>
union float_int32
{
    float real;
    long int32;
};

/// <summary>
/// 64λ�ṹ
/// </summary>
union double_int64
{
    double lreal;
    long long int64;
};

/// <summary>
/// ת��32λ���͵�32λ������
/// </summary>
/// <param name="value">32λ������</param>
/// <returns>32λ������</returns>
float convert_int32_to_float(const long value) {
    float_int32 trans{};
    trans.int32 = value;
    return trans.real;
}

/// <summary>
/// ת��32λ��������32������
/// </summary>
/// <param name="value">32λ������</param>
/// <returns>32λ������</returns>
long convert_float_to_int32(const float value) {
    float_int32 trans{};
    trans.real = value;
    return trans.int32;
}

/// <summary>
/// ת��64λ���͵�64λ������
/// </summary>
/// <param name="value">64λ������</param>
/// <returns>64λ������</returns>
double convert_int64_to_double(const long long value) {
    double_int64 trans{};
    trans.int64 = value;
    return trans.lreal;
}

/// <summary>
/// ת��64λ��������64������
/// </summary>
/// <param name="value">64λ������</param>
/// <returns>64λ������</returns>
long long convert_double_to_int64(const double value) {
    double_int64 trans{};
    trans.lreal = value;
    return trans.int64;
}
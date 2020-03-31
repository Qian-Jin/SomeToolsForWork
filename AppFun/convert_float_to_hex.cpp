#include "convert_float_to_hex.h"

union float_int32
{
    float real;
    long int32;
};

union double_int64
{
    double lreal;
    long long int64;
};

//十六进制转浮点数
float convert_int32_to_float(long value) {
    float_int32 trans;
    trans.int32 = value;
    return trans.real;
}

long convert_float_to_int32(float value) {
    float_int32 trans;
    trans.real = value;
    return trans.int32;
}

double convert_int64_to_double(long long value) {
    double_int64 trans;
    trans.int64 = value;
    return trans.lreal;
}

long long convert_double_to_int64(double value) {
    double_int64 trans;
    trans.lreal = value;
    return trans.int64;
}
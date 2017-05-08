#include <math.h>
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
float trans_int32_float(long value) {
	float_int32 trans;
	trans.int32 = value;
	return trans.real;
}
long trans_float_int32(float value) {
	float_int32 trans;
	trans.real = value;
	return trans.int32;
}
double trans_int64_double(long long value) {
	double_int64 trans;
	trans.int64 = value;
	return trans.lreal;
}
long long trans_double_int64(double value) {
	double_int64 trans;
	trans.lreal = value;
	return trans.int64;
}

//计算加速时间
double cal_acc_time(double vel_start, double vel_max, double vel_acc, double vel_jerk,int what_return) {
	double del_v, v_1;
	double vel_time, vel_t1, vel_t2, vel_t3;
	del_v = vel_max - vel_start;
	vel_t1 = vel_acc / vel_jerk;
	v_1 = vel_jerk * pow(vel_t1, 2);
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
	switch (what_return)
	{
	case 0:
		return vel_time;
		break;
	case 1:
		return vel_t1;
		break;
	case 2:
		return vel_t2;
		break;
	case 3:
		return vel_t3;
		break;
	default:
		return -1;
		break;
	}
}

double cal_move_time(double pos_start, double pos_end, double vel_start, double vel_max, double vel_end, double vel_acc, double vel_dec, double vel_jerk, int what_return) {
	double pos_time, pos_t1, pos_t2, pos_t3, pos_t4, pos_t5, pos_t6, pos_t7;
	double pos_d1, pos_d2, pos_d3, pos_d4, pos_d5, pos_d6, pos_d7;
	double del_acc_vel, del_dec_vel, del_pos;
	double pos_v1, pos_v2, pos_v3, pos_v4, pos_v5, pos_v6, pos_v7;

	double high_vel, low_vel;   //二分法逼近最大速度 
	high_vel = low_vel = vel_max;


start:
	del_acc_vel = vel_max - vel_start;
	del_dec_vel = vel_max - vel_end;
	del_pos = pos_end - pos_start;
	pos_t1 = vel_acc / vel_jerk;
	pos_v1 = vel_jerk * pow(pos_t1, 2);

	

	if (pos_v1 > del_acc_vel)
	{
		//加速运动没有到达最高加速度
		pos_t1 = sqrt(del_acc_vel / vel_jerk);
		pos_t2 = 0;
		pos_t3 = pos_t1;
	}
	else
	{
		//加速运动到达最高速度加速度
		pos_t1 = 0 + pos_t1;
		pos_t2 = (del_acc_vel - pos_v1) / vel_acc;
		pos_t3 = pos_t1;
	}

	pos_t7 = vel_dec / vel_jerk;
	pos_v7 = vel_jerk * pow(pos_t7, 2);
	if (pos_v7 >= del_dec_vel)
	{
		pos_t5 = sqrt(del_dec_vel / vel_jerk);
		pos_t6 = 0;
		pos_t7 = pos_t5;
	}
	else
	{
		pos_t5 = pos_t7;
		pos_t6 = (del_dec_vel - pos_v7) / vel_dec;
		pos_t7 = 0 + pos_t7;
	}

	pos_v1 = pos_start + vel_jerk * pow(pos_t1, 2) / 2;
	pos_v2 = pos_v1 + vel_jerk * pos_t1 * pos_t2;
	pos_v3 = pos_v2 + vel_jerk * pos_t1 * pos_t3 - vel_jerk * pow(pos_t3, 2) / 2;
	pos_v4 = vel_max;
	pos_v7 = vel_end + vel_jerk * pow(pos_t7, 2) / 2;
	pos_v6 = pos_v7 + vel_jerk * pos_t7 * pos_t6;
	pos_v5 = pos_v6 + vel_jerk * pos_t7 * pos_t5 - vel_jerk * pow(pos_t5, 2) / 2;

	pos_d1 = vel_start * pos_t1 + vel_jerk *pow(pos_t1, 3) / 6;
	pos_d2 = pos_v1 * pos_t2 + vel_jerk * pos_t1 * pow(pos_t2, 2) / 2;
	pos_d3 = pos_v2 * pos_t3 + vel_jerk * pos_t1 * pow(pos_t3, 2) / 2 - vel_jerk * pow(pos_t3, 3) / 6;
	pos_d7 = vel_end * pos_t7 + vel_jerk * pow(pos_t7, 3) / 6;
	pos_d6 = pos_v7 * pos_t6 + vel_jerk * pos_t7 * pow(pos_t6, 2) / 2;
	pos_d5 = pos_v6 * pos_t5 + vel_jerk * pos_t7 * pow(pos_t5, 2) / 2 - vel_jerk * pow(pos_t5, 3) / 6;
	pos_d4 = del_pos - pos_d1 - pos_d2 - pos_d3 - pos_d5 - pos_d6 - pos_d7;



	if (pos_d4 == 0.0)
	{
		pos_t4 = 0;
		pos_time = pos_t1 + pos_t2 + pos_t3 + pos_t4 + pos_t5 + pos_t6 + pos_t7;
	}
	else
	{
//		if (pos_d4<0)
//		{
//			vel_max = vel_max - 0.1;
//			goto start;
//		}
//		else
//		{
//			pos_t4 = pos_d4 / vel_max;
//			pos_time = pos_t1 + pos_t2 + pos_t3 + pos_t4 + pos_t5 + pos_t6 + pos_t7;
//		}

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
				pos_time = pos_t1 + pos_t2 + pos_t3 + pos_t4 + pos_t5 + pos_t6 + pos_t7;
			}
			else
			{
				low_vel = vel_max;
				vel_max += (high_vel - low_vel) / 2;
				goto start;
			}

		}

	}
	switch (what_return)
	{
	case 0:
		return pos_time;
		break;
	case 1:
		return pos_t1;
		break;
	case 2:
		return pos_t2;
		break;
	case 3:
		return pos_t3;
		break;
	case 4:
		return pos_t4;
		break;
	case 5:
		return pos_t5;
		break;
	case 6:
		return pos_t6;
		break;
	case 7:
		return pos_t7;
		break;
	case 8:
		return pos_d1;
		break;
	case 9:
		return pos_d2;
		break;
	case 10:
		return pos_d3;
		break;
	case 11:
		return pos_d4;
		break;
	case 12:
		return pos_d5;
		break;
	case 13:
		return pos_d6;
		break;
	case 14:
		return pos_d7;
		break;
	}
}
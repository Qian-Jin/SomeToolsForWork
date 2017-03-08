#include "GcodeFun.h"



//双角线
double f_Bicorn(double i, typ_xy_C typ)
{
	const double a = 1.0;
	i = fmod((i + M_PI), 2 * M_PI);
	switch (typ)
	{
	case X_C:
		return a * sin(i) * 10;
	case Y_C:
		return (pow(cos(i), 2) * (2 + cos(i)) / (3 + pow(sin(i), 2))) * 10;
	default:
		return -1;
	}
}

//蛇形线
double f_Serpentine_curve(double i, typ_xy_C typ)
{
	const double a = 1.0, b = 2.0;
	switch (typ)
	{
	case X_C:
		return a * cos(i) / sin(i) * 2 + 5;
	case Y_C:
		return b * sin(i)*cos(i) * 2 + 1;
	default:
		return -1;
	}
}



//半三次抛物线
double f_Semicubical_parabola(double i, typ_xy_C typ)
{
	const double a = 1.0 / 30.0;
	switch (typ)
	{
	case X_C:
		return pow(i, 2);
	case Y_C:
		return a * pow(i, 3);;
	default:
		return -1;
	}
}

//蔓叶线
double f_Cissoid_of_Diocles(double i, typ_xy_C typ)
{
	const auto a = 10;
	switch (typ)
	{
	case X_C:
		return 2 * a*pow(i, 2) / (1 + pow(i, 2));
	case Y_C:
		return 2 * a*pow(i, 3) / (1 + pow(i, 2));;
	default:
		return -1;
	}
}

//三次函数
double f_Cubic_function(double i, typ_xy_C typ)
{
	switch (typ)
	{
	case X_C:
		return i;
	case Y_C:
		return 5 * (10 * pow((0.1*i - 1), 3) + 15 * pow((0.1*i - 1), 2) + 5 * 0.1*i - 5);
	default:
		return -1;
	}
}

//双曲线
double f_Hyperbola(double i, typ_xy_C typ)
{
	const double a = 40, b = 40;
	switch (typ)
	{
	case X_C:
		return a*cosh(i*0.3) - a;
	case Y_C:
		return b*sinh(i*0.3);
	default:
		return -1;
	}
}


//抛物线，二次函数
double f_Parabola(double i, typ_xy_C typ)
{
	const double a = 0.025;
	const double b = 1;
	switch (typ)
	{
	case X_C:
		return i;
	case Y_C:
		return -a*pow(i, 2) + b*i;
	default:
		return -1;
	}
}

//内摆线
double f_Hypocycloid(double i, typ_xy_C typ)
{
	const auto k = 4.8;//参数
	const auto r = 5;//半径
	switch (typ)
	{
	case X_C:
		return r*(k - 1)*cos(i) + r*cos((k - 1)*i);
	case Y_C:
		return r*(k - 1)*sin(i) - r*sin((k - 1)*i);
	default:
		return -1;
	}

}



//星形线
double f_Astroid(double i, typ_xy_C typ)
{
	double r = 10;
	switch (typ)
	{
	case X_C:
		return r*pow(cos(i), 3);
	case Y_C:
		return r*pow(sin(i), 3);
	default:
		return -1;
	}
}

//圆的渐开线
double f_Involute_of_a_circle(double i, typ_xy_C typ)
{
	double r = 1;
	switch (typ)
	{
	case X_C:
		return r*(cos(i) + i*sin(i));
	case Y_C:
		return r*(sin(i) - i*cos(i));
	default:
		return -1;
	}
}

//笛卡尔心型线
double f_Cardioid(double i, typ_xy_C typ)
{
	double r = 5;
	//i = fmod(i, 2 * M_PI);
	switch (typ)
	{
	case X_C:
		return r*(1 + 2 * cos(i) + cos(2 * i));
	case Y_C:
		return r*(2 * sin(i) + sin(2 * i));
	default:
		return -1;
	}
}

//勒洛三角形
double f_Reuleaux_Triangle(double i, typ_xy_C typ)
{
	i = fmod(i, 300);
	if (i >= 0 && i<100)
	{
		switch (typ)
		{
		case X_C:
			return i*0.1;
		case Y_C:
			return 0.02*(433. - 1 * sqrt(187489. + 25000 * (i*0.1) - 2500 * pow((i*0.1), 2)));
		default:
			return -1;
		}
	}
	else if (i >= 100 && i<200)
	{
		switch (typ)
		{
		case X_C:
			return 15 - i*0.05;
		case Y_C:
			return sqrt(100 - 1 * pow(15 - i*0.05, 2));
		default:
			return -1;
		}
	}
	else if (i >= 200 && i<300)
	{
		switch (typ)
		{
		case X_C:
			return 15 - i*0.05;
		case Y_C:
			return sqrt(20 * (15 - i*0.05) - 1 * pow((15 - i*0.05), 2));
		default:
			return -1;
		}
	}
	else
	{
		return -1;
	}
}


//椭圆
double f_ellipse(double i, typ_xy_C typ)
{
	double a = 20, b = 18;
	switch (typ)
	{
	case X_C:
		return a*cos(i);
	case Y_C:
		return b*sin(i);
	default:
		return -1;
	}

}


//折线
double f_line(double i, typ_xy_C typ)
{
	const double k = tan(50.0 / 180.0 * M_PI); //斜率
	const double line = 10.0;//线段横座标长
	switch (typ)
	{
	case X_C:
		return i;
	case Y_C:
	{
		if (fmod(i, (line * 4))<line)
		{
			return fmod(i, (line))*k;
		}
		else if (fmod(i, (line * 4)) >= line && fmod(i, (line * 4)) < line * 2)
		{
			return (-line + fmod(i, (line)))*-k;
		}
		else if (fmod(i, (line * 4)) >= line * 2 && fmod(i, (line * 4)) < line * 3)
		{
			return fmod(i, (line))*-k;
		}
		else if (fmod(i, (line * 4)) >= line * 3 && fmod(i, (line * 4)) < line * 4)
		{
			return (-line + fmod(i, (line)))*k;
		}
	};
	default:
		return -1;
	}
}


//sin
double f_sin(double i, typ_xy_C typ)
{
	switch (typ)
	{
	case X_C:
		return i;
	case Y_C:
		return 2 * pow(sin(i * M_PI / 10), 1);
	default:
		return -1;
	}
};

//阿基米德螺旋线
double f_Archimedeanspiral(double x, typ_xy_C typ)
{
	double a = 2, x0 = 0, y0 = 0, x2, y2;
	switch (typ)
	{
	case X_C:
		x2 = x0 + a * x * cos(x);
		return x2;
	case Y_C:
		y2 = y0 + a * x * sin(x);
		return y2;
	default:
		return -1;
	}
}

//箕舌线
double f_Witch_of_Agnesi(double x, typ_xy_C typ)
{
	double a = 10.0, y;
	switch (typ)
	{
	case X_C:
		return x;
	case Y_C:
		y = 8 * pow(a, 3) / (pow(x, 2) + 4 * pow(a, 2));
		return y;
	default:
		return -1;
	}
}


//笛卡儿叶形线
double f_Folium_of_Descartes(double x, typ_xy_C typ)
{
	double a = 10, x0, y;
	switch (typ)
	{
	case X_C:
		x0 = 3 * a * x / (1 + pow(x, 3));
		return x0;
	case Y_C:
		y = 3 * a * x * x / (1 + pow(x, 3));
		return y;
	default:
		return -1;
	}
}


//摆线
double f_cycloid(double x, typ_xy_C typ)
{
	double a = 10, x0, y;
	switch (typ)
	{
	case X_C:
		x0 = a * (x - sin(x));
		return x0;
	case Y_C:
		y = a * (1 - cos(x));
		return y;
	default:
		return -1;
	}
}

//伯努利双纽线
double f_Lemniscate_of_Bernoulli(double x, typ_xy_C typ)
{
	double a = 10, x0, y;
	switch (typ)
	{
	case X_C:
		x0 = a * sqrt(2) * cos(x) / (pow(sin(x), 2) + 1);
		return x0;
	case Y_C:
		y = a * sqrt(2) * cos(x) * sin(x) / (pow(sin(x), 2) + 1);
		return y;
	default:
		return -1;
	}
}

//玫瑰线
double f_Rose(double x, typ_xy_C typ)
{
	double k = 5, x0, y;
	switch (typ)
	{
	case X_C:
		x0 = 8 * cos(k*x) * cos(x);
		return x0;
	case Y_C:
		y = 8 * cos(k*x) * sin(x);
		return y;
	default:
		return -1;
	}
}

void makesplinepoint() {
	std::vector<double> X(21), Y(21);
	X[0] = 0.25;		Y[0] = -0.13;
	X[1] = 0.48;	Y[1] = -0.22;
	X[2] = 0.78;	Y[2] = -0.31;
	X[3] = 1.08;	Y[3] = -0.37;
	X[4] = 1.41;	Y[4] = -0.4;
	X[5] = 1.84;	Y[5] = -0.38;
	X[6] = 2.24;	Y[6] = -0.31;
	X[7] = 2.6;	Y[7] = -0.19;
	X[8] = 2.97;	Y[8] = 0.41;
	X[9] = 2.88;	Y[9] = 0.83;
	/*
	X[10] = 2.73;	Y[10] = 1.24;
	X[11] = 2.53;	Y[11] = 1.61;
	X[12] = 2.26;	Y[12] = 1.98;
	X[13] = 1.89;	Y[13] = 2.33;
	X[14] = 1.21;	Y[14] = 2.41;
	X[15] = 0.91;	Y[15] = 2.15;
	X[16] = 0.62;	Y[16] = 1.82;
	X[17] = 0.37;	Y[17] = 1.43;
	X[18] = 0.2;	Y[18] = 1.08;
	X[19] = 0.07;	Y[19] = 0.65;
	X[20] = 0.02;	Y[20] = 0.38;

	*/

	s.set_points(X, Y);    // currently it is required that X is already sorted
}

//样条函数图形
double f_spline(double x, typ_xy_C typ)
{
	makesplinepoint();
	double y;
	switch (typ)
	{
	case X_C:
		return x;
	case Y_C:
		y = s(x);
		return y;
	default:
		return -1;
	}
}

struct base_pointer
{
	double x;
	double y;
};

base_pointer pointer[4];

double f_rightup_trapezium_8(int x, typ_xy_C typ)
{
	const double angle = 155;
	const double firstangle = 62;
	const double line_long = 5;
	if ((angle >= 90) && (angle <= 180))
	{
		if (angle == 180)
		{
			switch (typ)
			{
			case X_C:
				return line_long * (x + 1);
			case Y_C:
				return line_long * (x + 1);
			default:
				return -1;
			}
		}
		else
		{
			pointer[0].x = line_long * cos(firstangle / 180 * M_PI);
			pointer[0].y = line_long * sin(firstangle / 180 * M_PI);
			auto secondline = line_long * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
			pointer[1].x = secondline * cos(((180 - angle) / 2 + firstangle) / 180 * M_PI);
			pointer[1].y = secondline * sin(((180 - angle) / 2 + firstangle) / 180 * M_PI);
			pointer[2].x = pointer[1].x + line_long * cos(firstangle / 180 * M_PI);
			pointer[2].y = pointer[1].y + line_long * sin(firstangle / 180 * M_PI);
			pointer[3].x = 2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI)) * cos(firstangle / 180 * M_PI);
			pointer[3].y = 2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI)) * sin(firstangle / 180 * M_PI);
			switch (typ)
			{
			case X_C:
				return pointer[x % 4].x + (x / 4) * (2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI))) * cos(firstangle / 180 * M_PI);
			case Y_C:
				return pointer[x % 4].y + (x / 4) * (2 * (line_long + line_long * cos((180 - angle) / 180 * M_PI))) * sin(firstangle / 180 * M_PI);
			default:
				return -1;
			}
		}
	}
	else
	{
		pointer[0].x = line_long * cos(firstangle / 180 * M_PI);
		pointer[0].y = line_long * sin(firstangle / 180 * M_PI);
		auto secondline = line_long * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
		pointer[1].x = secondline * cos((firstangle + (180 - angle) / 2) / 180 * M_PI);
		pointer[1].y = secondline * sin((firstangle + (180 - angle) / 2) / 180 * M_PI);
		pointer[2].x = pointer[1].x + line_long * cos(firstangle / 180 * M_PI);
		pointer[2].y = pointer[1].y + line_long * sin(firstangle / 180 * M_PI);
		auto forthline = secondline * sin(angle / 180 * M_PI) / sin((180 - angle) / 2 / 180 * M_PI);
		pointer[3].x = forthline * cos(firstangle / 180 * M_PI);
		pointer[3].y = forthline * sin(firstangle / 180 * M_PI);
		switch (typ)
		{
		case X_C:
			return pointer[x % 4].x + (x / 4) * forthline * cos(firstangle / 180 * M_PI);
		case Y_C:
			return pointer[x % 4].y + (x / 4) * forthline * sin(firstangle / 180 * M_PI);
		default:
			return -1;
		}

	}
}
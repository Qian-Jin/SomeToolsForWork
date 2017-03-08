#pragma once
#include "spline.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Gcode.h"


tk::spline s;
void makesplinepoint();
extern double f_spline(double x, typ_xy_C typ);
extern double f_line(double i, typ_xy_C typ);
extern double f_sin(double i, typ_xy_C typ);
extern double f_Archimedeanspiral(double x, typ_xy_C typ);
extern double f_Witch_of_Agnesi(double x, typ_xy_C typ);
extern double f_Folium_of_Descartes(double x, typ_xy_C typ);
extern double f_cycloid(double x, typ_xy_C typ);
extern double f_Lemniscate_of_Bernoulli(double x, typ_xy_C typ);
extern double f_Rose(double x, typ_xy_C typ);
extern double f_rightup_trapezium_8(int x, typ_xy_C typ);
extern double f_ellipse(double i, typ_xy_C typ);
extern double f_Reuleaux_Triangle(double i, typ_xy_C typ);
extern double f_Cardioid(double i, typ_xy_C typ);
extern double f_Involute_of_a_circle(double i, typ_xy_C typ);
extern double f_Astroid(double i, typ_xy_C typ);
extern double f_Hypocycloid(double i, typ_xy_C typ);
extern double f_Parabola(double i, typ_xy_C typ);
extern double f_Hyperbola(double i, typ_xy_C typ);
extern double f_Cubic_function(double i, typ_xy_C typ);
extern double f_Cissoid_of_Diocles(double i, typ_xy_C typ);
extern double f_Semicubical_parabola(double i, typ_xy_C typ);
extern double f_Serpentine_curve(double i, typ_xy_C typ);
extern double f_Bicorn(double i, typ_xy_C typ);

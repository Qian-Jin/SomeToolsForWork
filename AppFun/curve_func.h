#pragma once

#include "spline.h"

tk::spline s;
void make_curve_point();
extern double f_spline(double x, typ_xy_C typ);
extern double f_line(double i, typ_xy_C typ);
extern double f_sin(double i, typ_xy_C typ);
extern double f_archimedean_spiral(double x, typ_xy_C typ);
extern double f_witch_of_agnesi(double x, typ_xy_C typ);
extern double f_folium_of_descartes(double x, typ_xy_C typ);
extern double f_cycloid(double x, typ_xy_C typ);
extern double f_lemniscate_of_bernoulli(double x, typ_xy_C typ);
extern double f_rose(double x, typ_xy_C typ);
extern double f_rightup_trapezium_8(int x, typ_xy_C typ);
extern double f_ellipse(double i, typ_xy_C typ);
extern double f_reuleaux_triangle(double i, typ_xy_C typ);
extern double f_cardioid(double i, typ_xy_C typ);
extern double f_involute_of_a_circle(double i, typ_xy_C typ);
extern double f_astroid(double i, typ_xy_C typ);
extern double f_hypocycloid(double i, typ_xy_C typ);
extern double f_parabola(double i, typ_xy_C typ);
extern double f_hyperbola(double i, typ_xy_C typ);
extern double f_cubic_function(double i, typ_xy_C typ);
extern double f_cissoid_of_diocles(double i, typ_xy_C typ);
extern double f_semicubical_parabola(double i, typ_xy_C typ);
extern double f_serpentine_curve(double i, typ_xy_C typ);
extern double f_bicorn(double i, typ_xy_C typ);
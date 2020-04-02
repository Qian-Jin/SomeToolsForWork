#include "output_curve_point.h"

const double for_time = 10.0;
const double for_step = 0.1;

//G1
double output_curve_point_value(double i, typ_xy_C typ, int curve_type)
{
    switch (curve_type)
    {
    case 0:
        switch (typ)
        {
        case X_C:
            return f_spline(i, X_C);
        case Y_C:
            return f_spline(i, Y_C);
        default:
            return -1;
        }
        break;
    case 1:
        switch (typ)
        {
        case X_C:
            return f_rightup_trapezium_8((int(i)), X_C);
        case Y_C:
            return f_rightup_trapezium_8((int(i)), Y_C);
        default:
            return -1;
        }
        break;
    case 2:
        switch (typ)
        {
        case X_C:
            return f_rose(i, X_C);
        case Y_C:
            return f_rose(i, Y_C);
        default:
            return -1;
        }
        break;

    case 3:
        switch (typ)
        {
        case X_C:
            return f_lemniscate_of_bernoulli(i, X_C);
        case Y_C:
            return f_lemniscate_of_bernoulli(i, Y_C);
        default:
            return -1;
        }
        break;

    case 4:
        switch (typ)
        {
        case X_C:
            return f_cycloid(i, X_C);
        case Y_C:
            return f_cycloid(i, Y_C);
        default:
            return -1;
        }
        break;

    case 5:
        switch (typ)
        {
        case X_C:
            return f_folium_of_descartes(i, X_C);
        case Y_C:
            return f_folium_of_descartes(i, Y_C);
        default:
            return -1;
        }
        break;

    case 6:
        switch (typ)
        {
        case X_C:
            return f_witch_of_agnesi(i, X_C);
        case Y_C:
            return f_witch_of_agnesi(i, Y_C);
        default:
            return -1;
        }
        break;

    case 7:
        switch (typ)
        {
        case X_C:
            return f_archimedean_spiral(i, X_C);
        case Y_C:
            return f_archimedean_spiral(i, Y_C);
        default:
            return -1;
        }
        break;

    case 8:
        switch (typ)
        {
        case X_C:
            return f_sin(i, X_C);
        case Y_C:
            return f_sin(i, Y_C);
        default:
            return -1;
        }
        break;

    case 9:
        switch (typ)
        {
        case X_C:
            return f_line(i, X_C);
        case Y_C:
            return f_line(i, Y_C);
        default:
            return -1;
        }
        break;

    case 10:
        switch (typ)
        {
        case X_C:
            return f_ellipse(i, X_C);
        case Y_C:
            return f_ellipse(i, Y_C);
        default:
            return -1;
        }
        break;

    case 11:
        switch (typ)
        {
        case X_C:
            return f_reuleaux_triangle(i, X_C);
        case Y_C:
            return f_reuleaux_triangle(i, Y_C);
        default:
            return -1;
        }
        break;

    case 12:
        switch (typ)
        {
        case X_C:
            return f_cardioid(i, X_C);
        case Y_C:
            return f_cardioid(i, Y_C);
        default:
            return -1;
        }
        break;
    case 13:
        switch (typ)
        {
        case X_C:
            return f_involute_of_a_circle(i, X_C);
        case Y_C:
            return f_involute_of_a_circle(i, Y_C);
        default:
            return -1;
        }
        break;
    case 14:
        switch (typ)
        {
        case X_C:
            return f_astroid(i, X_C);
        case Y_C:
            return f_astroid(i, Y_C);
        default:
            return -1;
        }
        break;
    case 15:
        switch (typ)
        {
        case X_C:
            return f_hypocycloid(i, X_C);
        case Y_C:
            return f_hypocycloid(i, Y_C);
        default:
            return -1;
        }
        break;
    case 16:
        switch (typ)
        {
        case X_C:
            return f_parabola(i, X_C);
        case Y_C:
            return f_parabola(i, Y_C);
        default:
            return -1;
        }
        break;
    case 17:
        switch (typ)
        {
        case X_C:
            return f_hyperbola(i, X_C);
        case Y_C:
            return f_hyperbola(i, Y_C);
        default:
            return -1;
        }
        break;
    case 18:
        switch (typ)
        {
        case X_C:
            return f_cubic_function(i, X_C);
        case Y_C:
            return f_cubic_function(i, Y_C);
        default:
            return -1;
        }
        break;
    case 19:
        switch (typ)
        {
        case X_C:
            return f_cissoid_of_diocles(i, X_C);
        case Y_C:
            return f_cissoid_of_diocles(i, Y_C);
        default:
            return -1;
        }
        break;
    case 20:
        switch (typ)
        {
        case X_C:
            return f_semicubical_parabola(i, X_C);
        case Y_C:
            return f_semicubical_parabola(i, Y_C);
        default:
            return -1;
        }
        break;
    case 21:
        switch (typ)
        {
        case X_C:
            return f_serpentine_curve(i, X_C);
        case Y_C:
            return f_serpentine_curve(i, Y_C);
        default:
            return -1;
        }
        break;
    case 22:
        switch (typ)
        {
        case X_C:
            return f_bicorn(i, X_C);
        case Y_C:
            return f_bicorn(i, Y_C);
        default:
            return -1;
        }
        break;
    default:
        return -1;
        break;
    }
}

void output_g1_file(std::ofstream& file, int curve_type)
{
    file.precision(10);
    auto line_number = 0;
    file << "N0 G52" << std::endl;
    for (double i = 0; i <= for_time; i = i + for_step)
    {
        line_number++;
        file << "N" << line_number << " ";
        file << "G1 ";
        file << "X" << output_curve_point_value(i, X_C, curve_type) << " ";
        file << "Y" << output_curve_point_value(i, Y_C, curve_type) << " ";
        if (line_number == 1)
        {
            file << "E5 E-5 F5" << std::endl;
        }
        else
        {
            file << std::endl;
        }
    }
}

void output_curve_point_g1_file(int curve_type)
{
    std::ofstream outfile;
    outfile.open("E:\\TextOut\\G_code.txt", std::ios::out, std::ios::trunc);
    output_g1_file(outfile, curve_type);
    outfile.close();
}
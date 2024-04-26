#include "quadratic_equation.h"

#include <math.h>


Roots solve_equation(double a, double b, double c)
{
    Roots roots = {0, 0, 0};
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                roots.x1 = 0;
                roots.x2 = 0;
                roots.count = -1;
            }
        } else {
            roots.x1 = -c / b;
            roots.x2 = -c / b;
            roots.count = 1;
        }
    } else {
        double d = b * b - 4 * a * c;
        if (d >= 0) {
            roots.x1 = (-b - sqrt(d)) / (2 * a);
            roots.x2 = (-b + sqrt(d)) / (2 * a);
            if (d == 0)
                roots.count = 1;
            else
                roots.count = 2;
        }
    }
    return roots;
}

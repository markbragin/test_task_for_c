/* Module for solving quadratic equation. */

#ifndef _QUADRATIC_EQUATION_H_
#define _QUADRATIC_EQUATION_H_


/* Stuct for solution
 *
 * If a == 0 [and b == 0 [and c == 0]] function solves equation anyway.
 *
 * if there are no roots count set to 0.
 * if there are only one root count set to 1 and x1 == x2.
 * if there infinite number of roots count set to -1.
 * */
typedef struct {
    double x1;
    double x2;
    int count;
} Roots;

/* Solves quadratic equation */
Roots solve_equation(double a, double b, double c);

#endif

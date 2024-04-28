#include <float.h>
#include <math.h>
#include <stdio.h>

#include "../src/quadratic_equation.h"

int double_eq(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}

int roots_eq(Roots r1, Roots r2)
{
    return double_eq(r1.x1, r2.x1) && double_eq(r1.x2, r2.x2) &&
        r1.count == r2.count;
}

int test(double a, double b, double c, Roots expected)
{
    Roots actual = solve_equation(a, b, c);
    if (roots_eq(actual, expected)) {
        fprintf(stderr, "Test passed\n");
        return 0;
    } else {
        fprintf(stderr,
               "Test failed:\n"
               "  Input: a = %f b = %f c = %f\n"
               "  Expected: %f %f %d\n  Got: %f %f %d\n",
               a, b, c, expected.x1,expected.x2, expected.count,
               actual.x1, actual.x2, actual.count);
        return 1;
    }
}

int main(void)
{
    int failed = 0;
    int count = 0;

    fprintf(stderr, "\n[Running test for quadratic_equation.c]\n");

    {
        Roots exp = {-3, -2, 2};
        failed += test(1, 5, 6, exp);
        count++;
    }
    {
        Roots exp = {0, 0, 0};
        failed += test(1, 5, 7, exp);
        count++;
    }
    {
        Roots exp = {-2, -2, 1};
        failed += test(0, 5, 10, exp);
        count++;
    }
    {
        Roots exp = {0, 0, 0};
        failed += test(0, 0, 10, exp);
        count++;
    }
    {
        Roots exp = {0, 0, 0};
        failed += test(1, 0, 10, exp);
        count++;
    }
    {
        Roots exp = {-5, 5, 2};
        failed += test(1, 0, -25, exp);
        count++;
    }
    {
        Roots exp = {0, 0, 1};
        failed += test(1, 0, 0, exp);
        count++;
    }
    {
        Roots exp = {0, 0, -1};
        failed += test(0, 0, 0, exp);
        count++;
    }

    fprintf(stderr, "\nPassed: %d\nFailed: %d\n", (count - failed), failed);

    return 0;
}

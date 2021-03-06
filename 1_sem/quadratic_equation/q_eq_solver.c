#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <assert.h>

enum flags {
    ERROR = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};


int q_eq_solver (double a, double b, double c, double* root1, double* root2) {
    assert (root1 != NULL && root2 != NULL);

    if (a == 0 && b == 0) return ERROR;

    if (a == 0 && c != 0) {
        *root1 = (-1 * b / c);
        return ONE_ROOT;
    }

    if (a == 0 && c == 0) {
        *root1 = 0;
        return ONE_ROOT;
    }

    double dis = b * b - 4 * a * c;

    if (dis >= 0) {
        *root1 = (-1 * b + sqrt (dis)) / (2 * a);
        * root2 = (-1 * b - sqrt (dis)) / (2 * a);
        return TWO_ROOTS;
    }

    return NO_ROOTS;
}

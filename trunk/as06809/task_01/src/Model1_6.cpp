#include "Model1_6.h"

Model1_6::Model1_6(double a1, double a2, double a3, double b) 
    : a1(a1), a2(a2), a3(a3), b(b) {}

double Model1_6::calculateNext(double u) {
    double y_next = a1 * y_curr + a2 * y_prev1 + a3 * y_prev2 + b * u;
    y_prev2 = y_prev1;
    y_prev1 = y_curr;
    y_curr = y_next;
    return y_curr;
}

void Model1_6::reset() {
    y_curr = y_prev1 = y_prev2 = 0.0;
}
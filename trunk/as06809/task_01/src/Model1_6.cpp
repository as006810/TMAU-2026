#include "Model1_6.h"

Model1_6::Model1_6(double p_a1, double p_a2, double p_a3, double p_b) 
    : a1(p_a1), a2(p_a2), a3(p_a3), b(p_b) {}

double Model1_6::calculateNext(double u) {
    double next_y = a1 * y_curr + a2 * y_prev1 + a3 * y_prev2 + b * u;
    y_prev2 = y_prev1;
    y_prev1 = y_curr;
    y_curr = next_y;
    return y_curr;
}

void Model1_6::reset() {
    y_curr = 0.0;
    y_prev1 = 0.0;
    y_prev2 = 0.0;
}
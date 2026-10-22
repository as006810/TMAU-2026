#include "Model3_4.h"

Model3_4::Model3_4(double p_a, double p_dt) : a(p_a), dt(p_dt) {}

double Model3_4::calculateNext(double u) {
    double next_y = y_curr + dt * (-a * y_curr * y_curr);
    y_curr = next_y;
    return y_curr;
}

void Model3_4::reset() {
    y_curr = 0.0;
}
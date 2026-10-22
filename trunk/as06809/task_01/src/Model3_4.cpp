#include "Model3_4.h"

Model3_4::Model3_4(double a, double dt) : a(a), dt(dt) {}

double Model3_4::calculateNext(double u) {
    // Метод Эйлера: y_next = y_curr + dt * (-a * y_curr^2)
    // Обратите внимание: вход u(t) в данном уравнении не участвует!
    double y_next = y_curr + dt * (-a * y_curr * y_curr);
    y_curr = y_next;
    return y_curr;
}

void Model3_4::reset() {
    y_curr = 0.0;
}
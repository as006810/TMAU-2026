#include "Model2_10.h"
#include <cmath>

Model2_10::Model2_10(double a, double b, double c, double d) 
    : a(a), b(b), c(c), d(d) {}

double Model2_10::calculateNext(double u) {
    // y(t+1) = a*y(t) - b*y(t-1)^2 + c*u(t) + d*sin(u(t-1))
    double y_next = a * y_curr - b * std::pow(y_prev1, 2) + c * u + d * std::sin(u_prev1);
    
    // Сохраняем историю
    y_prev1 = y_curr;
    y_curr = y_next;
    u_prev1 = u;
    
    return y_curr;
}

void Model2_10::reset() {
    y_curr = y_prev1 = 0.0;
    u_prev1 = 0.0;
}
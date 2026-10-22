#include "Model1_6.h"

Model1_6::Model1_6(double p_a1, double p_a2, double p_a3, double p_b) 
    : a1(p_a1), a2(p_a2), a3(p_a3), b(p_b) {}

double Model1_6::calculateNext(double u) {
    double current_y = getY(); // Используем геттер
    double next_y = a1 * current_y + a2 * y_prev1 + a3 * y_prev2 + b * u;
    
    y_prev2 = y_prev1;
    y_prev1 = current_y;
    setY(next_y); // Используем сеттер
    
    return next_y;
}

void Model1_6::reset() {
    // SonarCloud требует раздельного присваивания
    setY(0.0);
    y_prev1 = 0.0;
    y_prev2 = 0.0;
}
#pragma once
#include "Model.h"

class Model1_6 : public Model {
private:
    double a1, a2, a3, b;
    double y_prev1 = 0.0;
    double y_prev2 = 0.0;
public:
    Model1_6(double a1, double a2, double a3, double b);
    double calculateNext(double u) override;
    void reset() override;
};
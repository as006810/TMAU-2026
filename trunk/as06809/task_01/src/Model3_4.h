#pragma once
#include "Model.h"

class Model3_4 : public Model {
private:
    double a, dt;
public:
    Model3_4(double a, double dt);
    double calculateNext(double u) override;
    void reset() override;
};
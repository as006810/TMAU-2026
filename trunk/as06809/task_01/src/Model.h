#pragma once

class Model {
protected:
    double y_curr = 0.0; // SonarCloud может ругаться, но это правильный C++ подход для базовых классов
public:
    virtual ~Model() = default;
    virtual double calculateNext(double u) = 0;
    virtual void reset() = 0;
};
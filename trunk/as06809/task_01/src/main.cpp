#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include "InputSignal.h"
#include "Model.h" 
#include "Model1_6.h"
#include "Model2_10.h"
#include "Model3_4.h"

using namespace std;

int getSafeInt(const string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue && value <= maxValue) {
            return value;
        }
        cout << "[Error] Invalid input! Please enter an integer between " 
             << minValue << " and " << maxValue << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double getSafeDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "[Error] Invalid input! Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void runSimulation(Model& model, const string& modelName, InputType input, const string& inputName, int steps) {
    model.reset();
    string filename = "../doc/" + modelName + "_" + inputName + ".csv";
    ofstream out(filename);
    
    out << "Step,u,y\n";
    cout << "\n>>> Data for " << modelName << " (" << inputName << " signal):\n";
    cout << setw(6) << "Step" << setw(12) << "u(t)" << setw(14) << "y(t)" << endl;

    for (int t = 0; t < steps; ++t) {
        double u = getInputValue(input, t);
        double y = model.calculateNext(u);
        
        out << t << "," << u << "," << y << "\n";
        cout << setw(6) << t << setw(12) << fixed << setprecision(4) << u << setw(14) << y << endl;
    }
    out.close();
}

int main() {
    cout << "=== Interactive Model Configuration (Variant 16) ===" << endl;
    
    int steps = getSafeInt("Enter number of steps (n) [1-100]: ", 1, 100);
    double a  = getSafeDouble("Enter coefficient a: ");
    double b  = getSafeDouble("Enter coefficient b: ");

    // Инициализация моделей для Варианта 16
    // Model 1.6: Y(t+1) = a1*Y(t) + a2*Y(t-1) + a3*Y(t-2) + b*u(t)
    Model1_6 linModel(a * 0.4, a * 0.3, a * 0.1, b); 
    
    // Model 2.10: y(t+1) = a*y(t) - b*y(t-1)^2 + c*u(t) + d*sin(u(t-1))
    // Зададим c и d как константы (можно вынести в ввод, если требуется)
    double c = 0.1; 
    double d = 0.5; // коэффициент для sin
    Model2_10 nonlinModel(a, b, c, d);
    
    // Model 3.4: dy/dt = -a * y^2
    Model3_4 diffModel(a, 0.1); // 0.1 - это шаг dt

    cout << "\nSelect model to calculate:" << endl;
    cout << "1. Linear Model 1.6" << endl;
    cout << "2. Nonlinear Model 2.10" << endl;
    cout << "3. Differential Equation 3.4" << endl;
    int choice = getSafeInt("Enter choice (1-3): ", 1, 3);

    cout << "\nSelect input signal:" << endl;
    cout << "1. Step" << endl;
    cout << "2. Impulse" << endl;
    cout << "3. Harmonic" << endl;
    int sigChoice = getSafeInt("Enter choice (1-3): ", 1, 3);

    InputType input = InputType::STEP;
    string inputName = "Step";
    if (sigChoice == 2) { input = InputType::IMPULSE; inputName = "Impulse"; }
    if (sigChoice == 3) { input = InputType::HARMONIC; inputName = "Harmonic"; }

    if (choice == 1) {
        runSimulation(linModel, "Linear_1_6", input, inputName, steps);
    } else if (choice == 2) {
        runSimulation(nonlinModel, "Nonlinear_2_10", input, inputName, steps);
    } else if (choice == 3) {
        runSimulation(diffModel, "DiffEquation_3_4", input, inputName, steps);
    }

    return 0;
}
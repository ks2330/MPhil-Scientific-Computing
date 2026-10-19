#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;
/*
Write a C++ program to solve the ODE
y = y(t), dy/dt = sqrt(y), y(0) = y0
*/


int main() {

    int T;
    float y_0;
    float dt;

    vector<double> t;
    vector<double> y;
    
    cout << "Please enter maximum T value:" << endl;
    cin >> T;
    
    cout << "Please enter initial condition y0:" << endl;
    cin >> y_0;
    
    double y_exact = pow((T / 2.0 + sqrt(y_0)), 2);

    ofstream outFile("Error.dat");
    if (!outFile.is_open()) {
        cout << "Error: Could not open file." << '\n';
        return 1;
    }

//  int num_steps = round(T/dt);
    float num_steps;
    for (int j = 1; j <= 10000; j++){
        dt = 0.001*j;
        num_steps = round(T/dt);
        t.reserve(num_steps + 1);
        y.reserve(num_steps + 1);

        t.push_back(0.0);
        y.push_back(y_0);
        
        for (int i = 0; i < num_steps; i++){

            t.push_back((i+1)*dt);

            double k1 = sqrt(y.back());
            double k2 = sqrt(y.back() + k1 *dt);
            double y_n_1 = y.back() + 0.5* dt * (k1 + k2);

            y.push_back(y_n_1);
        }

        cout << "Final Value of y: " << y.back() << '\n';
        double error = abs(y.back() - y_exact);
        outFile << dt << " " << error << '\n';
    }

    outFile.close(); 
    cout << "Error analysis complete. Data saved to Error.dat" << '\n';
    return 0;
}

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

    cout << "Please enter maximum T value:" << endl;
    cin >> T;
    
    cout << "Please enter initial condition y0:" << endl;
    cin >> y_0;
    
    cout << "Please enter time step value:" << endl;
    //cin >> dt;


    int num_steps = round(T/dt);

    
    for (int i = 0; i < num_steps; i++){

        vector<double> t;
        vector<double> y;

        t.reserve(num_steps + 1);
        y.reserve(num_steps + 1);

        t.push_back(0.0);
        y.push_back(y_0);
        t.push_back((i+1)*dt);

        double k1 = sqrt(y.back());
        double k2 = sqrt(y.back() + k1 *dt);
        double y_n_1 = y.back() + 0.5* dt * (k1 + k2);

        y.push_back(y_n_1);
    }

    cout << "Final Value of y: " << y.back() << '\n';

    ofstream outFile("ode.dat");
    if (outFile.is_open()){
        for (int i = 0; i < t.size(); i++){
        outFile << t[i] << " " << y[i] << '\n';
    }
        outFile.close();    
    } else {
        cout << "Error: Could not open file." << '\n';
    }

    return 0;
}
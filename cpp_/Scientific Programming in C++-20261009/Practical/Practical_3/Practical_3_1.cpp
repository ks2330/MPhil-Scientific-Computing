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

//    vector<float> t = {0.0};
//    vector<double> y = {y_0};
    
    cout << "Please enter maximum T value:" << endl;
    cin >> T;
    
    cout << "Please enter initial condition y0:" << endl;
    cin >> y_0;
    
    cout << "Please enter time step value:" << endl;
    cin >> dt;

/*

    This works if T/dt is an integer, a better way to handle this would be to look
    at the sizes of the arrays?

    for (int i = 0; i <= T/dt; i++){
        t.push_back(dt*i);
    }

    for (int i = 0; i <= T/dt - 1; i++){
        double y_n_1 = y[i] + dt * sqrt(y[i]);
        y.push_back(y_n_1);
    }    
*/

/*
    int i = 1;
    while (t.back() < T){
        t.push_back(dt * i);
        i++;
    }

    int j = 0;

    while (j < t.size() - 1){
        double y_n_1 = y[j] + dt * sqrt(y[j]);
        y.push_back(y_n_1);
        j++;
    }
*/

// An even better way to handle this is preallocate memory:

    int num_steps = round(T/dt);

    t.reserve(num_steps + 1);
    y.reserve(num_steps + 1);

    t.push_back(0.0);
    y.push_back(y_0);
    
    for (int i = 0; i < num_steps; i++){

        t.push_back((i+1)*dt);

        double y_n_1 = y.back() + dt * sqrt(y.back());

        y.push_back(y_n_1);

    }

    cout << "Final Value of y: " << y.back() << '\n';

   /* 

    ofstream outFile("ode.dat");
    if (outFile.is_open()){
        for (const double& current_val_t : t){
        outFile << current_val_t << '\n';
    }
        for (const double& current_val_y : y){
        outFile << current_val_y << '\n';
    }
        outFile.close();    
    }

    */

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
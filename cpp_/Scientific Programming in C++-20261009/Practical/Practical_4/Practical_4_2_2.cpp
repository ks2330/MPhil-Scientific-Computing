#include <iostream>
#include <array>

const int size = 3;

double det(const std::array<std::array<int, size>, size>& M){
    
    double a = M[0][0];
    double e = M[1][1];
    double i = M[2][2];
    double f = M[1][2];
    double h = M[2][1];
    double b = M[0][1];
    double d = M[1][0];
    double g = M[2][0];
    double c = M[0][2];

    double det_M;

    return det_M = a*(e * i - f * h) - b*(d * i- f * g) + c*(d * h - e * g);
}

double trace(const std::array<std::array<int, size>, size>& M){
    double tr;
    for(int i = 0; i < M.size(); i++){
        tr += M[i][i];
    }
    return tr;
}

int main(){
    std::array<std::array<int, size>, size> testM = {{
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    }};

    std::cout << "Determinant: " << det(testM) << std::endl;
    std::cout << "Trace: " << trace(testM) << std::endl;
    return 0;
}
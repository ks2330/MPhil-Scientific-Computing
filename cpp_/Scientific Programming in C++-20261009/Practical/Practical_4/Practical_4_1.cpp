#include <iostream>
#include <cmath>

int sum(int a, int b){
    return a + b;
}

void decrease(int& a, int b){
    a -= b;
}


int q(double a, double b, double c, double& x1, double& x2){
    int slns;
    double discrimanant = b*b - 4 * a *c;
    if (discrimanant > 0) {
        x1 = (- b + sqrt(discrimanant)) / (2*a);
        x2 = (- b - sqrt(discrimanant)) / (2*a);
        slns = 2;

    } else if (discrimanant == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
        slns = 1; 
    } else {
        slns = 0;
    }
    return slns;

}


int main(){

    int x = 10;
    int y = 7;

    decrease(x, y);

    std::cout << "x is now: " << x << std::endl;

    return 0;

}

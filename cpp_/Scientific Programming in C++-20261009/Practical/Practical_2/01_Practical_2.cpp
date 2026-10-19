#include <stdio.h>
#include <iostream>
#include <cmath>

int main() {

    double a, b, c;

    std::cout << "Please enter Quadratic Equation: " << std::endl;
    std::cout << "Please enter a: " << std::endl;
    std::cin >> a;

    std::cout << "Please enter b: " << std::endl;
    std::cin >> b;

    std::cout << "Please enter c: " << std::endl;
    std::cin >> c;

    std::cout << "Quadratic is: " << a << "xx + " << b << "x + " << c << std::endl;

    double quad1, quad2;

    double discrimanant = b*b - 4 * a *c;

    if (discrimanant > 0 || discrimanant == 0) {
        quad1 = (- b + sqrt(discrimanant)) / (2*a);
        quad2 = (- b - sqrt(discrimanant)) / (2*a);
        std::cout << "x1: " << quad1 << std::endl;
        std::cout << "x2: " << quad2 << std::endl;

    } else {
        quad1 = (-b/(2*a));
        quad2 = (-b/(2*a));
        discrimanant = sqrt(-1*discrimanant) / (2*a);
        std::cout << "x1: " << quad1 << " + " << discrimanant << "i" << std::endl;
        std::cout << "x2: " << quad2 << " - " << discrimanant << "i" << std::endl;
    }



    return 0;
}

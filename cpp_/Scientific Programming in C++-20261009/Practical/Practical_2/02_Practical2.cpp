#include <iostream>

int main()
{

    int a; 
    do  {
        std::cout << "Please enter number: "<< '\n';
        std::cin >> a;
        } while (a < 1 );

            for (int i = 0; i <= a; i++){
                std::cout << i*i << '\n';
            }
    return 0;
}
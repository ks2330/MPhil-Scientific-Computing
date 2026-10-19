// Float to Integer Truncation

#include <iostream>

int main(void)
{
    float c = 1e34;
    std::cout << c << std::endl;
    int b = c;
    std::cout << b << std::endl;
    return 0;
}

/*

    The float got truncated once converted to an int
    Float can be stored upto a much larger number 3.4 x 10^34 so 1e34 is easy enough
    But once its casted to an int which max is 2.14x0^9 there is undefined behaviour

*/
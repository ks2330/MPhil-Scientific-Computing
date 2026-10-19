#include <iostream>
#include <array>

const int n = 20;
std::array<int, 20> a = {1, 2, 3, 4, 5 ,6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
std::array<int, 20> l = {0};


void partial_sum(const std::array<int, n>& a, std::array<int, n>& l){
    for (int i = 0; i < a.size(); i++){
        if (i == 0){
            l[i] = a[i];
            continue;
        }

        l[i] = l[i-1] + a[i];
    }

    for (const auto& element : l){
        std::cout << element << " ";
    }
}


int main() {
    partial_sum(a, l);
    return 0;
}
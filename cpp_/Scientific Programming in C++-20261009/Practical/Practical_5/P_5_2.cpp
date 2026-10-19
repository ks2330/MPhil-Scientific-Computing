#include <iostream>


class Array{
    private:
        int N;
        int* data;

    public:
    // Constructor
        Array(int n){
            N = n;
            data = new int[N*N];
        }

    // Destructor
        ~Array(){
            delete[] data;
        }
    
    void get(int i, int j){
        std::cout << data[N*(i-1) + (j - 1)] << std::endl;
    }

    // Operation
        int& operator()(int i, int j){
            return data[N*(i-1) + (j - 1)]; 
        }
};


int main(){
    int N = 5;
    Array a(N);

    a(2,3) = 10;
    a.get(2, 3);
}
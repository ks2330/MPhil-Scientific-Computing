#include <iostream>


class Array{
    private:
        int N;
        int** data;

    public:
    // Constructor
        Array(int n){
            N = n;
            data = new int*[N];
            for (int i = 0; i < N; i++) {
                data[i] = new int[N]; // Allocates N elements for each row
            }
        }

    // Destructor
        ~Array(){
            for(int i = 0; i < N; i++){
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    
    void get(int i, int j){
        int* row = data[i - 1];
        int Aij = row[j - 1];
        std::cout << Aij << std::endl;
    }

    // Operation
        int& operator()(int i, int j){
            int* row = data[i - 1];
            return row[j - 1]; 
        }
};


int main(){
    int N = 5;
    Array a(N);

    a(2,3) = 12;
    a.get(2, 3);
    a(5,5) = 100;
    a.get(5,5);
}
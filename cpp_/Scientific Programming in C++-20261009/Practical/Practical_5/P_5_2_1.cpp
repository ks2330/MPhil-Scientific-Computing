#include <iostream>

template <typename T>
class Array{
    private:
        int N;
        T** data;

    public:
    // Constructor
        Array(const int n){
            N = n;
            data = new T*[N];
            for (int i = 0; i < N; i++) {
                data[i] = new T[N];
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

    /*  Should have a copy constructor and an assignment operator
        To ensure  
    */

    // Copy Constructor

        Array(const Array<T> &old_A){
            N = old_A.N;
            data = new T*[N];
            for (int i = 0; i < N; i++) {
                data[i] = new T[N];
                for (int j = 0; j < N; j++){
                    data[i][j] = old_A.data[i][j];
                }
            }
        }

    // Getter
        T get(int i, int j) const{
            T* row = data[i - 1];
            std::cout << row[j - 1] << std::endl;
            return row[j - 1];
        }

    // Operations
        T& operator()(int i, int j){
            T* row = data[i - 1];
            return row[j - 1]; 
        }

        Array<T> operator+(const Array<T>& A, const Array<T>& B){
            Array<T> C(A.size);
            for (int i = 1; i <= A.rows(); ++i) {
                for (int j = 1; j <= A.cols(); ++j) {
            result(i, j) = A(i, j) + B(i, j); 
            return C;
        }
    }

    return result; 
        }

    //    
        Array<T>& operator=(const Array<T>& old_A) {
            if (this == &old_A) {
                return *this;
            }

            for (int i = 0; i < N; i++) {
                delete[] data[i];
            }
            delete[] data;

            N = old_A.N;

            data = new T*[N];
            for (int i = 0; i < N; i++) {
                data[i] = new T[N];
                
                for (int j = 0; j < N; j++) {
                    data[i][j] = old_A.data[i][j];
                }
            }

            return *this;
        }

};


int main(){
    int N = 5;
    Array<int> a(N);

    a(2,3) = 12;
    a.get(2, 3);
    a(5,5) = 100;
    a.get(5,5);

    Array<int> b(N);
    b = a;
    a.get(2, 3);
}
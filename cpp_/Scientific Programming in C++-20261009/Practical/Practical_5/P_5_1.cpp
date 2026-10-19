#include <iostream>

const int N = 6;
int* p = new int[N](); 
int* n = new int[N](); 

void calcNextRow(const int* prevRow, int* nextRow, int rowNo){

    for(int i = 0; i < N; i++){

        if( i == 0){
            nextRow[i] = prevRow[i] + 0;
        } else{
            nextRow[i] = prevRow[i] + prevRow[i - 1];
        }
        std::cout << nextRow[i] << ", ";    
    }

    std::cout << std::endl;

    
}

int main(){


    p[0] = 1;
    n[0] = 0;

    for(int i = 0; i < N; i++){
        std::cout << p[i] << ", "; 
    }

    std::cout << " " << std::endl;

    for (int j = 0; j < N; j++){
        calcNextRow(p, n, N);
        
        int* tmpRow = p;
        p = n;
        n = tmpRow;
    }


    delete[] p;
    delete[] n;
}
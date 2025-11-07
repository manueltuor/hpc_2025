#include <iostream>
using namespace std;

void swap_axis0(int **M, int **M2, int rows, int cols) {
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            *(*(M2+i)+j) = *(*(M+rows-1-i)+cols-1-j);
}

int main() {
    int rows=2, cols=5;
    int **M = new int*[rows];
    int **M2 = new int*[rows];

    for (int i=0; i<rows; i++) {
        M[i] = new int[cols];
        M2[i] = new int[cols];
    }

    for (int j=0; j<cols; j++) {
        *(M[0]+j) = j;
        *(M[1]+j) = 5+j;
    }

    swap_axis0(M, M2, rows, cols);

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++)
            cout << *(*(M2+i)+j) << " ";
        cout << endl;
    }

    for (int i=0; i<rows; i++) { delete[] M[i]; delete[] M2[i]; }
    delete[] M; delete[] M2;

    return 0;
}

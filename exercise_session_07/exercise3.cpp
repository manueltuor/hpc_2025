#include <iostream>
using namespace std;

const int NX = 14;
const int NY = 6; 

int ii(int x, int y) {
    return y * NX + x;
}

int main() {
    for (int y = 0; y < NY; y++) {
        for (int x = 0; x < NX; x++) {
            cout << "(" << x << "," << y << ") -> " << ii(x, y) << endl;
        }
    }

    cout << "Element (0,10) -> " << ii(0,10) << " (out of bounds!)" << endl;
    cout << "Element (3,0) -> " << ii(3,0) << endl;
    cout << "Element (7,4) -> " << ii(7,4) << endl;

    return 0;
}

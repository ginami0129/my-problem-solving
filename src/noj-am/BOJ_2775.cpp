#include <iostream>
using namespace std;

int main(void) {
    int apartment[15][15] = {0,};
    int T, k, n;
    for (int i = 0; i < 15; ++i) {
        apartment[0][i] = i+1;
        apartment[i][0] = 1;
    }
    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            apartment[i][j] = apartment[i][j-1] + apartment[i-1][j];
        }    
    }
    cin >> T;
    while(T) {
        cin >> k >> n;
        cout << apartment[k][n-1] << '\n';
        T--;
    }
}
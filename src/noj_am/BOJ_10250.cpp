#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int H, W, N, T;
    int floor, number;
    cin >> T;
    while(T) {
        cin >> H >> W >> N;
        floor = N % H == 0 ? H : N % H;
        number = ceil((float)N / H);
        cout << floor * 100 + number << endl;
        --T;
    }
}
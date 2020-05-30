#include <iostream>
using namespace std;

int main(void) {
    int H, M;
    cin >> H >> M;
    int hour[24], min[60];
    for (int i = 0; i < 24; ++i) {
        hour[i] = 23 - i;
    }
    for (int i = 0; i < 60; ++i) {
        min[i] = 59 - i;
    }
    cout << (M - 45 < 0 ? hour[(23 - H + 1) % 24] : hour[23 - H]) << " ";
    cout << min[(59 - M + 45) % 60] << endl;
}

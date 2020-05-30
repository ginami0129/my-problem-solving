#include <iostream>
using namespace std;

int main(void) {
    int A,B,C;
    cin >> A >> B >> C;
    cout << (B < C ? A/(C-B) + 1 : -1) << '\n';
}
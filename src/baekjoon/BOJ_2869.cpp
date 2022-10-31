#include <iostream>
using namespace std;

int main (void) {
    int A, B, V;
    cin >> A >> B >> V;
    int diff = A - B;
    int start = A - (diff - 1);
    int end = V;
    cout << 1 + (end - start) / diff << endl;
}
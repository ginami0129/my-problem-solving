#include <iostream>
using namespace std;

int main(void) {
  int N;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N-i; ++j) {
      cout << '*';
    }
    cout << '\n';
  }
}
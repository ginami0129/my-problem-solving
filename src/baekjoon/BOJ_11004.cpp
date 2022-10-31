#include <algorithm>
#include <iostream>
#define MAX 5000000
using namespace std;

int main(void) {
  int N, K;
  int num[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> num[i];
  }
  nth_element(num, num + K - 1, num + N);
  cout << num[K-1] << '\n';
}
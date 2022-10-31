#include <algorithm>
#include <iostream>
#define MAX 100000
using namespace std;

int main(void) {
  int N, count = 1, max = 1;
  long long num[MAX] = {0};
  long long result;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> num[i];
  }
  sort(num, num + N);
  result = num[0];
  for (int i = 1; i < N; ++i) {
    if (num[i - 1] == num[i]) {
      ++count;
    } else {
      count = 1;
    }
    if (max < count) {
      max = count;
      result = num[i];
    }
  }
  cout << result << '\n';
}
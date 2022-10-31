#include <iostream>
#define MAX 100001
using namespace std;

int main(void) {
  int N, result = -1000;
  int d[MAX] = {0};
  int num[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> num[i];
    d[i] = max(d[i - 1] + num[i], num[i]);
    result = max(result, d[i]);
  }
  cout << result << '\n';
}
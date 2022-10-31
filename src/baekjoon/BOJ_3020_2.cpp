#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 1e5 + 1;
int down[MAX], up[MAX];
int N, H;

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N >> H, N /= 2;
  for (int i = 0; i < N; ++i) {
    cin >> down[i] >> up[i];
  }
  sort(down, down + N);
  sort(up, up + N);
  int cnt = 0, min = MAX, temp = 0;
  for (int i = 1; i <= H; ++i) {
    temp = N - (lower_bound(down, down + N, i) - down);
    temp += N - (upper_bound(up, up + N, H - i) - up);
    if (temp < min) {
      cnt = 1;
      min = temp;
    } else if (temp == min) {
      ++cnt;
    }
  }
  cout << min << " " << cnt << '\n';
  return 0;
}
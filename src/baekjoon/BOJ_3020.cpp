#include <iostream>
using namespace std;

const int MAX = 5e5 + 2;
int N, H;
int imos[MAX];

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N >> H;
  int length;
  for (int i = 0; i < N; ++i) {
    cin >> length;
    if (i % 2 == 0)
      ++imos[1], --imos[length + 1];
    else
      ++imos[H - length + 1], --imos[H + 1];
  }
  for (int i = 1; i < H + 1; ++i) {
    imos[i] += imos[i - 1];
  }
  int min = 2e5 + 1, count = 0;
  for (int i = 1; i < H + 1; ++i) {
    if (min == imos[i]) {
      ++count;
    } else if (imos[i] < min) {
      count = 1;
      min = imos[i];
    }
  }
  cout << min << " " << count << '\n';
  return 0;
}
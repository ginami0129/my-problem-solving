#include <algorithm>
#include <iostream>
#include <utility>
#define MAX 100000
using namespace std;

int main(void) {
  int N;
  pair<int, int> p[MAX];
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + N);
  for (int i = 0; i < N; ++i) {
    cout << p[i].first << " " << p[i].second << '\n';
  }
}
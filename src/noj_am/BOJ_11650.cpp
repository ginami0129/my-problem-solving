#include <algorithm>
#include <iostream>
#include <utility>
#define MAX 100000
using namespace std;

bool cmp(pair<int, int> P1, pair<int, int> P2) {
  if (P1.first == P2.first) {
    return P1.second < P2.second;
  } else {
    return P1.first < P2.first;
  }
}

int main(void) {
  int N;
  pair<int, int> P[MAX];
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> P[i].first >> P[i].second;
  }
  sort(P, P + N, cmp);
  for (int i = 0; i < N; ++i) {
    cout << P[i].first << " " << P[i].second << '\n';
  }
}
#include <algorithm>
#include <iostream>
#include <utility>
#define MAX 100000
using namespace std;

int main(void) {
  int N;
  pair<int, int> P[MAX];
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> P[i].second >> P[i].first;
  }
  sort(P, P + N);
  for (int i = 0; i < N; ++i) {
    cout << P[i].second << " " << P[i].first << '\n';
  }
}
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#define MAX 100000
using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2) {
  return p1.first < p2.first;
}

int main(void) {
  int N;
  pair<int, string> people[MAX];
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> people[i].first >> people[i].second;
  }
  stable_sort(people, people + N, cmp);
  for (int i = 0; i < N; ++i) {
    cout << people[i].first << " " << people[i].second << '\n';
  }
}
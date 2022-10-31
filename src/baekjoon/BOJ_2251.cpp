#include <iostream>
#define MAX 201

using namespace std;
int max_volume[3];
bool flag[MAX][MAX][MAX];
int ans[MAX];
int capacity, water;

void dfs(int A, int B, int C) {
  int volume[3];
  if (flag[A][B][C] == true) return;
  if (A == 0) ++ans[C];
  flag[A][B][C] = true;
  int to;
  for (int from = 0; from < 3; ++from) {
    for (int move = 1; move < 3; ++move) {
      to = (from + move) % 3;
      volume[0] = A, volume[1] = B, volume[2] = C;
      water = min(volume[from], max_volume[to] - volume[to]);
      volume[from] -= water;
      volume[to] += water;
      dfs(volume[0], volume[1], volume[2]);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  for (int i = 0; i < 3; ++i) {
    cin >> max_volume[i];
  }
  dfs(0, 0, max_volume[2]);
  for (int i = 0; i < MAX; ++i) {
    if (!ans[i]) continue;
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
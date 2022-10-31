#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;
int N, M;
int height = ceil(log2(MAX));
int tree_size = (1 << (height + 1));
vector<int> number(MAX);
vector<pair<int, int> > tree(tree_size);

pair<int, int> init(int node, int start, int end) {
  if (start == end) return tree[node] = make_pair(number[start], number[end]);
  pair<int, int> op1, op2;
  op1 = init(2 * node, start, start + (end - start) / 2);
  op2 = init(2 * node + 1, start + (end - start) / 2 + 1, end);
  return tree[node] =
             make_pair(min(op1.first, op2.first), max(op1.second, op2.second));
}

pair<int, int> minMax(int node, int start, int end, int left, int right) {
  pair<int, int> op1, op2;
  if (right < start || end < left) {
    return make_pair(1e9, 0);
  } else if (left <= start && end <= right) {
    return tree[node];
  } else {
    op1 = minMax(2 * node, start, start + (end - start) / 2, left, right);
    op2 = minMax(2 * node + 1, start + (end - start) / 2 + 1, end, left, right);
    return make_pair(min(op1.first, op2.first), max(op1.second, op2.second));
  }
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> number[i];
  }
  init(1, 1, N);
  pair<int, int> range, ans;
  for (int i = 0; i < M; ++i) {
    cin >> range.first >> range.second;
    ans = minMax(1, 1, N, range.first, range.second);
    cout << ans.first << " " << ans.second << '\n';
  }
  return 0;
}
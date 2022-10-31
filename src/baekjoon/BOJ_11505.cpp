#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N, M, K, a, b, c;
const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
int height = ceil(log2(MAX));
int tree_size = 1 << (height + 1);
vector<int> number(MAX);
vector<int> tree(tree_size);

int init(int node, int start, int end) {
  if (start == end) return tree[node] = number[start] % MOD;
  return tree[node] = ll(init(2 * node, start, start + (end - start) / 2)) *
                      init(2 * node + 1, start + (end - start) / 2 + 1, end) %
                      MOD;
}

int multiply(int node, int start, int end, int left, int right) {
  if (end < left || right < start)
    return 1;
  else if (left <= start && end <= right)
    return tree[node];
  return ll(multiply(2 * node, start, start + (end - start) / 2, left, right)) *
         multiply(2 * node + 1, start + (end - start) / 2 + 1, end, left,
                  right) %
         MOD;
}

int update(int node, int start, int end, int index, int n) {
  if (index < start || index > end) return tree[node];
  if (start == end) return tree[node] = n;
  return tree[node] =
             ll(update(2 * node, start, start + (end - start) / 2, index, n)) *
             update(2 * node + 1, start + (end - start) / 2 + 1, end, index,
                    n) %
             MOD;
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N >> M >> K, M += K;
  for (int i = 1; i < N + 1; ++i) {
    cin >> number[i];
  }
  init(1, 1, N);
  while (M--) {
    cin >> a >> b >> c;
    switch (a) {
      case 1:
        update(1, 1, N, b, c);
        break;
      case 2:
        cout << multiply(1, 1, N, b, c) << '\n';
        break;
    }
  }
  return 0;
}
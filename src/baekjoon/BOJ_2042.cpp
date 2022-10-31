#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 1;
int h = (int)ceil(log2(MAX));
int tree_size = (1 << (h + 1));

int N, M, K;
vector<ll> number(MAX);
vector<ll> tree(tree_size);

ll init(int node, int start, int end) {
  if (start == end) {
    return tree[node] = number[start];
  } else {
    return tree[node] = init(node * 2, start, start + (end - start) / 2) +
                        init(node * 2 + 1, start + (end - start) / 2 + 1, end);
  }
}

ll sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start) {
    return 0;
  } else if (left <= start && end <= right) {
    return tree[node];
  } else {
    return sum(node * 2, start, start + (end - start) / 2, left, right) +
           sum(node * 2 + 1, start + (end - start) / 2 + 1, end, left, right);
  }
}

void update(int node, int start, int end, int index, ll diff) {
  if (index < start || index > end) return;
  tree[node] += diff;
  if (start != end) {
    update(node * 2, start, start + (end - start) / 2, index, diff);
    update(node * 2 + 1, start + (end - start) / 2 + 1, end, index, diff);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N >> M >> K, M += K;
  for (int i = 1; i <= N; ++i) {
    cin >> number[i];
  }
  init(1, 1, N);
  ll a, b, c;
  while (M--) {
    cin >> a >> b >> c;
    switch (a) {
      case 1:
        update(1, 1, N, b, c - number[b]);
        number[b] = c;
        break;
      case 2:
        cout << sum(1, 1, N, b, c) << '\n';
        break;
    }
  }
  return 0;
}
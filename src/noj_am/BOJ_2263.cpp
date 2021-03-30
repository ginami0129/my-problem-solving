#include <iostream>
using namespace std;

int v, n;
int post_order[100002];
int in_order[100002];

void pre_order(int inStart, int inEnd, int postStart, int postEnd) {
  if (inStart > inEnd || postStart > postEnd) return;
  int root = post_order[postEnd];
  cout << root << ' ';
  int mid = in_order[root];
  pre_order(inStart, mid - 1, postStart, postStart + mid - inStart - 1);
  pre_order(mid + 1, inEnd, postStart + mid - inStart, postEnd - 1);
}
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    in_order[v] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    post_order[i] = v;
  }
  pre_order(1, n, 1, n);
}

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  vector<int> d(100001, 0);
  int N, temp;
  cin >> N;
  while (N) {
    cin >> temp;
    ++d[temp];
    --N;
  }
  for (int i = 1; i < d.size(); ++i) {
    if (d[i] == 1) {
      cout << i << " ";
    }
  }
}

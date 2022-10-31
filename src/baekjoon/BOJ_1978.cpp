#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  int N;
  int num = 0;
  int count = 0;
  bool d[MAX * 10] = {
      1,
      1,
  };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i <= 100; ++i) {
    if (d[i] == false) {
      for (int j = i * i; j <= 1000; j += i) {
        d[j] = true;
      }
    }
  }
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> num;
    if (!d[num]) ++count;
  }
  cout << count << '\n';
}
#include <iostream>
#define MAX_SIZE 1000000
using namespace std;

int main(void) {
  int S, C;
  int onion_number = 0;
  long long sum = 0;
  int onion[MAX_SIZE] = {0, };
  ios_base::sync_with_stdio(false);
  cin >> S >> C;
  for(int i = 0; i < S; ++i) {
    cin >> onion[i];
    sum += onion[i];
  }
  int start = 1;
  int end = 1e9;
  long long mid = (start + end) / 2;
  while (start <= end) {
    onion_number = 0;
    for (int i = 0; i < S; ++i) {
      onion_number += onion[i] / mid;
    }
    if (onion_number >= C) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = (start + end) / 2;
  }
  cout << sum - mid * C << '\n';
}
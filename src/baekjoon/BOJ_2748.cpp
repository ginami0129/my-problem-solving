#include <iostream>
#define MAX_SIZE 100
using namespace std;

int main(void) {
  int n;
  long long fibo[MAX_SIZE] = {0,1, };
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 2; i < MAX_SIZE; ++i) {
    fibo[i] = fibo[i-1] + fibo[i-2];
  }
  cout << fibo[n] << '\n';
}
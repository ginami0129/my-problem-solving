#include <iostream>
#define MAX_SIZE 91
using namespace std;

int main(void) {
  int N;
  long long d[MAX_SIZE] = {0, 1, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i < MAX_SIZE; ++i) {
    d[i] = d[i-1] + d[i-2]; 
  }
  cin >>N;
  cout << d[N] << '\n';
}
#include <iostream>
#define MAX_SIZE 31
using namespace std;

int main(void) {
  int N;
  int d[MAX_SIZE] ={1, 0, 3, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 4; i <= N; i+=2) {
    d[i] =  3*d[i-2];
    for (int j = i-4; j >= 0; j-=2) {
      d[i] += 2*d[j];
    }
  }
  cout << d[N] << '\n';
}
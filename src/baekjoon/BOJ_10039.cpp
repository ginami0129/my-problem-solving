#include <iostream>
using namespace std;

int score[5], sum;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 5; ++i) {
    cin >> score[i];
    sum += (score[i] < 40 ? 40 : score[i]);
  }
  cout << sum / 5 << '\n';
}
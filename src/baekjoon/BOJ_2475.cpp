#include <iostream>
using namespace std;

int arr[5], sum;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 5; ++i) {
    cin >> arr[i];
    sum += arr[i] * arr[i];
  }
  cout << sum % 10 << '\n';
}
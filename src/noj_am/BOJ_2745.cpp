#include <cstring>
#include <iostream>
#define MAX 32
using namespace std;

int main(void) {
  int B, digit = 1, result = 0;
  char num[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> num >> B;
  for (int i = strlen(num) - 1; i >= 0; --i) {
    num[i] -= (num[i] >= 'A' ? 'A' - 10 : '0');
    result += digit * num[i];
    digit *= B;
  }
  cout << result << '\n';
}
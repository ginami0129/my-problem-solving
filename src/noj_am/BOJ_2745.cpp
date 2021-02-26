#include <cstring>
#include <iostream>
#define MAX 32
using namespace std;

int main(void) {
  int B, num, digit = 1, result = 0;
  char d[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> d >> B;
  for (int j = strlen(d) - 1; j >= 0; --j) {
    num = (d[j] >= 'A' ? d[j] + 10 - 'A' : d[j] - '0');
    result += num * digit;
    digit *= B;
  }
  cout << result << '\n';
}
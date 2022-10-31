#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  char input[MAX] = {0};
  int count = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  for (; input[count]; ++count) {
  }
  cout << count << '\n';
}
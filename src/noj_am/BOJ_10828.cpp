#include <iostream>
#define MAX 10000
using namespace std;

int main(void) {
  int N, data;
  string str;
  int top = -1;
  int stack[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> str;
    if (str == "push") {
      cin >> data;
      stack[++top] = data;
    } else if (str == "pop") {
      cout << (top == -1 ? top : stack[top--]) << '\n';
    } else if (str == "top") {
      cout << (top == -1 ? top : stack[top]) << '\n';
    } else if (str == "size") {
      cout << top + 1 << '\n';
    } else if (str == "empty") {
      cout << (top == -1 ? 1 : 0) << '\n';
    }
  }
}
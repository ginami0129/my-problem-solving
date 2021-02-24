#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

int main(void) {
  int N;
  int queue[MAX] = {0};
  int front = 0, rear = -1;
  int count;
  string input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> input;
    if (input == "push") {
      cin >> queue[++rear];
    } else if (input == "pop") {
      cout << (front > rear ? -1 : queue[front++]) << '\n';
    } else if (input == "size") {
      cout << max(0, rear - front + 1) << '\n';
    } else if (input == "empty") {
      cout << (front > rear) << '\n';
    } else if (input == "front") {
      cout << (front > rear ? -1 : queue[front]) << '\n';
    } else if (input == "back") {
      cout << (front > rear ? -1 : queue[rear]) << '\n';
    }
  }
}
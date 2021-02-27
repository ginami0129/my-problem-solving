#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int main(void) {
  int N, front = 0, rear = -1;
  int queue[MAX] = {0};
  string command;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> command;
    if (command == "push") {
      cin >> queue[++rear];
    } else if (command == "size") {
      cout << rear - front + 1 << '\n';
    } else if (command == "empty") {
      cout << (rear < front) << '\n';
    } else if (rear < front) {
      cout << -1 << '\n';
    } else if (command == "pop") {
      cout << queue[front++] << '\n';
    } else if (command == "front") {
      cout << queue[front] << '\n';
    } else if (command == "back") {
      cout << queue[rear] << '\n';
    }
  }
}
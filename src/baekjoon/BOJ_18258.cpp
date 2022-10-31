#include <iostream>
#define MAX 2000000
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, front = 0, rear = -1;
  int queue[MAX] = {0};
  cin >> N;
  while (N--) {
    string command;
    cin >> command;
    if (command == "push") {
      cin >> queue[++rear];
    } else if (command == "size") {
      cout << rear - front + 1 << '\n';
    } else if (command == "empty") {
      cout << (front > rear) << '\n';
    } else if (front > rear) {
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
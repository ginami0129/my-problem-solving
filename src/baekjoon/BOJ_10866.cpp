#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int main(void) {
  int N, count = 0;
  int front = 0, rear = MAX - 1;
  int deque[MAX] = {0};
  string input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> input;
    if (input == "push_front") {
      front = (front - 1 + MAX) % MAX;
      cin >> deque[front];
      ++count;
    } else if (input == "push_back") {
      rear = (rear + 1) % MAX;
      cin >> deque[rear];
      ++count;
    } else if (input == "size") {
      cout << count << '\n';
    } else if (input == "empty") {
      cout << (count == 0) << '\n';
    } else if (count == 0) {
      cout << -1 << '\n';
    } else if (input == "pop_front") {
      cout << deque[front] << '\n';
      front = (front + 1) % MAX;
      --count;
    } else if (input == "pop_back") {
      cout << deque[rear] << '\n';
      rear = (rear - 1 + MAX) % MAX;
      --count;
    } else if (input == "front") {
      cout << deque[front] << '\n';
    } else if (input == "back") {
      cout << deque[rear] << '\n';
    }
  }
}
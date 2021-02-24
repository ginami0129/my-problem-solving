#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int main(void) {
  int N;
  int deque[MAX] = {0};
  int count = 0, front = MAX - 1, rear = 0;
  string input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> input;
    if (input == "push_front") {
      front = (front + 1) % MAX;
      cin >> deque[front];
      ++count;
    } else if (input == "push_back") {
      rear = (rear + MAX - 1) % MAX;
      cin >> deque[rear];
      ++count;
    } else if (input == "pop_back") {
      if (count == 0) {
        cout << -1 << '\n';
      } else {
        cout << deque[rear] << '\n';
        rear = (rear + 1) % MAX;
        --count;
      }
    } else if (input == "pop_front") {
      if (count == 0) {
        cout << -1 << '\n';
      } else {
        cout << deque[front] << '\n';
        front = (front - 1 + MAX) % MAX;
        --count;
      }
    } else if (input == "size") {
      cout << count << '\n';
    } else if (input == "empty") {
      cout << (count == 0) << '\n';
    } else if (input == "front") {
      cout << (count == 0 ? -1 : deque[front]) << '\n';
    } else if (input == "back") {
      cout << (count == 0 ? -1 : deque[rear]) << '\n';
    }
  }
}
#include <iostream>
#define MAX 100001
using namespace std;

typedef struct Node {
  char data;
  Node* prev;
  Node* next;
} Node;

int main(void) {
  char input[MAX] = {0};
  char command;
  int M;
  Node* cursor = nullptr;
  Node* node = nullptr;
  Node* head = new Node();
  Node* tail = new Node();
  head->next = tail;
  head->prev = nullptr;
  tail->prev = head;
  tail->prev = nullptr;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  cursor = head;
  for (int i = 0; input[i]; ++i, cursor = cursor->next) {
    node = new Node();
    node->data = input[i];
    node->prev = cursor;
    node->next = cursor->next;
    cursor->next->prev = node;
    cursor->next = node;
  }
  cursor = tail;
  cin >> M;
  while (M--) {
    cin >> command;
    if (command == 'L') {
      if (cursor->prev->prev != nullptr) {
        cursor = cursor->prev;
      }
    } else if (command == 'D') {
      if (cursor->next != nullptr) {
        cursor = cursor->next;
      }
    } else if (command == 'B') {
      if (cursor->prev->prev != nullptr) {
        node = cursor->prev;
        cursor->prev = node->prev;
        node->prev->next = cursor;
        delete (node);
      }
    } else if (command == 'P') {
      node = new Node();
      cin >> node->data;
      node->next = cursor;
      node->prev = cursor->prev;
      cursor->prev->next = node;
      cursor->prev = node;
    }
  }
  for (cursor = head->next; cursor->next; cursor = cursor->next) {
    cout << cursor->data;
  }
  cout << '\n';
}
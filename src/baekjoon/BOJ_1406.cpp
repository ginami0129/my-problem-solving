#include <iostream>
using namespace std;

typedef struct Node {
  char data;
  Node *prev = nullptr;
  Node *next = nullptr;
} Node;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  Node *head = new Node;
  Node *tail = new Node;
  head->next = tail;
  tail->prev = head;
  Node *cursor = head;
  Node *node = nullptr;
  for (int i = 0; i < str.size(); ++i) {
    node = new Node;
    node->data = str[i];
    node->prev = cursor;
    node->next = cursor->next;
    cursor->next->prev = node;
    cursor->next = node;
    cursor = cursor->next;
  }
  int N;
  cin >> N;
  cursor = tail;
  while (N--) {
    char command;
    cin >> command;
    if (command == 'L' && cursor->prev->prev) {
      cursor = cursor->prev;
    } else if (command == 'D' && cursor->next) {
      cursor = cursor->next;
    } else if (command == 'B' && cursor->prev->prev) {
      node = cursor->prev;
      cursor->prev = node->prev;
      node->prev->next = cursor;
      delete (node);
    } else if (command == 'P') {
      node = new Node;
      cin >> node->data;
      node->next = cursor;
      node->prev = cursor->prev;
      cursor->prev->next = node;
      cursor->prev = node;
    }
  }
  cursor = head->next;
  while (cursor->next) {
    cout << cursor->data;
    cursor = cursor->next;
  }
}
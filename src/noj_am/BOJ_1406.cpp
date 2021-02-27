#include <iostream>
#define MAX 100001
using namespace std;

typedef struct Node {
  char data;
  Node* prev;
  Node* next;
} Node;

int main(void) {
  int M;
  char str[MAX] = {0};
  char command;
  Node* node = nullptr;
  Node* cursor = nullptr;
  Node* head = new Node;
  Node* tail = new Node;
  head->next = tail;
  head->prev = nullptr;
  tail->next = nullptr;
  tail->prev = head;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> str;
  cursor = head;
  for (int i = 0; str[i]; ++i) {
    node = new Node;
    node->data = str[i];
    node->prev = cursor;
    node->next = cursor->next;
    cursor->next->prev = node;
    cursor->next = node;
    cursor = cursor->next;
  }
  cin >> M;
  cursor = tail;
  while (M--) {
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
      node->prev = cursor->prev;
      node->next = cursor;
      cursor->prev->next = node;
      cursor->prev = node;
    }
  }
  cursor = head->next;
  while (cursor->next) {
    cout << cursor->data;
    cursor = cursor->next;
  }
  cout << '\n';
}
#include <iostream>
#define MAX 100001
using namespace std;

typedef struct Node {
  char c;
  Node* prev;
  Node* next;
} Node;

int main(void) {
  char input[MAX] = {0};
  int N;
  Node* head = new Node;
  Node* tail = new Node;
  head->prev = nullptr;
  head->next = tail;
  tail->prev = head;
  tail->next = nullptr;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  Node* cursor = head;
  Node* node = nullptr;
  for (int i = 0; input[i]; ++i) {
    node = new Node();
    node->c = input[i];
    node->next = cursor->next;
    node->prev = cursor;
    cursor->next->prev = node;
    cursor->next = node;
    cursor = cursor->next;
  }
  cursor = cursor->next;
  cin >> N;
  char command, data;
  Node* temp = nullptr;
  while (N--) {
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
        temp = cursor->prev;
        temp->prev->next = cursor;
        cursor->prev = temp->prev;
        delete (temp);
      }
    } else if (command == 'P') {
      cin >> data;
      temp = new Node;
      temp->c = data;
      temp->next = cursor;
      temp->prev = cursor->prev;
      cursor->prev->next = temp;
      cursor->prev = temp;
    }
  }
  temp = head->next;
  while (temp->next) {
    cout << temp->c;
    temp = temp->next;
  }
  cout << '\n';
}
#include <iostream>
using namespace std;

typedef struct Node {
  int data;
  Node* next;
} Node;

int main(void) {
  int N, K, count;
  Node* node = nullptr;
  Node* head = new Node;
  Node* temp = head;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    node = new Node();
    node->data = i;
    temp->next = node;
    temp = temp->next;
  }
  temp->next = head->next;
  cout << '<';
  while (--N) {
    count = K;
    while (--count) {
      temp = temp->next;
    }
    node = temp->next;
    temp->next = node->next;
    cout << node->data << ", ";
    delete (node);
  }
  cout << temp->data << ">\n";
}
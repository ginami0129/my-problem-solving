#include <iostream>
using namespace std;

typedef struct Node {
  int data;
  Node *left = nullptr, *right = nullptr;
} Node;
int num;
Node *root = nullptr;

void insert(Node *&node, int data) {
  if (node == nullptr) {
    node = new Node;
    node->data = data;
  } else if (node->data < data) {
    insert(node->right, data);
  } else if (node->data > data) {
    insert(node->left, data);
  }
}

void postorder(Node *node) {
  if (node == nullptr) return;
  postorder(node->left);
  postorder(node->right);
  cout << node->data << '\n';
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  while (cin >> num) {
    insert(root, num);
  }
  postorder(root);
}
#include <iostream>
using namespace std;

typedef struct Node {
  char data;
  Node *left = nullptr, *right = nullptr;
} Node;

Node *address['Z' + 1];
int N;

void preorder(Node *node) {
  if (node == nullptr) return;
  cout << node->data;
  preorder(node->left);
  preorder(node->right);
}

void inorder(Node *node) {
  if (node == nullptr) return;
  inorder(node->left);
  cout << node->data;
  inorder(node->right);
}

void postorder(Node *node) {
  if (node == nullptr) return;
  postorder(node->left);
  postorder(node->right);
  cout << node->data;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 'A'; i <= 'Z'; ++i) {
    address[i] = new Node();
    address[i]->data = i;
  }
  address['.'] = nullptr;
  cin >> N;
  while (N--) {
    char node, left, right;
    cin >> node >> left >> right;
    address[node]->left = address[left];
    address[node]->right = address[right];
  }
  preorder(address['A']);
  cout << '\n';
  inorder(address['A']);
  cout << '\n';
  postorder(address['A']);
  cout << '\n';
}
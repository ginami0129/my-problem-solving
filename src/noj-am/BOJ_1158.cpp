#include <iostream>
#include <string>
using namespace std;

typedef struct NodeRecord {
  int data;
  struct NodeRecord *next;
} Node;

int main(void) {
  int N, K;
  string result = "<";
  // 더미노드 생성
  Node *head = new Node;
  Node *temp = head;
  Node *node = nullptr;
  head->data = 1;
  cin >> N >> K;
  // 원형 연결리스트 생성
  for(int i = 1; i <= N; ++i) {
    node = new Node;
    node->data = i;
    temp->next = node;
    temp = temp->next;
  }
  // 마지막노드는 처음노드(더미노드 다음)
  temp->next = head->next;
  // 순회하면서 이전노드 찾아 링크 정리후 다음노드 삭제 
  temp = head;
  for(int i = 0; N > 0; ++i){
    if (i % K == K-1) {
      node = temp->next;
      result += to_string(node->data) + ", ";
      temp->next = node->next;
      delete(node);
      N--;
    } else {
      temp = temp->next;
    }
  }
  // 결과 출력
  result[result.size() - 2] = '>';
  cout << result << endl;
}
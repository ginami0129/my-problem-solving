#include <list>
using namespace std;

class Queue {
 public:
  Queue();
  Queue(const Queue &Q);
  ~Queue();
  void Push(int item);
  int Pop();
  int Size();
  bool IsEmpty();
  int Front();
  int Back();
 private:
  list<int> L;
};
// 큐 초기화 함수
// 리스트가 멤버변수기 때문에 생성할 필요가 없다.
Queue::Queue() {}
// 큐 깊은 복사생성자 함수
// 리스트의 깊은 복사생성자가 구현
Queue::Queue(const Queue &Q) {
  L = Q.L;
}
// 큐 소멸자 함수
// 리스트의 소멸자함수 호출
Queue::~Queue() {}
// 큐 Push 연산 함수
// 1. 넣고싶은 아이템을 입력한다.
// 2. 리스트의 맨 뒤에 아이템을 삽입한다
void Queue::Push(int item) {
  L.insert(L.end(), item);
}
// 큐 Pop 연산 함수
// 1. 리스트의 가장 앞의 원소를 삭제한다.
int Queue::Pop() {
  int result = L.front();
  L.erase(L.begin());
  return result;
}
// 큐의 길이 알수있는 함수
int Queue::Size() {
  return L.size();
}
// 큐가 비어있는지 확인하는 함수
bool Queue::IsEmpty() {
  return Size() == 0;
}
// 큐의 가장 앞에 있는 정수 확인
int Queue::Front() {
  return L.front();
}
// 큐의 가장 뒤에 있는 정수 확인
int Queue::Back() {
  return L.back();
}
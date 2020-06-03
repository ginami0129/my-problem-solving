#include <list>
using namespace std;

class Stack {
 public:
  Stack();
  Stack(const Stack &S);
  ~Stack();
  void Push(int item);
  int Pop();
  int Top();
  int Size();
  bool IsEmpty();
 private:
  list<int> L;
};

// 스택 초기화함수
// 리스트를 생성한다.-> 멤버변수로 선언 생성할필요 없음
Stack::Stack() {}
// 스택 깊은복사함수
// 리스트 깊은복사 구현되어있기 때문에 그냥 대입
Stack::Stack(const Stack &S) {
  L = S.L;
}
// 스택 소멸자함수
// 리스트에 구현되어있기때문에 아무것도 할필요 없음
Stack::~Stack() {}
// 스택 Push 연산 함수
// 1. 삽입하고자하는 값을 입력받는다.
// 2. 리스트의 0번 인덱스에 삽입연산을 수행한다.
void Stack::Push(int item) {
  L.insert(L.begin(), item);
}
// 스택 Pop 연산 함수
// 1. 리스트의 0번인덱스의 항목을 삭제
// 2. 삭제한 항목 반환
int Stack::Pop() {
  int result = L.front();
  L.erase(L.begin());
  return result;
}
// 스택에서 가장위에있는 원소 출력함수
int Stack::Top() {
  return L.front();
}
// 스택에 들어있는 원소의 개수 알려주는 함수
int Stack::Size() {
  return L.size();
}
// 스택 비어있는지 확인하는함수
// 리스트가 비어있는지 확인한다.
bool Stack::IsEmpty() {
  return L.empty();
}
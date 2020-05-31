typedef struct NodeRecord {
  int data;
  struct NodeRecord *prev, *next;
} Node;

class List {
 public:
  List();
  List(const List &L);
  ~List();

  void Insert(int position, int item);
  void Remove(int position);
  int Retrieve(int position) const;
  bool IsEmpty() const{return Size() == 0 ? true : false;};
  int Size() const{return count;};

 private:
  Node* GetNode(int posiiton) const;
  int count;
  Node *head;
  Node *tail;
};

// 리스트를 초기화하는 함수
//  리스트의 항목수 는 0개이다.
//  Head-> dummynode - dummynode <- tail
List::List() {
  count = 0;
  head = new Node;
  tail = new Node;
  head->next = tail;
  tail->prev = head;
}
// 리스트가 소멸할때 작동하는 함수
// 모든 노드들을 제거한다.
List::~List() {
  while(Size() > 0) {
    Remove(0);
  }
}
// 리스트를 깊은복사하는 함수
// 복사하고자하는 리스트의 항목을 가져와 해당 인덱스에 넣는다.
List::List(const List &L) {
  int item;
  for(int i = 0; i < L.Size(); ++i) {
    item = L.Retrieve(i);
    Insert(i, item);
  }
}
// 해당위치의 노드를 반환하는함수
// 검색하고자 하는 인덱스를 받는다.
// 인덱스가 앞쪽이라면 앞부터 뒤쪽이라면 뒤부터 검색한다.O(n/2)
Node* List::GetNode(int position) const{
  Node *temp = nullptr;
  if (position < Size() / 2) {
      temp = head->next;
      for(int i = 0; i < position; ++i) {
          temp = temp->next;
      }
  } else {
      temp = tail;
      for (int i = Size(); i > position; --i) {
          temp = temp->prev;
      }
  }
  return temp;
} 
// 리스트에 항목을 추가하는 함수
// 삽입할 위치와 값을 입력받는다.(유효한 위치와 값이 들어왔다고 가정)
// 노드들 만들어 값을 저장한다.
// 들어갈 위치를 찾아서 링크한다.
void List::Insert(int position, int item) {
  // 노드를 만들어 값을 저장한다.
  Node *node = new Node;
  node->data = item;
  // 들어갈 위치를 찾아서 링크한다.
  Node *temp = GetNode(position);
  // if (position == Size()) temp = temp->next;
  node->next = temp;
  node->prev = temp->prev;
  temp->prev->next = node;
  temp->prev = node;
  // 리스트 크기 증가
  ++count;
}
// 리스트의 항목을 삭제하는 함수
// 삭제할 노드의 위치를 받는다.
// 삭제할 노드를 찾는다.
// 노드를 삭제한다.
void List::Remove(int position) {
  // 삭제할 노드를 찾는다.
  Node* temp = GetNode(position);
  //노드를 삭제한다.
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete(temp);
  // 리스트 크기 감소
  --count;
}
// 리스트의 항목을 검색하는 함수
// 항목에 해당하는 노드를 찾는다.
int List::Retrieve(int position) const{
  return GetNode(position)->data;
}
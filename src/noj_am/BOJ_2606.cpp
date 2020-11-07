#include <iostream>
#include <stack>
#include <vector>
#define MAX_SIZE 100
using namespace std;
/*
컴퓨터의 연결을 그래프화 하고
노드 1부터 BFS 탐색하고 노드의 수를 출력하는 문제

BFS 알고리즘을 통해 어렵지 않게 풀었다.
BFS의 수도 코드는 BOJ 1260 참고
*/
int main(void) {
  int N,P;
  int start, end, node;
  int count = 0;
  stack<int> r;
  vector<int> computer[MAX_SIZE];
  bool is_visited[MAX_SIZE] = {1, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> P;
  for (int i = 0; i < P; ++i) {
    cin >> start >> end;
    computer[start-1].push_back(end);
    computer[end-1].push_back(start);
  }
  r.push(1);
  while(!r.empty()) {
    bool all_visited = true;
    for (auto i : computer[r.top()-1]) {
      if (is_visited[i-1] == false) {
        all_visited = false;
        node = i;
        break;
      }
    }
    if (all_visited) {
      r.pop();
    } else {
      ++count;
      r.push(node);
      is_visited[node-1] = true;
    }
  }
  cout << count << '\n';
}
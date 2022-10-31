#include <iostream>
#include <stack>
#define MAX_SIZE 100
using namespace std;
/*
인접행렬을 활용한 DFS 알고리즘을 구현하였다.

DFS알고리즘을 알고있어서 어렵지 않게 풀었으나
시작과 끝이 같을때 예외를 처리하느라 조금 시간이 걸렸다.
시작과 끝이 같으면 처음 push한 노드를 방문처리를 하지 않는다.

do while문으로 변경하여 무조건 한번은 실행시켰다.

시작과 끝이 같음에 관계없이 방문처리를 하지 않아도
실행시간의 큰 차이는 존재하지 않는다.
*/
int main(void) {
  int N;
  bool a[MAX_SIZE][MAX_SIZE] = {0, };
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a[i][j];
    }
  }
  bool is_visited[MAX_SIZE] = {0, };
  stack<int> r;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        fill_n(is_visited, MAX_SIZE, false);
        r.push(i);
        // is_visited[i] = false;
        is_visited[i] = (i == j ? false : true);
        do {
          bool all_visited = true;
          for (int i = 0; i < N; ++i) {
            if (a[r.top()][i] && !is_visited[i]) {
              all_visited = false;
              r.push(i);
              is_visited[i] = true;
              break;
            }
          }
          if (all_visited) {
            r.pop();
          }
        } while (!r.empty() && !(r.top() == j && r.size() > 1));
        cout << !r.empty() << ' ';
        while(!r.empty()) {
          r.pop();
        }
    }
    cout << '\n';
  }
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
  int N, M, V;
  int start, end;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> V;
  vector<vector<int>> graph;
  /*
  인접리스트로 그래프를 구현하였다.
  정점 번호가 작은 순으로 방문하기 때문에 오름차순으로 정렬하였다.
  */
  for (int i = 0; i < N; ++i) {
    vector<int> temp;
    graph.push_back(temp);
  }
  for (int i = 0; i < M; ++i) {
    cin >> start >> end;
    graph[start-1].push_back(end);
    graph[end-1].push_back(start);
  }
  for (int i = 0; i < N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }
  /* DFS 알고리즘 구현
    1. 맨처음 방문한 노드를 스택에 넣는다.
    2. 스택의 top과 연결된 노드를 모두 방문하였는지 확인한다.
    2-1. 모두 방문하지 않았다면, 
         처음방문한 노드 중 노드번호가 작은순 으로 방문한다. 
         방문한 노드 번호를 스택에 push한다.
    2-2. 모두 방문하였다면, 스택을 pop한다.
    3. 2번을 스택이 비어있을 때까지 한다.
    방문순서는 stack에 push 한 순서와 같다.
  */
  stack<int> route;
  vector<bool> is_first(N, true);
  route.push(V);
  cout << V << " ";
  is_first[V-1] = false;
  int node;
  while(!route.empty()) {
    bool all_visited = true;
    for (auto ptr : graph[route.top()-1]) {
        if (is_first[ptr-1] == true) {
        all_visited = false;
        node = ptr;
        break;
      }
    }
    if (all_visited) {
      route.pop();
    } else {
      route.push(node);
      is_first[node-1] = false;
      cout << node << " ";
    }
  }
  cout << '\n';
  /* BFS 알고리즘 구현
    1. 맨처음 방문한 노드를 큐에 넣는다.
    2. 스택의 front과 연결된 노드 중 
    2-1. 모두 방문하지 않았다면, 
         처음방문하는 노드중 노드번호가 작은순으로 방문한다.
         방문한 노드번호를 큐에 push한다.
    2-2. 모두 방문하였다면, 큐을 pop한다.
    3. 2번을 큐가 비어있을 때까지 한다.
    방문순서는 큐를 pop 한 순서와 같다.
  */
  queue<int> root;
  is_first.assign(N, true);
  root.push(V);
  is_first[V-1] = false;
  while(!root.empty()) {
    bool all_visited = true;
    for (auto ptr : graph[root.front()-1]) {
      if (is_first[ptr-1] == true) {
        all_visited = false;
        root.push(ptr);
        is_first[ptr-1] = false;
      }
    }
    if (all_visited) {
      cout << root.front() << " ";
      root.pop();
    }
  }
  cout << '\n';
}
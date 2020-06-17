/******************************************************************************
1.5 깊이 우선 탐색: depth-first search 구현
스택을 이용하여 그래프 파일을 로딩하여, 그래프 구조를 얻은후 사용자로부터 시
작점과 끝점을 입력받아, 깊이 우선 탐색을 수행하여 경로를 찾는 알고리즘을 구현
(DFS.cpp ) 하시오. 스택은 앞서 구현한 template stackClass<int>를 이용하라.
그래프 파일은 인접리스트방식을 사용하며, 위 그래프에서 그래프 입력 파일
(sample graph.txt)은 다음과 같다.
---------------------------------------------------
9 8
1 2 7
2 3 5
3 4
4 2
5 6 7
7 8
8 9
9 2
---------------------------------------------------
다음 프로그램 구동 시나리오이다.
---------------------------------------------------
enter staring and ending vertices> 1 6
path length: 3
1 2 5 6
enter staring and ending vertices> 5 1
not found
enter staring and ending vertices> 1 9
path length: 5
1 2 5 7 8 9
enter staring and ending vertices> ...
---------------------------------------------------
******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

int main(void) {
  int N, line;
  int start, end;
  string input;
  stringstream ss;
  vector<vector<int>> graph;
  cin >> N >> line;
  /*
  인접리스트로 그래프를 구현하였다.
  */
  for (int i = 0; i < N; ++i) {
    vector<int> temp;
    graph.push_back(temp);
  }
  for (int i = 0; i < line; ++i) {
    cin >> start;
    getline(cin, input);
    ss.str(input);
    while(ss >> end) {
      graph[start-1].push_back(end);
    }
    ss.clear();
  }
  /* DFS 알고리즘 구현
    1. 맨처음 방문한 노드를 스택에 넣는다.
    2. 스택의 top과 연결된 노드를 모두 방문하였는지 확인한다.
    2-1. 모두 방문하지 않았다면, 
         처음방문한 노드 중 노드번호가 작은순 으로 방문한다. 
         방문한 노드 번호를 스택에 push한다.
    2-2. 모두 방문하였다면, 스택을 pop한다.
    3. 2번을 스택이 비어있을 때 또는 스택의 top이 경로의 끝일때까지 한다.
    방문순서는 stack에 push 한 순서와 같다.
  */
  cout << "enter staring and ending vertices> " << endl;
  cin >> start >> end;
  deque<int> route;
  vector<bool> is_first(N, true);
  route.push_back(start);
  is_first[start-1] = false;
  int node;
  while(!route.empty() && route.back() != end) {
    bool all_visited = true;
    for (auto ptr : graph[route.back()-1]) {
      if (is_first[ptr-1] == true) {
        all_visited = false;
        node = ptr;
        break;
      }
    }
    if (all_visited) {
      route.pop_back();
    } else {
      route.push_back(node);
      is_first[node-1] = false;
    }
  }
  /* 경로출력하기
  1. 스택이 비어있으면
  1-1. 경로는 존재하지 않는다.
  2. 스택의 탑이 경로의 끝이라면
  2-1. 경로의 길이를 출력한다.
  2-2. 스택의 앞에서 부터 pop하면서 경로를 출력한다.
  */
  if (route.empty()) {
    cout << "not found" << endl;
  } else if (route.back() == end){
    cout << "path length: " << route.size()-1 << endl;
    while(!route.empty()) {
      cout << route.front() << " ";
      route.pop_front();
    }
    cout << endl;
  }
}
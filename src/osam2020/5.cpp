#include <vector>
#include <iostream>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;

// advanced algorithm
// dfs한번에 cycle의 존재 유무를 확인한다
// visited가 -1이라는 얘기는 dfs가 아직 안끝났다는 의미고 1은 dfs가 끝났다는 얘기다
bool dfs(int here) {
  if (visited[here] == -1) {
    visited[here] = 1;
    return true;
  } else if (visited[here] == 1){
    return false;
  }

  visited[here] = -1;
  for (auto there : graph[here]) {
    if (dfs(there)) {
      visited[there] = 1;
      visited[here] = 1;
      return true;
    }
  }
  visited[here] = 1;
  return false;
}

int solution(int N, vector<vector<int>> res) {
  int answer = N;
  visited.assign(N, 0);
  graph.assign(N, vector<int>());
  for (auto r : res)
    graph[r[0]].push_back(r[1]);

  // 사이클을 탐지한다.
  // 사이클이 탐지되면 answer--1;
  // 사이클이 탐지되지 않으면 answer
  // 사이클탐지시 방문하지 않은 노드를 대상으로 사이클 탐지
  // 모두 방문하면 종료

  for (int i = 0; i < N; ++i) {
    if (visited[i] != 1 && dfs(i) == true) --answer;
  }

  return answer;
}

int main(void)
{
  int answer = solution(5, {{3, 2}, {3, 0}, {4, 3}, {1, 4}});
  //int answer = solution(4, {{1,3},{3,0},{0,1},{1,2}});
  //int answer = solution(10, {{1, 2}, {7, 9}, {2, 3}, {7, 2}, {2, 8}, {2, 9}, {8, 0}, {2, 6}, {3, 1}, {4, 2}, {5, 2}, {4, 6}, {0, 5}});
  //int answer = solution(10, {{4,7},{0,2},{9,8},{8,6},{5,3},{3,0},{7,9},{2,1},{1,4},{6,5}});

  cout << answer << '\n';
}
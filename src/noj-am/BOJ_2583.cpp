#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define MAX_SIZE 100
using namespace std;

typedef struct Point {
  int x;
  int y;
} Point;

int main(void) {
  int M,N,K;
  int count = 0;
  int length = 0;
  vector<int> area;
  Point p1, p2;
  stack<Point> r;
  bool all_visited = true;
  bool m[MAX_SIZE][MAX_SIZE] = {false, };
  bool is_visited[MAX_SIZE][MAX_SIZE] = {false, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> M >> N >> K;
  for (int i = 0; i < K; ++i) {
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    for (int j = p1.y; j < p2.y; ++j) {
      for (int k = p1.x; k < p2.x; ++k) {
        m[j][k] = true;
      }
    }
  }
  // BFS 탐색을 이용하여 사각형이 아닌곳의 넓이를 구한다.
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      // 사각형이 아닌곳을 찾는다.
      if (!is_visited[i][j] && !m[i][j]) {
        is_visited[i][j] = true;
        p1 = {i, j};
        r.push(p1);
        ++length;
        ++count;
      }
      // 사각형의 넓이를 BFS탐색을 이용하여 구한다.
      while (!r.empty()) {
        p1 = r.top();
        all_visited = true;
        for (int i = -1; i <= 1; ++i) {
          for (int j = -1; j<= 1; ++j) {
            if ((i == 0 || j == 0) &&
                0 <= p1.x+i && p1.x+i < M && 0 <= p1.y+j && p1.y+j < N && 
                !m[p1.x+i][p1.y+j] && !is_visited[p1.x+i][p1.y+j]) {
              all_visited = false;
              is_visited[p1.x+i][p1.y+j] = true;
              p1 = {p1.x+i, p1.y+j};
              r.push(p1);
              ++length;
              break;
            }
          }
        }
        if (all_visited) r.pop();
      }
      // 다른 사각형의 넓이를 구하기위해 준비한다.
      if (length) area.push_back(length);
      length = 0;
    }
  }
  // 사각형이 아닌 곳의 개수 , 넓이를 오름차순으로 출력한다.
  cout << count << '\n';
  sort(area.begin(), area.end());
  for (auto p : area) {
    cout << p << ' ';
  }
}
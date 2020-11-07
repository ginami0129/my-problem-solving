#include <iostream>
#include <stack>
#define MAX_SIZE 50
using namespace std;

typedef struct Coordinate {
  int x;
  int y;
} Coordinate;

int main(void) {
  int w, h;
  bool all_visited = true;
  bool map[MAX_SIZE][MAX_SIZE] = {0,};
  bool is_visited[MAX_SIZE][MAX_SIZE] = {false, };
  int count = 0;
  stack<Coordinate> r;
  Coordinate c;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> w >> h;
  while (w && h) {
    // 맵 입력
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> map[i][j];
      }
    }
    // 모든 위치에 대하여
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        //맵에서 섬, 그리고 가보지 않은 곳에서 BFS탐색 수행
        if (map[i][j] && !is_visited[i][j]) {
          is_visited[i][j] = true;
          c = {i, j};
          r.push(c);
          // 한번이라도 실행되면 새로운 섬 발견
          ++count;
        }
        // 그 새로운 섬을 탐색한다.
        while (!r.empty()) {
          c = r.top();
          all_visited = true;
          // 그 점에서 가볼수 있는 모든점 탐색
          for(int k = -1; k <= 1; ++k) {
            for (int l = -1; l <= 1; ++l) {
              // 맵의 크기를 벗어나는가, 방문한적이 없는가, 섬인가 확인
              if (0 <= c.x+k && c.x+k < h && c.y+l >= 0 && c.y+l < w && 
                  !is_visited[c.x+k][c.y+l] && map[c.x+k][c.y+l]) {
                c = {c.x+k, c.y+l};
                r.push(c);
                is_visited[c.x][c.y] = true;
                all_visited = false;
                break;
              }
            }
            if (!all_visited) break;
          }
          if (all_visited) r.pop();
        }
      }
    }
    // 섬의 개수
    cout << count << '\n';
    // 다음 테스트 케이스 실행을 위해 초기화
    for (int i = 0; i < MAX_SIZE; ++i) {
      fill_n(map[i], MAX_SIZE, 0);
      fill_n(is_visited[i], MAX_SIZE, false);
    }
    count = 0;
    // 다음 테스트 케이스 실행
    cin >> w >> h;
  }
}
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, M;
  int L,R,B,T;
  int X, Y;
  vector<vector<int>> map(1001, vector<int>(1001, 0));
  vector<int> button(51, 0);
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> L >> R >> B >> T;
    for (int j = B; j <= T; ++j) {
      for (int k = L; k <= R; ++k) {
        map[j][k] = i+1;
      }
    }
  }
  while (M) {
    cin >> X >> Y;
    ++button[map[Y][X]]; 
    --M;
  }
  for (int i = 1; i < button.size(); ++i) {
    if (button[i] == 0) continue;
    cout << "Button #" << i << ": " << button[i] << '\n';
  }
}


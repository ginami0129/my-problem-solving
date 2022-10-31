#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int N, M;
char mp[MAX][MAX];
long long ans, s1, s2, s3;

int sum(int x1, int y1, int x2, int y2) {
  int sum = 0;
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      sum += mp[i][j] - '0';
    }
  }
  return sum;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> mp[i][j];
    }
  }
  // =
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      s1 = sum(0, 0, i, M - 1);
      s2 = sum(i + 1, 0, j, M - 1);
      s3 = sum(j + 1, 0, N - 1, M - 1);
      ans = max(ans, s1 * s2 * s3);
    }
  }
  // ||
  for (int i = 0; i < M - 2; i++) {
    for (int j = i + 1; j < M - 1; j++) {
      s1 = sum(0, 0, N - 1, i);
      s2 = sum(0, i + 1, N - 1, j);
      s3 = sum(0, j + 1, N - 1, M - 1);
      ans = max(ans, s1 * s2 * s3);
    }
  }
  // ㅓ
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N - 1; j++) {
      s1 = sum(0, i, N - 1, M - 1);
      s2 = sum(0, 0, j, i - 1);
      s3 = sum(j + 1, 0, N - 1, i - 1);
      ans = max(ans, s1 * s2 * s3);
    }
  }
  // ㅏ
  for (int i = 0; i < M - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      s1 = sum(0, 0, N - 1, i);
      s2 = sum(0, i + 1, j, M - 1);
      s3 = sum(j + 1, i + 1, N - 1, M - 1);
      ans = max(ans, s1 * s2 * s3);
    }
  }
  //ㅜ
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M - 1; j++) {
      s1 = sum(0, 0, i, M - 1);
      s2 = sum(i + 1, 0, N - 1, j);
      s3 = sum(i + 1, j + 1, N - 1, M - 1);
      ans = max(ans, s1 * s2 * s3);
    }
  }
  //ㅗ
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M - 1; j++) {
      s1 = sum(i, 0, N - 1, M - 1);
      s2 = sum(0, 0, i - 1, j);
      s3 = sum(0, j + 1, i - 1, M - 1);
      ans = max(ans, s1 * s2 * s3);
    }
  }
  cout << ans << '\n';
}
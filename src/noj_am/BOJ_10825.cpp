#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 100000
using namespace std;

typedef struct Score {
  char name[11];
  int kor, eng, math;
} Score;

bool cmp(Score s1, Score s2) {
  if (s1.kor == s2.kor) {
    if (s1.eng == s2.eng) {
      if (s1.math == s2.math) {
        return strcmp(s1.name, s2.name) < 0;
      } else {
        return s1.math > s2.math;
      }
    } else {
      return s1.eng < s2.eng;
    }
  } else {
    return s1.kor > s2.kor;
  }
}

int main(void) {
  int N;
  Score s[MAX];
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].math;
  }
  sort(s, s + N, cmp);
  for (int i = 0; i < N; ++i) {
    cout << s[i].name << '\n';
  }
}
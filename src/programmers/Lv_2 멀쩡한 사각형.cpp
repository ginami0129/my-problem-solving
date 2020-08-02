using namespace std;
long long gcd(long long a, long long b) {
  int n;
  if (a < b)  a ^= b ^= a ^= b;
  while (b) {
    n = a%b;
    a = b;
    b = n;
  }
  return a;
}

long long solution(int w,int h) {
    long long answer = static_cast<long long>(w) * h;
    long long g = gcd(w, h);
    answer -= (w / g + h / g - 1) * g;
    return answer;
}
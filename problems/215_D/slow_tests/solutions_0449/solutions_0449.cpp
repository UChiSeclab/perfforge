#include <bits/stdc++.h>
using namespace std;
int ToInt(string& s, int len) {
  int r = 0;
  for (int i = 0, max_ = (len); i < max_; ++i) {
    r *= 10;
    r += s[i] - '0';
  }
  return r;
}
int GCD(int a, int b) { return b != 0 ? GCD(b, a % b) : a; }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
long long Pow(long long n, long long e) {
  if (e == 0) return 1;
  if (e == 1)
    return n;
  else if (e & 1) {
    long long t = Pow(n, e / 2);
    return n * t * t;
  } else {
    long long t = Pow(n, e / 2);
    return t * t;
  }
}
int main() {
  long long N, M, t, T, x, cost;
  scanf("%I64d %I64d", &N, &M);
  long long res = 0;
  for (int i = 0, max_ = (N); i < max_; ++i) {
    scanf("%I64d %I64d %I64d %I64d", &t, &T, &x, &cost);
    long long cost1 = cost;
    if (t + M > T) cost1 += M * x;
    long long cost2 = numeric_limits<long long>::max();
    if (T > t) {
      long long count = M / (T - t);
      if (M % (T - t)) ++count;
      cost2 = count * cost;
    }
    res += min(cost1, cost2);
  }
  printf("%I64d\n", res);
  return 0;
}

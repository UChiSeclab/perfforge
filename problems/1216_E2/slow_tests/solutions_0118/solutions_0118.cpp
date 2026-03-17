#include <bits/stdc++.h>
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long MAX = 510000;
const long long INF = 1LL << 61;
const long long MOD = 1000000007LL;
const long long mod = 998244353LL;
using namespace std;
long long ten[20];
long long sum(long long x) {
  if (x == 0) return 0;
  long long D = to_string(x).size();
  long long res = 0;
  for (long long i = 1; i <= D; i++) {
    long long mn = ten[i - 1];
    long long mx = min(ten[i] - 1, x);
    long long n = mx - mn + 1;
    for (long long j = 1; j < i; j++) {
      res += 9 * ten[j - 1] * n * j;
    }
    res += n * (n + 1) / 2 * i;
  }
  return res;
}
long long sum2(long long x) {
  if (x == 0) return 0;
  long long D = to_string(x).size();
  long long res = 0;
  long long mn = ten[D - 1];
  long long mx = min(ten[D] - 1, x);
  long long n = mx - mn + 1;
  for (long long i = 1; i < D; i++) {
    res += 9 * ten[i - 1] * i;
  }
  res += n * D;
  return res;
}
void solve(long long k) {
  long long l = 0;
  long long r = 1LL << 30;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (sum(m) < k) {
      l = m;
    } else {
      r = m;
    }
  }
  long long k2 = k - sum(l);
  l = 0;
  r = 1LL << 30;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (sum2(m) < k2) {
      l = m;
    } else {
      r = m;
    }
  }
  long long k3 = k2 - sum2(l);
  string s = to_string(r);
  cout << s[k3 - 1] << endl;
}
int main() {
  long long Q;
  scanf("%lld", &Q);
  ten[0] = 1;
  for (long long i = 1; i < 20; i++) {
    ten[i] = ten[i - 1] * 10;
  }
  for (long long loop = 0; loop < Q; loop++) {
    long long k;
    scanf("%lld", &k);
    solve(k);
  }
  return 0;
}

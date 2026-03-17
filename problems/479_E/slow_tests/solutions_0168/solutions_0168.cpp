#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
inline void umin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void umax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T, typename W>
inline void Int(T &x, W &y) {
  Int(x), Int(y);
}
template <typename T, typename W, typename Q>
inline void Int(T &x, W &y, Q &z) {
  Int(x, y), Int(z);
}
const int N = 5e3 + 7;
const int mod = (int)1e9 + 7;
int dp[N], tdp[N];
int l = 1, r, a, b, k;
int Ways(int x) { return dp[x]; }
int Ways(int l, int r) {
  if (l > r) return 0;
  int ret = Ways(r) - Ways(l - 1);
  return (ret % mod + mod) % mod;
}
int solve() {
  Int(r, a);
  Int(b, k);
  if (a < b) r = b - 1;
  if (a > b) l = b + 1;
  for (int i = l; i <= r; ++i) dp[i] = 1;
  for (int j = 1; j <= k; ++j) {
    for (int i = l; i <= r; ++i) {
      tdp[i] = 0;
      dp[i] += dp[i - 1];
      dp[i] %= mod;
    }
    for (int i = l; i <= r; ++i) {
      int mxDist = abs(b - i) - 1;
      tdp[i] += Ways(max(l, i - mxDist), i - 1);
      tdp[i] += Ways(i + 1, min(r, i + mxDist));
      if (tdp[i] > mod) tdp[i] -= mod;
    }
    for (int i = l; i <= r; ++i) dp[i] = tdp[i];
  }
  printf("%d\n", dp[a]);
  return 0;
}
int main() {
  int tests = 1, CaseNo = 0;
  while (tests--) {
    solve();
  }
  return 0;
}

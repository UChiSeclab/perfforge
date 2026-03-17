#include <bits/stdc++.h>
using namespace std;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 2147483647;
const long long linf = 1e18 + 5;
const double PI = acos(-1.0);
const long double eps = 1e-12;
const int MAXN = 5e5 + 2;
const int N = 1e6;
const int fix = 1e5;
long long M = 1e9 + 7;
const int K = 30;
long long n, k;
int count(int x) {
  int ans = 0;
  for (register int i = (1), I = (n) + 1; i < I; ++i) {
    int t = i;
    bool flag = 0;
    while (t) {
      if (t == x || (x % 2 == 0 && t - 1 == x)) flag = 1;
      t = t >> 1;
    }
    ans += flag;
  }
  return ans;
}
int d[65], t[65];
long long dfs(int len, bool limit, bool lead, int match) {
  if (!len) return match == 0;
  if (!match && !limit && !lead) return (1LL << len);
  int up = limit ? d[len] : 1;
  long long ans = 0;
  if (lead) ans += dfs(len - 1, limit && up == 0, 1, match);
  if (match) {
    if (up >= t[match])
      ans += dfs(len - 1, limit && up == t[match], 0, match - 1);
  } else
    for (register int i = (0), I = (up) + 1; i < I; ++i)
      ans += dfs(len - 1, limit && up == i, lead && i == 0, 0);
  return ans;
}
long long solve(long long x) {
  if (x > n) return 0;
  memset(t, 0, sizeof(t));
  while (x) t[++t[0]] = x & 1, x = x >> 1;
  return dfs(d[0], 1, 1, t[0]);
}
int work() {
  scanf("%lld%lld", &n, &k);
  long long x = n;
  while (x) d[++d[0]] = x & 1, x = x >> 1;
  long long ans = 1;
  {
    long long l = 1, r = n / 2;
    while (l <= r) {
      const long long mid = (l + r) >> 1;
      if (solve(mid * 2) + solve(mid * 2 + 1) >= k)
        ans = max(ans, mid * 2), l = mid + 1;
      else
        r = mid - 1;
    }
  }
  {
    long long l = 1, r = (n + 1) / 2;
    while (l <= r) {
      const long long mid = (l + r) >> 1;
      if (solve(mid * 2 - 1) >= k)
        ans = max(ans, mid * 2 - 1), l = mid + 1;
      else
        r = mid - 1;
    }
  }
  return printf("%lld\n", ans);
}
int main() {
  work();
  return 0;
}

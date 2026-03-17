#include <bits/stdc++.h>
const int MAXN = 1e5 + 10;
int n, m;
long long a[MAXN], b[MAXN];
int main() {
  scanf("%d%*d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += 1e9;
  scanf("%d%*d", &m);
  for (int i = 1; i <= m; i++) scanf("%lld", b + i), b[i] += 1e9;
  int ans = 0;
  for (long long x = 2; x <= 1e10; x <<= 1) {
    std::map<long long, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
      mp1[a[i] & (x - 1)]++;
    }
    for (int i = 1; i <= m; i++) {
      mp2[b[i] & (x - 1)]++;
    }
    for (auto i : mp1) {
      ans = std::max(ans, i.second + (mp2[i.first ^ (x >> 1)]));
    }
    for (auto i : mp2) {
      ans = std::max(ans, i.second + (mp1[i.first ^ (x >> 1)]));
    }
  }
  {
    std::map<long long, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
      mp1[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
      mp2[b[i]]++;
    }
    for (auto i : mp1) {
      ans = std::max(ans, i.second + (mp2[i.first]));
    }
    for (auto i : mp2) {
      ans = std::max(ans, i.second + (mp1[i.first]));
    }
  }
  printf("%d\n", ans);
}

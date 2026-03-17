#include <bits/stdc++.h>
using namespace std;
map<pair<int, long long>, int> dp;
int n, s[1000010];
int calc(pair<int, long long> u) {
  if (dp.count(u) > 0) return dp[u];
  if (u.first == 0) return dp[u] = 0;
  vector<bool> g(61);
  for (int i = 1; i <= u.first; ++i) {
    if (u.second & (1ll << i)) continue;
    g[calc({u.first - i, u.second | (1ll << i)})] = true;
  }
  int x = 0;
  while (g[x]) ++x;
  return dp[u] = x;
}
int main() {
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
    ans = ans ^ calc({s[i], 0});
  }
  printf("%s\n", ans != 0 ? "NO" : "YES");
  return 0;
}

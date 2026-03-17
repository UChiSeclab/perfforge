#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
bool vis[10], good[10];
int n, k;
long long ans, mod = 1000000007;
vector<int> v;
bool dfs(int u) {
  if (vis[u]) return good[u];
  vis[u] = 1;
  if (u == 1) return good[u] = 1;
  return good[u] = dfs(v[u]);
}
bool check() {
  memset(good, 0, sizeof good);
  memset(vis, 0, sizeof vis);
  bool ret = 1;
  for (int i = 1; i <= k; i++) ret &= dfs(i);
  return ret;
}
void bt(int i) {
  if (i == k + 1) {
    ans += check();
    return;
  }
  for (int num = 1; num <= k; num++) {
    v.push_back(num);
    bt(i + 1);
    v.pop_back();
  }
}
int main() {
  scanf("%d%d", &n, &k);
  v.push_back(0);
  bt(1);
  for (int i = k + 1; i <= n; i++) ans = (ans * (n - k)) % mod;
  printf("%lld\n", ans);
}

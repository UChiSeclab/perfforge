#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
int setb(int n, int pos) { return n = n | (1 << pos); }
int resb(int n, int pos) { return n = n & ~(1 << pos); }
bool checkb(int n, int pos) { return (bool)(n & (1 << pos)); }
long long bigmod(long long b, long long p) {
  if (p == 0) return 1;
  long long ret = bigmod(b, p / 2);
  ret = (ret * ret) % 998244353;
  if (p & 1) ret = (ret * b) % 998244353;
  return ret;
}
int n;
vector<int> g[3002];
int d[3002][3002], save[3002][3002];
long long dp[3002][3002];
bool visit[3002][3002];
void go(int root, int u, int p, int cur = 0) {
  d[root][u] = cur;
  save[root][u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == p) continue;
    go(root, v, u, cur + 1);
    save[root][u] += save[root][v];
  }
}
void prework() {
  for (int u = 1; u <= n; u++) go(u, u, u);
}
long long get_cost(int x, int y) { return (long long)save[x][y] * save[y][x]; }
long long F(int x, int y) {
  if (visit[x][y]) return dp[x][y];
  long long ret = 0;
  for (int i = 0; i < g[x].size(); i++) {
    int nxt = g[x][i];
    if (d[y][nxt] > d[y][x]) ret = max(ret, get_cost(y, nxt) + F(nxt, y));
  }
  for (int i = 0; i < g[y].size(); i++) {
    int nxt = g[y][i];
    if (d[x][nxt] > d[x][y]) ret = max(ret, get_cost(x, nxt) + F(x, nxt));
  }
  visit[x][y] = true;
  return dp[x][y] = ret;
}
long long solve() {
  prework();
  long long ret = 0;
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      ret = max(ret, get_cost(u, v) + F(u, v));
    }
  }
  return ret;
}
int main() {
  int i, x, y;
  scanf("%d", &n);
  for (i = 1; i <= n - 1; i++) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  long long ret = solve();
  printf("%lld\n", ret);
  return 0;
}

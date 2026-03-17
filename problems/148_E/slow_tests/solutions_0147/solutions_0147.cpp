#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101], fp[101][10001];
int vis[101][101][101];
int a[101], m, cs = 0;
vector<int> adj[105];
int prec(int rem, int i, int j) {
  if (rem == 0) return 0;
  if (i > j) return 0;
  if (vis[rem][i][j] == cs) return dp[rem][i][j];
  vis[rem][i][j] = cs;
  int ret = 0;
  ret = max(a[i] + prec(rem - 1, i + 1, j), a[j] + prec(rem - 1, i, j - 1));
  return dp[rem][i][j] = ret;
}
int call(int pos, int k) {
  if (k == 0) return 0;
  if (pos == 0) return 0;
  if (fp[pos][k] != -1) return fp[pos][k];
  int ret = 0;
  int sz = adj[pos].front();
  ret = max(ret, call(pos - 1, k));
  for (int i = 1; i <= sz; i++) {
    if (i <= k) {
      int tmp = adj[pos][i] + call(pos - 1, k - i);
      ret = max(ret, tmp);
    } else
      break;
  }
  return fp[pos][k] = ret;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    for (int j = 1; j <= m; j++) scanf("%d", &a[j]);
    ++cs;
    int foo = prec(m, 1, m);
    adj[i].push_back(m);
    for (int j = 1; j <= m; j++) adj[i].push_back(prec(j, 1, m));
  }
  memset(fp, -1, sizeof(fp));
  int ret = call(n, k);
  printf("%d\n", ret);
  return 0;
}

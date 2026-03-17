#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000 * 1000 * 1000 + 7;
void dfs(int ind, vector<vector<int> > &g, vector<int> &used) {
  used[ind] = 1;
  for (auto i : g[ind]) {
    if (!used[i]) dfs(i, g, used);
  }
}
void dfs2(int ind, vector<vector<int> > &g, vector<int> &used, int t) {
  used[ind] = t;
  for (auto i : g[ind]) {
    if (!used[i]) dfs2(i, g, used, t);
  }
}
int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  s--;
  vector<vector<int> > g(n);
  vector<int> p(n, 0);
  vector<int> used(n, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[--a].push_back(--b);
    p[b]++;
  }
  dfs(s, g, used);
  vector<int> unin;
  for (int i = 0; i < n; i++) {
    if (!used[i]) unin.push_back(i);
  }
  sort(unin.begin(), unin.end(), [&](int l, int r) {
    if (p[l] == p[r]) return g[l].size() > g[r].size();
    return (int)p[l] < (int)p[r];
  });
  int ans = INT_MAX;
  int start = 0;
  int kk = (int)unin.size();
  while (start < kk) {
    int type = 1;
    for (int i = start; i < start + kk; i++) {
      if (!used[unin[i % kk]]) {
        dfs2(unin[i % kk], g, used, type);
        type++;
      }
    }
    ans = min(ans, type);
    for (auto i : unin) used[i] = 0;
    start++;
  }
  if (ans == INT_MAX) ans = 1;
  printf("%d\n", ans - 1);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5100;
const long long mod = 1e9 + 7;
int n, m;
int dis(int x, int y) {
  if (y < x)
    return n - x + y;
  else
    return y - x;
}
vector<int> f[N];
int now;
int cmp(int a, int b) { return dis(now, a) >= dis(now, b); }
int head[N];
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int base, cnt;
int pp[N], cp[N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    f[x].push_back(y);
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < f[i].size(); j++) pp[f[i][j]]++;
    int now = i;
    f[i].clear();
    for (int j = 1; j <= n; j++) {
      while (pp[now]) f[i].push_back(now), pp[now]--;
      now = now + 1;
      if (now > n) now = 1;
    }
    reverse(f[i].begin(), f[i].end());
    mx = max(mx, (int)f[i].size());
  }
  mx = max(1, mx - 1);
  base = n * (mx - 1);
  for (int i = 1; i <= n; i++) {
    if (f[i].size() < mx)
      f[i].clear();
    else {
      int x = f[i][f[i].size() - 1];
      int ff = 0, y;
      if (f[i].size() == mx + 1) ff = 1, y = f[i][f[i].size() - 2];
      f[i].clear();
      if (ff) cnt++, f[i].push_back(y);
      f[i].push_back(x);
      cnt++;
    }
  }
  for (int i = 1; i <= n; i++) {
    now = i;
    for (int j = 1; j <= n; j++) pp[j] = cp[j] = 0;
    int ans = base;
    int tmp = cnt;
    while (tmp) {
      if (cp[now] < f[now].size()) pp[f[now][cp[now]]]++;
      cp[now]++;
      if (pp[now]) tmp -= pp[now], pp[now] = 0;
      now = now + 1;
      if (now > n) now = 1;
      ans++;
    }
    printf("%d", ans - 1);
    if (i != n)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}

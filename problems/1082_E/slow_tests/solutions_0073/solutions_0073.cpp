#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 1e7 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int INF = 2e9;
const int seed = 131;
int n, c, a[N], sum[N], pre[N];
vector<int> G[N];
int main() {
  int mx = 0;
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + (a[i] == c);
    mx = max(mx, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    G[a[i]].push_back(-(sum[i - 1] - sum[pre[a[i]]]));
    G[a[i]].push_back(1);
    pre[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= mx; ++i) {
    if (i == c) continue;
    int res = 0, sum = 0;
    for (auto &x : G[i]) {
      sum = max(0, sum + x);
      res = max(res, sum);
    }
    ans = max(ans, res);
  }
  printf("%d\n", ans + sum[n]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300010;
struct {
  ll v;
  ll c1, c2;
} dp[N];
int num[4], n, m;
ll a[4][N], s[4][N];
int main() {
  scanf("%d%d", &n, &m);
  memset(num, 0, sizeof num);
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    ll w, c;
    scanf("%I64d%I64d", &w, &c);
    a[w][++num[w]] = c;
  }
  for (int i = 1; i <= 3; ++i) {
    s[i][0] = 0;
    sort(a[i] + 1, a[i] + num[i] + 1,
         [](const int &a, const int &b) { return a > b; });
    for (int j = 1; j <= num[i]; ++j) s[i][j] = s[i][j - 1] + a[i][j];
  }
  dp[0].v = dp[0].c1 = dp[0].c2 = 0;
  for (int i = 1; i <= m; ++i) {
    if (dp[i - 1].v + a[1][dp[i - 1].c1 + 1] > dp[i].v) {
      dp[i].v = dp[i - 1].v + a[1][dp[i - 1].c1 + 1];
      dp[i].c1 = dp[i - 1].c1 + 1;
      dp[i].c2 = dp[i - 1].c2;
    }
    if (i > 1 && dp[i - 2].v + a[2][dp[i - 2].c2 + 1] > dp[i].v) {
      dp[i].v = dp[i - 2].v + a[2][dp[i - 2].c2 + 1];
      dp[i].c1 = dp[i - 2].c1;
      dp[i].c2 = dp[i - 2].c2 + 1;
    }
  }
  ll ans = 0;
  for (int i = 0; i <= num[3]; ++i) {
    if (m >= i * 3) ans = max(ans, s[3][i] + dp[m - i * 3].v);
  }
  printf("%I64d\n", ans);
  return 0;
}

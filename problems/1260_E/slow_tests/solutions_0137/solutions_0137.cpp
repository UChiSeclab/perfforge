#include <bits/stdc++.h>
using namespace std;
int n, hold;
int a[(1 << 19)];
long long dp[19][(1 << 19)];
int lg() {
  int cnt = 0;
  int t = n;
  while (t) {
    t >>= 1;
    cnt++;
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == -1) {
      hold = i;
      continue;
    }
    if (!hold)
      a[i] = 0;
    else
      a[i - 1] = a[i];
  }
  n--;
  int req = lg();
  for (int i = 1; i <= req; i++)
    fill(dp[i], dp[i] + (1 << 19), 100000000000000000);
  for (int cnt = 1; cnt <= req; cnt++) {
    int tot = (1 << (cnt - 1)) - 1;
    int add = (1 << (cnt - 1));
    for (int i = 1; i <= n; i++) {
      if (tot + add <= i) {
        dp[cnt][i] = min(dp[cnt][i], dp[cnt - 1][i - 1] + a[i]);
      }
      dp[cnt][i] = min(dp[cnt][i], dp[cnt][i - 1]);
    }
  }
  printf("%lld", dp[req][n]);
}

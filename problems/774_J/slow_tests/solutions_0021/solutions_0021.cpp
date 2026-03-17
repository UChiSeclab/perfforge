#include <bits/stdc++.h>
using namespace std;
int dp[110][110][110];
int n, m;
char a[110];
int func(int here, int ch, int ch1) {
  if (here == n) {
    if (ch1 == m)
      return 1;
    else
      return 0;
  }
  int &ret = dp[here][ch][ch1];
  if (ret != -1) return ret;
  ret = 0;
  if (a[here] == 'N')
    ret = func(here + 1, ch + 1, max(ch + 1, ch1));
  else if (a[here] == 'Y')
    ret = func(here + 1, 0, ch1);
  else {
    ret = max(func(here + 1, ch + 1, max(ch + 1, ch1)), func(here + 1, 0, ch1));
  }
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf(" %1c", &a[i]);
  if (func(0, 0, 0))
    puts("YES");
  else
    puts("NO");
}

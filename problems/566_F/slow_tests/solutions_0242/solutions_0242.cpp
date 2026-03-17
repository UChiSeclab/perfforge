#include <bits/stdc++.h>
using namespace std;
int dp[1111111];
template <typename __ll>
inline void read(__ll &m) {
  __ll x = 0, f = 1;
  char ch = getchar();
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  m = x * f;
}
int main() {
  int i, n, x, ma = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    read(x);
    ma = max(ma, dp[x] + 1);
    for (int j = 2 * x; j <= 1000000; j += x) dp[j] = max(dp[j], dp[x] + 1);
    dp[x]++;
  }
  printf("%d", ma);
}

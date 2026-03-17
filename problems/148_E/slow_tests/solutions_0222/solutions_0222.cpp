#include <bits/stdc++.h>
using namespace std;
void scan(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
const int M = 101;
int dp[M][M], dp1[M][10001], s[M], a[M][M], mx[101][101], nn, mm;
int solve(int l, int r, int d) {
  if (d > mm) return 0;
  if (l > r) return 0;
  if (l == r) {
    return a[nn][l];
  }
  int &ret = dp[l][r];
  if (ret != -1) return ret;
  ret = 0;
  ret +=
      max(solve(l + 1, r, d + 1) + a[nn][l], solve(l, r - 1, d + 1) + a[nn][r]);
  return ret;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scan(s[i]);
    for (int j = 0; j < s[i]; j++) {
      scan(a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    nn = i;
    for (int j = 1; j <= s[i]; j++) {
      memset(dp, -1, sizeof dp);
      mm = j;
      mx[i][j] = solve(0, s[i] - 1, 1);
    }
  }
  memset(dp, -1, sizeof dp);
  dp1[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i]; j++) {
      for (int k = 0; k <= m; k++) {
        if (dp1[i - 1][k] != -1) {
          if (k + j + 1 <= m)
            dp1[i][k + j + 1] =
                max(dp1[i][k + j + 1], dp1[i - 1][k] + mx[i][j + 1]);
          dp1[i][k] = max(dp1[i - 1][k], dp1[i][k]);
        }
      }
    }
  }
  printf("%d\n", dp1[n][m]);
  return 0;
}

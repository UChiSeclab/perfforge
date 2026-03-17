#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e15;
const int mod = 998244353;
const int MXN = (int)1e2 + 7;
char s[MXN];
long long a[MXN];
int b[MXN];
long long dp[MXN][MXN][MXN][2];
long long val[MXN << 1];
int main() {
  int n;
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) a[i] = max(a[i], a[j] + a[i - j]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = -INFF;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int v = s[i] - '0';
    dp[i][i][0][v] = a[1];
    dp[i][i][1][v] = 0;
    dp[i][i][0][v ^ 1] = a[1];
  }
  for (int len = 2; len <= n; len++) {
    for (int ll = 1; ll + len - 1 <= n; ll++) {
      int rr = ll + len - 1;
      for (int p = 0; p < 2; p++) {
        for (int num = 0; num <= n; num++) {
          if (s[ll] - '0' == p && num) {
            long long v = dp[ll][ll][1][p] + dp[ll + 1][rr][num - 1][p];
            dp[ll][rr][num][p] = max(dp[ll][rr][num][p], v);
          }
          for (int mid = ll; mid < rr; mid++) {
            long long v = dp[ll][mid][num][p] + dp[mid + 1][rr][0][p];
            dp[ll][rr][num][p] = max(dp[ll][rr][num][p], v);
            v = dp[ll][mid][0][p] + dp[mid + 1][rr][num][p];
            dp[ll][rr][num][p] = max(dp[ll][rr][num][p], v);
          }
          for (int j = num; j >= 0; j--) {
            dp[ll][rr][j][p] =
                max(dp[ll][rr][j][p], dp[ll][rr][num][p] + a[num - j]);
          }
        }
        dp[ll][rr][0][p ^ 1] = max(dp[ll][rr][0][p ^ 1], dp[ll][rr][0][p]);
      }
    }
  }
  printf("%lld\n", dp[1][n][0][1]);
  return 0;
}

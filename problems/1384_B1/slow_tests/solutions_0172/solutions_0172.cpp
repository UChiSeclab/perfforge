#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const int N = 1e2 + 10;
const long long mod = 1e9 + 7;
const double PI = 3.14;
int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int random(int n) { return (long long)rand() * rand() % n; }
int a[N];
int dp[N][100005];
int sum[100005];
void solve() {
  int n = read(), k = read(), l = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  memset(dp, 0, sizeof dp);
  memset(sum, 0, sizeof sum);
  int cnt = 0;
  for (int i = 1; i < 100005; i++) {
    int x;
    if (cnt % (2 * k) < k)
      x = 1;
    else
      x = -1;
    sum[i] = sum[i - 1] + x;
    cnt++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < 100005; j++) {
      if (i == 1) {
        if (a[i] + sum[j] <= l) {
          dp[i][j] = 1;
        }
      } else {
        if (dp[i - 1][j - 1] && a[i] + sum[j] <= l) {
          dp[i][j] = 1;
        }
        if (dp[i][j - 1] && a[i] + sum[j] <= l) {
          dp[i][j] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int flag = 1;
    for (int j = 1; j < 100005; j++) {
      if (dp[i][j] == 1) flag = 0;
    }
    if (flag) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
int main() {
  srand((unsigned)time(0));
  int t = read();
  while (t--) {
    solve();
  }
  return 0;
}

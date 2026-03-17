#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma warning(disable : 4996)
using namespace std;
double dp[1003][1003];
int vis[1003][1003];
int m;
double DP(int total, int n, int k) {
  if (n == 0) return k;
  double &ret = dp[n][k];
  if (vis[n][k]) return ret;
  vis[n][k] = 1;
  ret = 0;
  if (k < m) ret += (1. * m - k) / total * DP(total - 1, n - 1, k + 1);
  if (total > m - k)
    ret += (1. * total - (m - k)) / total * DP(total - 1, n - 1, k);
  return ret;
}
int main() {
  int n;
  scanf("%d %d", &n, &m);
  if (n == 1) {
    printf("%.10lf\n", 1.0);
    return 0;
  }
  double ans = (DP(n * m - 1, n - 1, 1)) / n;
  printf("%.10lf\n", ans);
  return 0;
}

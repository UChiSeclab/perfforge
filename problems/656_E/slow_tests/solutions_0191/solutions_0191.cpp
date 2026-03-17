#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long inf = 1e15;
int n;
long long a[12][12];
long long dp[12][12][12];
long long take(int i, int j, int k, int p) {
  return p == n ? inf
                : min(dp[i][p][k - 1] + dp[p][j][k - 1], take(i, j, k, p + 1));
}
long long calc(int h, int k) {
  int i = h / n, j = h % n;
  return h == n * n ? 0 : ((dp[i][j][k] = take(i, j, k, 0)), calc(h + 1, k));
}
int floyd(int k) { return k == n + 1 ? 0 : (calc(0, k), floyd(k + 1)); }
int input(int h) {
  return h == n * n ? 0 : ((cin >> a[h / n][h % n]), input(h + 1));
}
int init(int h) {
  return h == n * n ? 0
                    : ((dp[h / n][h % n][0] = a[h / n][h % n]), init(h + 1));
}
long long maxim(int h) {
  int i = h / n, j = h % n;
  return h == n * n ? -1 : max(dp[i][j][n], maxim(h + 1));
}
int main() {
  cin >> n;
  input(0);
  init(0);
  floyd(1);
  cout << maxim(0);
  return 0;
}

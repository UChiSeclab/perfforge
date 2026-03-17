#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dp1[101][101][101];
long long dp2[101][10001];
long long ans1[101][101];
long long arr[101][101];
long long sz[101];
long long ind = -1;
long long f1(long long i, long long j, long long left) {
  if (left == 0) return dp1[i][j][left] = 0;
  if (i == j) return arr[ind][i];
  if (dp1[i][j][left] != -1) return dp1[i][j][left];
  dp1[i][j][left] = max(arr[ind][i] + f1(i + 1, j, left - 1),
                        arr[ind][j] + f1(i, j - 1, left - 1));
  return dp1[i][j][left];
}
long long f2(long long i, long long left) {
  if (i > n) {
    if (left == 0) return 0;
    return -1e18;
  }
  if (dp2[i][left] != -1) return dp2[i][left];
  long long ans = 0;
  for (long long j = 0; j <= min(left, sz[i]); j++)
    ans = max(ans, f2(i + 1, left - j) + ans1[i][j]);
  return dp2[i][left] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> sz[i];
    for (long long j = 1; j <= sz[i]; j++) cin >> arr[i][j];
  }
  memset(ans1, 0, sizeof(ans1));
  for (long long i = 1; i <= n; i++) {
    memset(dp1, -1, sizeof(dp1));
    for (long long j = 1; j <= sz[i]; j++) {
      ind = i;
      ans1[ind][j] = f1(1, sz[i], j);
    }
  }
  memset(dp2, -1, sizeof(dp2));
  cout << f2(1, m);
}

#include <bits/stdc++.h>
using namespace std;
string a, b;
int n, k;
const int maxn = 205;
int dp[maxn][maxn][maxn];
int solve(int i, int k, int cnt0) {
  if (dp[i][k][cnt0] != -1) return dp[i][k][cnt0];
  if (i == n) return dp[i][k][cnt0] = 0;
  if (k > 0) {
    return dp[i][k][cnt0] = max(
               max(cnt0 * (b[0] == b[1]) + solve(i + 1, k - 1, cnt0 + 1),
                   cnt0 + solve(i + 1, k - 1, cnt0)),
               cnt0 * (a[i] == b[1]) + solve(i + 1, k, cnt0 + (a[i] == b[0])));
  } else {
    return dp[i][k][cnt0] =
               cnt0 * (a[i] == b[1]) + solve(i + 1, k, cnt0 + (a[i] == b[0]));
  }
}
int main() {
  cin >> n >> k;
  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  cout << solve(0, k, 0) << endl;
}

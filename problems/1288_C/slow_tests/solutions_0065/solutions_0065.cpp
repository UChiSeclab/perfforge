#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 11;
const int MOD = 1e9 + 7;
int n, m;
int dp[M][N][N];
int solve(int idx, int a, int b) {
  if (idx >= m) return 1;
  int& r = dp[idx][a][b];
  if (r != -1) return r;
  r = solve(idx + 1, a, b);
  if (a < b) {
    r = (r + solve(idx, a + 1, b)) % MOD;
    r = (r + solve(idx, a, b - 1)) % MOD;
  }
  if (a + 1 < b) r = ((r - solve(idx, a + 1, b - 1)) % MOD + MOD) % MOD;
  return r;
}
int main() {
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 1, n) << '\n';
  return 0;
}

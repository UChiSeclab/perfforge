#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
long long t[11];
long long dp[N][11];
long long mx[N];
long long solve(long long n) {
  if (n == 0) return 0;
  if (n < 0) return -int(1e9);
  if (mx[n] == -1)
    for (int i = 1; i < 10; i++) {
      dp[n][i] = max(dp[n][i], 1 + solve(n - t[i]));
      mx[n] = max(mx[n], dp[n][i]);
    }
  return mx[n];
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  memset(mx, -1, sizeof(mx));
  long long n;
  cin >> n;
  long long mn = int(1e9);
  for (int i = 1; i < 10; i++) {
    cin >> t[i];
    mn = min(mn, t[i]);
  }
  if (n < mn) {
    cout << -1;
    return 0;
  }
  solve(n);
  long long i = n;
  while (i) {
    int ind = -1;
    for (int j = 1; j <= 9; j++)
      if (dp[i][j] == mx[i] && mx[i] > -1) ind = j;
    if (ind == -1) return 0;
    cout << ind;
    i = i - t[ind];
  }
}

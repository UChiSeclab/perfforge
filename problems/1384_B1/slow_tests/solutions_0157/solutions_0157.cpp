#include <bits/stdc++.h>
using namespace std;
int n, k, l;
const int MAX1 = 100;
const int MAX2 = 2000;
int dp[MAX1 + 1][MAX2 + 1];
int solve(int d[], int p[], int pos, int t) {
  if (pos == n) return 1;
  int curr = d[pos] + p[t % (2 * k)];
  if (curr > l) return 0;
  if (dp[pos][t] != -1) return dp[pos][t];
  int good = 0;
  for (int i = 0; i < 2 * k; i++) {
    curr = d[pos] + p[(t + i) % (2 * k)];
    if (curr > l) break;
    good = max(good, solve(d, p, pos + 1, t + i + 1));
  }
  return dp[pos][t] = good;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k >> l;
    int d[n];
    int p[2 * k];
    for (int i = 0; i < n; i++) cin >> d[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= k; i++) p[i] = i;
    for (int i = k + 1; i < 2 * k; i++) p[i] = p[i - 1] - 1;
    int good = 0;
    for (int i = 0; i < 2 * k; i++) {
      good = max(good, solve(d, p, 0, i + 1));
    }
    if (good)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

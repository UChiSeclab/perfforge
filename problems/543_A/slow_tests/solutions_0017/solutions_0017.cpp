#include <bits/stdc++.h>
using namespace std;
int n, m, b, mod;
int flip = 0;
vector<vector<vector<int> > > DP;
vector<int> V;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> b >> mod;
  V = vector<int>(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  DP = vector<vector<vector<int> > >(
      2, vector<vector<int> >(m + 1, vector<int>(b + 1, 0)));
  DP[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    flip = !flip;
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= b; ++k) {
        DP[flip][j][k] = DP[!flip][j][k];
        if (j > 0 && k >= V[i]) DP[flip][j][k] += DP[flip][j - 1][k - V[i]];
        DP[flip][j][k] %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= b; ++i) {
    ans = (ans + DP[flip][m][i]) % mod;
  }
  cout << ans << "\n";
  return 0;
}

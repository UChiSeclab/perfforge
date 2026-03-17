#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  int c[2] = {};
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] > 0) ++c[v[i] % 2];
  }
  c[1] = (n + 1) / 2 - c[1];
  c[0] = n / 2 - c[0];
  vector<vector<vector<int> > > dp(
      c[0] + 1, vector<vector<int> >(c[1] + 1, vector<int>(2, mod)));
  dp[c[0]][c[1]][0] = 0;
  dp[c[0]][c[1]][1] = 0;
  for (int i = 1; i <= n; i++) {
    vector<vector<vector<int> > > new_dp(
        c[0] + 1, vector<vector<int> >(c[1] + 1, vector<int>(2, mod)));
    for (int even = 0; even <= c[0]; even++) {
      for (int odd = 0; odd <= c[1]; odd++) {
        for (int la = 0; la < 2; la++) {
          if (v[i] > 0) {
            new_dp[even][odd][v[i] % 2] =
                min(new_dp[even][odd][v[i] % 2],
                    dp[even][odd][la] + ((v[i] % 2) != la));
            continue;
          }
          if (even > 0)
            new_dp[even - 1][odd][0] =
                min(new_dp[even - 1][odd][0], dp[even][odd][la] + (la != 0));
          if (odd > 0)
            new_dp[even][odd - 1][1] =
                min(new_dp[even][odd - 1][1], dp[even][odd][la] + (la != 1));
        }
      }
    }
    dp = new_dp;
  }
  cout << min(dp[0][0][0], dp[0][0][1]) << "\n";
  return 0;
}

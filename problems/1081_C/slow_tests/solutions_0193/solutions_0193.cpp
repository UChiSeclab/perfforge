#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int n, m, k;
long long find(int i, int f) {
  if (i == 1) {
    if (f == 0)
      return m;
    else
      return 0;
  }
  if (dp[i][f] != -1) return dp[i][f];
  return dp[i][f] = (find(i - 1, f) % 998244353 +
                     (find(i + -1, f - 1) % 998244353 * (m - 1) % 998244353) %
                         998244353) %
                    998244353;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  memset(dp, -1, sizeof(dp));
  cout << find(n, k) << "\n";
  return 0;
}

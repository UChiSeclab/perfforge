#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target(sse, sse2, sse3, popcnt, tune = native)
using namespace std;
const long long inf = 1e9 + 47;
long long n;
vector<long long> val;
vector<vector<vector<vector<long long> > > > dp;
void read() {
  cin >> n;
  val.resize(n);
  vector<long long> odd(2, 0);
  odd[0] = n / 2;
  odd[1] = n - odd[0];
  for (long long i = 0; i < n; ++i) {
    cin >> val[i];
    if (val[i] == 0)
      val[i] = -1;
    else {
      val[i] %= 2;
      odd[val[i]]--;
    }
  }
  long long free = 0;
  dp.resize(n + 1, vector<vector<vector<long long> > >(
                       2, vector<vector<long long> >(
                              n + 1, vector<long long>(n + 1, inf))));
  if (val[0] == -1) {
    dp[0][0][1][0] = 0;
    dp[0][1][0][1] = 0;
  } else {
    if (val[0] == 0)
      dp[0][0][1][0] = 0;
    else
      dp[0][1][0][1] = 0;
  }
  for (long long i = 1; i < n; ++i) {
    if (val[i] == -1) {
      for (long long zero = 0; zero < n; ++zero) {
        for (long long one = 0; one < n; ++one) {
          if (zero != 0) {
            dp[i][0][zero][one] =
                min(dp[i][0][zero][one], dp[i - 1][0][zero - 1][one]);
          }
          if (zero != 0) {
            dp[i][0][zero][one] =
                min(dp[i][0][zero][one], dp[i - 1][1][zero - 1][one] + 1);
          }
        }
      }
      for (long long zero = 0; zero < n; ++zero) {
        for (long long one = 0; one < n; ++one) {
          if (one != 0) {
            dp[i][1][zero][one] =
                min(dp[i][1][zero][one], dp[i - 1][0][zero][one - 1] + 1);
          }
          if (one != 0) {
            dp[i][1][zero][one] =
                min(dp[i][1][zero][one], dp[i - 1][1][zero][one - 1]);
          }
        }
      }
    } else {
      long long a = 0, b = 0;
      if (val[i] == 0)
        a++;
      else
        b++;
      for (long long zero = 0; zero < n; ++zero) {
        for (long long one = 0; one < n; ++one) {
          if (zero - a >= 0 && one - b >= 0) {
            long long add = val[i];
            dp[i][val[i]][zero][one] =
                min(dp[i][val[i]][zero][one],
                    dp[i - 1][0][zero - a][one - b] + add);
          }
          if (zero - a >= 0 && one - b >= 0) {
            long long add = val[i] ^ 1;
            dp[i][val[i]][zero][one] =
                min(dp[i][val[i]][zero][one],
                    dp[i - 1][1][zero - a][one - b] + add);
          }
        }
      }
    }
  }
  long long a = n / 2, b = n - a;
  cout << min(dp[n - 1][0][a][b], dp[n - 1][1][a][b]) << endl;
}
void solve() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    read();
    solve();
  }
}

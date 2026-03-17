#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int factors[maxn];
long long mod = 998244353;
string p1, p2;
long long dp[105][905];
long long solve(long long S, long long s, long long n, string num) {
  if (s == n) {
    if (S == 0) {
      p1 = num;
      return dp[s][S] = 1;
    }
    return dp[s][S] = 0;
  };
  if (dp[s][S] != -1) return dp[s][S];
  for (int i = 0; i <= 9; i++) {
    if (S - i >= 0)
      if (solve(S - i, s + 1, n, num + to_string(i)) == 1) return dp[s][S] = 1;
  }
  return dp[s][S] = 0;
}
long long solve2(long long S, long long s, long long n, string num) {
  if (s == n) {
    if (S == 0) {
      p2 = num;
      return dp[s][S] = 1;
    }
    return dp[s][S] = 0;
  };
  if (dp[s][S] != -1) return dp[s][S];
  for (int i = 9; i >= 0; i--) {
    if (S - i >= 0)
      if (solve2(S - i, s + 1, n, num + to_string(i)) == 1) return dp[s][S] = 1;
  }
  return dp[s][S] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  if (m == 0) {
    if (n == 1)
      cout << "0 0";
    else
      cout << "-1 -1";
    return 0;
  }
  p1 = "";
  p2 = "";
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= 9; i++) {
    if (solve(m - i, 1, n, to_string(i))) break;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 9; i >= 1; i--) {
    if (solve2(m - i, 1, n, to_string(i))) break;
  }
  if (p1 == "" || p2 == "")
    cout << -1 << " " << -1;
  else
    cout << p1 << " " << p2;
  cout << "\n";
  ;
  return 0;
}

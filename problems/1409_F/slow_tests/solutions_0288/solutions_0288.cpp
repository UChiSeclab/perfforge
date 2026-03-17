#include <bits/stdc++.h>
using namespace std;
const int N = 205;
long long dp[N][N][N];
int n, k;
string s, t;
long long solve(int i, int j, int m) {
  if (i == n) return 0;
  long long &r = dp[i][j][m];
  if (r != -1) return r;
  long long res = (s[i] == t[1]) * j + solve(i + 1, j + (s[i] == t[0]), m);
  if (m) {
    for (int x = 0; x < 26; x++) {
      res = max(res, (x + 'a' == t[1]) * j +
                         solve(i + 1, j + (x + 'a' == t[0]), m - 1));
    }
  }
  return r = res;
}
int main() {
  cin >> n >> k >> s >> t;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, k) << '\n';
  return 0;
}

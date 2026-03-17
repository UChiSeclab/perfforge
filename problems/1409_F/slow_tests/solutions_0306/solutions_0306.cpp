#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, k, dp[N][N][N];
string s, t;
int solve(int ind, int rem, int prev) {
  if (ind == n) return 0;
  int &ret = dp[ind][rem][prev];
  if (~ret) return ret;
  int c1 = 0, c2 = 0, c3 = 0;
  c1 = solve(ind + 1, rem, prev + (s[ind] == t[0]));
  if (s[ind] == t[1]) c1 += prev;
  if (rem > 0) {
    c2 = solve(ind + 1, rem - 1, prev + 1);
    if (t[0] == t[1]) c2 += prev;
    c3 = solve(ind + 1, rem - 1, prev);
    c3 += prev;
  }
  ret = max({c1, c2, c3});
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> k >> s >> t;
  cout << solve(0, k, 0);
  return 0;
}

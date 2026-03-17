#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
int n, m, k;
long long dp[2010][2010];
long long Rec(int i, int k) {
  if (i == n) return (k == 0);
  if (dp[i][k] != -1) return dp[i][k];
  long long Res1 = Rec(i + 1, k);
  long long Res2 = ((Rec(i + 1, k - 1) % Mod) * ((m - 1) % Mod)) % Mod;
  return dp[i][k] = ((Res1 % Mod) + (Res2 % Mod)) % Mod;
}
int main() {
  cin >> n >> m >> k;
  memset(dp, -1, sizeof(dp));
  cout << ((m % Mod) * (Rec(1, k) % Mod)) % Mod;
  return 0;
}

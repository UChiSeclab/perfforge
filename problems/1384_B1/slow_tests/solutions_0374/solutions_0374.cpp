#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y);
long long int gcd(long long int a, long long int b);
vector<long long int> ft = {1};
long long int modInv(long long int i) { return power(i, 1000000007 - 2); }
long long int ncr(long long int n, long long int r) {
  return (n >= r ? (ft[n] * modInv(ft[r])) % 1000000007 * modInv(ft[n - r]) %
                       1000000007
                 : 0);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int n, k, l;
long long int dp[101][1001];
vector<long long int> p, d;
long long int solve(long long int x, long long int time) {
  if (x == n + 1) return 1;
  if (time > 1000) return 0;
  if (d[x] + p[time % (2 * k)] > l and x != 0) return 0;
  if (dp[x][time] != -1) return dp[x][time];
  return dp[x][time] = (solve(x, time + 1) | solve(x + 1, time + 1));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    cin >> n >> k >> l;
    memset(dp, -1, sizeof(dp));
    p.resize(2 * k + 1);
    d.resize(n + 1, 0);
    for (long long int i = 1; i < n + 1; i++) cin >> d[i];
    for (long long int i = 0; i < k + 1; i++) p[i] = i;
    long long int j = 2;
    for (long long int i = k + 1; i <= 2 * k; i++) p[i] = k - (i - k);
    if (solve(0, 0))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

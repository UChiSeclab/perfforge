#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long z = 1000000007;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a);
      b--;
    } else {
      a = (a * a);
      b = b >> 1;
    }
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a, b;
    set<long long> s;
    map<long long, long long> m;
    for (long long i = 0; i < n; i++) {
      cin >> a >> b;
      s.insert(a);
      m[a] = b;
    }
    long long dp[1000005];
    memset(dp, 0, sizeof(dp));
    if (m[0] > 0) dp[0] = 1;
    for (long long i = 1; i <= 1000004; i++) {
      if (s.find(i) == s.end())
        dp[i] = dp[i - 1];
      else {
        if (m[i] >= i)
          dp[i] = 1;
        else
          dp[i] = dp[i - m[i] - 1] + 1;
      }
    }
    long long ans = dp[0];
    for (long long i = 1; i <= 1000004; i++) {
      if (dp[i] > ans) ans = dp[i];
    }
    cout << n - ans << "\n";
  }
}

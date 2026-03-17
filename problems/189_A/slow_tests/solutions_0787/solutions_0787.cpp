#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 5;
const long long modu = 1e9 + 7;
long long n, a, b, c;
long long dp[4005][4005];
long long fun(long long n, long long count) {
  if (n < 0) return 0;
  if (dp[n][count] != -1) return dp[n][count];
  if (n == 0) return count;
  long long ans1 = fun(n - a, count + 1);
  long long ans2 = fun(n - b, count + 1);
  long long ans3 = fun(n - c, count + 1);
  return dp[n][count] = max(ans1, max(ans2, ans3));
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> a >> b >> c;
  memset(dp, -1, sizeof(dp));
  cout << fun(n, 0);
}

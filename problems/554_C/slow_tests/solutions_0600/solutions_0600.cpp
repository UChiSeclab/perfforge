#include <bits/stdc++.h>
using namespace std;
long long nck[1005][1005];
long long m(long long a) {
  return ((a % 1000000007) + 1000000007) % 1000000007;
}
long long ncr(long long n, long long r) {
  if (r > n) return 0ll;
  if (n == r || r == 0) return 1ll;
  if (nck[n][r] != 0) return nck[n][r];
  return nck[n][r] = m(ncr(n - 1, r) + ncr(n - 1, r - 1));
}
int main() {
  int k;
  scanf("%d", &k);
  vector<int> a(k);
  for (int &i : a) scanf("%d", &i);
  vector<long long> dp(1005);
  dp[1] = 1;
  long long sm = a[0];
  for (int i = 2; i <= k; i++) {
    sm += a[i - 1];
    dp[i] = m(dp[i - 1] * ncr(sm - 1, a[i - 1] - 1));
  }
  printf("%lld\n", dp[k]);
}

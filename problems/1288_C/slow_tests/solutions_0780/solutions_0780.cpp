#include <bits/stdc++.h>
using namespace std;
long long n, m, dp[1005][1005][10];
long long fn(long long l, long long r, long long pos) {
  if (pos == m) return 1;
  if (l > r) return 0;
  long long &z = dp[l][r][pos];
  if (z != -1) return z;
  z = 0;
  z += fn(l, r, pos + 1);
  z %= 1000000007;
  z += fn(l + 1, r, pos);
  z %= 1000000007;
  z += fn(l, r - 1, pos);
  z %= 1000000007;
  z -= fn(l + 1, r - 1, pos);
  z += 1000000007;
  z %= 1000000007;
  return z;
}
int main() {
  long long int i, j, k, z = 0, c = 0, t, x, y, l, r, mid;
  scanf("%lld", &n);
  scanf("%lld", &m);
  memset(dp, -1, sizeof(dp));
  z = fn(1, n, 0);
  cout << z << endl;
}

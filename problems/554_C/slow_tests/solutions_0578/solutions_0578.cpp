#include <bits/stdc++.h>
using namespace std;
long long n, len;
long long MOD = 1000000007ll;
long long a[1111], d[1111], cache[1111][1111];
long long C(long long x, long long y) {
  if (x == y) return 1;
  if (y == 1) return x;
  if (y <= 0) return 1;
  long long &ret = cache[x][y];
  if (~ret) return ret;
  return ret = (C(x - 1, y) + C(x - 1, y - 1)) % MOD;
}
int main() {
  memset(cache, -1, sizeof(cache));
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  d[1] = 1;
  len = a[1];
  for (int i = 2; i <= n; i++) {
    d[i] = (d[i - 1] * C(len + a[i] - 1ll, a[i] - 1ll)) % MOD;
    len += a[i];
  }
  cout << d[n];
}

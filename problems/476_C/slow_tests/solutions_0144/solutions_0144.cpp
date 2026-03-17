#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
long long power(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = (r * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long z = power(2, mod - 2);
  long long a, b;
  cin >> a >> b;
  long long ans = 0;
  for (long long k = 1; k <= a; k++) {
    long long x = k * b + 1;
    x %= mod;
    x = (x * b) % mod;
    x = (x * (b - 1)) % mod;
    x = (x + mod) % mod;
    x = (x * z) % mod;
    ans = (ans + x) % mod;
  }
  cout << ans << endl;
  return 0;
}

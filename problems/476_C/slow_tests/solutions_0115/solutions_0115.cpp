#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  long long ans = 0, mod = 1e9 + 7;
  cin >> a >> b;
  for (long long k = 1; k < b; ++k) {
    long long diff = b * k, first = 2 * (k * b + k), n = a - 1, m = a;
    if (m % 2ll) {
      first /= 2;
      first %= mod;
      n /= 2;
      n %= mod;
      diff %= mod;
      diff *= n;
      diff %= mod;
      diff += first;
      diff %= mod;
      m %= mod;
      ans += (m * diff) % mod;
    } else {
      m /= 2;
      m %= mod;
      first %= mod;
      n %= mod;
      diff %= mod;
      diff *= n;
      diff %= mod;
      diff += first;
      diff %= mod;
      ans += (m * diff) % mod;
    }
    ans %= mod;
  }
  cout << ans % mod;
}

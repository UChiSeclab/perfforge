#include <bits/stdc++.h>
using namespace std;
const int mod = (1e9) + 7;
bool isprime(long long int a) {
  if (a <= 1) return false;
  for (long long int i = 2; i < floor(sqrt(a) + 1); i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
long long int modpow(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = ((ans % mod) * (x % mod)) % mod;
    }
    y = y >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int x, n, ans = 1;
  cin >> x >> n;
  for (long long int i = 1; i < floor(sqrt(x)) + 1; i++) {
    if (x % i == 0 && isprime(i)) {
      long long int m = n / i;
      while (m) {
        ans = (ans * modpow(i, m)) % mod;
        m = m / i;
      }
    }
    if (x % i == 0 && isprime((x / i)) && i != (x / i)) {
      long long int m = n / (x / i);
      while (m) {
        ans = (ans * modpow((x / i), m)) % mod;
        m = m / (x / i);
      }
    }
  }
  cout << ans;
  return 0;
}

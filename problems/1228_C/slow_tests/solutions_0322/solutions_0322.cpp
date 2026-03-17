#include <bits/stdc++.h>
const int N = 1e5 + 100;
const int INF = 1e9;
const unsigned long long mod = 1e9 + 7;
using namespace std;
unsigned long long x, n, ans = 1;
vector<unsigned long long> d;
bool isprime(unsigned long long a) {
  if (a == 1) return false;
  for (unsigned long long i = (2); (i) <= (sqrt(a)); ++(i)) {
    if (a % i == 0) return false;
  }
  return true;
}
unsigned long long qpow(unsigned long long x, unsigned long long y) {
  unsigned long long ret = 1, a = x;
  for (; y; a = a * a % mod, y >>= 1)
    if (y & 1) ret = ret * a % mod;
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> n;
  for (unsigned long long i = (1); (i) <= (sqrt(x)); ++(i)) {
    if (x % i == 0) {
      if (isprime(i)) d.push_back(i);
      if (isprime(x / i) && i * i != x) d.push_back(x / i);
    }
  }
  for (unsigned long long i = 0; (i) < (d.size()); ++(i)) {
    unsigned long long tmp = d[i], cnt = 0;
    while (1) {
      ans *= qpow(d[i], n / tmp);
      ans %= mod;
      if (n / tmp < d[i]) break;
      tmp *= d[i];
    }
  }
  cout << ans % mod;
  return 0;
}

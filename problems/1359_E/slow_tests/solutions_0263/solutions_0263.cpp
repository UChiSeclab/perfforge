#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e9;
const long long inf = (long long)2e18;
const long double eps = (long double)1e-8;
const long long mod = (long long)998244353;
const long long MAXN = (long long)5e5 + 1;
const long long MAXC = (long long)1e6 + 1;
const long long MAXE = (long long)1000;
const long long MAXLOG = 21;
const long long maxlen = (long long)1e5;
const long long asci = (long long)256;
const long long block = 480;
const long double PI = acos(-1);
const long double e = 2.7182818284;
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &cnt : arr) {
    in >> cnt;
  }
  return in;
};
long long fact[MAXN];
long long fast_pow(long long x, long long y) {
  if (!y) return 1;
  if (y % 2) return (x * fast_pow(x, y - 1)) % mod;
  long long c = fast_pow(x, y / 2);
  return (c * c) % mod;
}
long long back(long long x) { return fast_pow(x, mod - 2); }
long long c(long long n, long long k) {
  if (k > n) return 0;
  return fact[n] * back(fact[n - k]) % mod * back(fact[k]) % mod;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  fact[0] = 1;
  for (long long i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    ans += c(n / i - 1, k - 1);
    ans %= mod;
  }
  cout << ans;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(30);
  solve();
  return 0;
}

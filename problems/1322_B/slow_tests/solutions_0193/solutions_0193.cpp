#include <bits/stdc++.h>
using namespace std;
long double eps = (long double)1 / 1e7;
long long inf = INT_MAX, mod2 = 998244353, mod1 = 1e9 + 7;
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
const long long R = 1e4;
const long long tx[4] = {0, 0, -1, 1};
const long long ty[4] = {-1, 1, 0, 0};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const long long N = 2 * 1e5 + 4;
long long need(long long i, vector<long long> &b, long long pos_in_v) {
  long long first = upper_bound(b.begin() + pos_in_v + 1, b.end(),
                                (1ll << i + 1) - b[pos_in_v] - 1) -
                    b.begin() - pos_in_v;
  first -=
      lower_bound(b.begin() + pos_in_v + 1, b.end(), (1ll << i) - b[pos_in_v]) -
      b.begin();
  long long second = upper_bound(b.begin() + pos_in_v + 1, b.end(),
                                 (1ll << i + 2) - 2 - b[pos_in_v]) -
                     b.begin() - pos_in_v;
  second -= lower_bound(b.begin() + pos_in_v + 1, b.end(),
                        (1ll << i + 1) + (1ll << i) - b[pos_in_v]) -
            b.begin();
  return first + second;
}
bool add(long long bit, vector<long long> a) {
  vector<long long> b((long long)a.size());
  long long n = (long long)a.size();
  for (long long i = 0; i < n; i++) {
    b[i] = a[i] % (1ll << bit + 1);
  }
  sort(b.begin(), b.end());
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cnt += need(bit, b, i);
  }
  return cnt % 2;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &z : a) cin >> z;
  long long ans = 0;
  for (long long i = 0; i < 32; i++) {
    if (add(i, a)) {
      ans += (1ll << i);
    }
  }
  cout << ans;
  return 0;
}

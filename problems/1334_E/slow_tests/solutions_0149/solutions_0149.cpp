#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
const long long MOD = 998244353;
long long d, q;
vector<long long> prm;
long long dp_pow[1000];
long long mpow(long long a, long long n) {
  if (dp_pow[a] != -1) return dp_pow[a];
  if (n == 0) return 1;
  long long res = mpow(a, n / 2);
  res = res * res % MOD;
  if (n % 2) res = res * a % MOD;
  return dp_pow[a] = res;
}
map<long long, long long> mp;
long long dist(long long n) {
  if (mp.count(n)) return mp[n];
  long long tn = n;
  long long all_cnt = 0;
  vector<long long> v;
  for (long long p : prm) {
    long long cnt = 0;
    while (n % p == 0) {
      n /= p;
      cnt++;
    }
    all_cnt += cnt;
    if (cnt) v.push_back(cnt);
  }
  long long res = 1;
  for (long long i = 1; i <= all_cnt; i++) {
    res *= i;
    res %= MOD;
  }
  for (long long cnt : v) {
    for (long long i = 1; i <= cnt; i++) {
      res *= mpow(i, MOD - 2);
      res %= MOD;
    }
  }
  return mp[tn] = res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(dp_pow, -1, sizeof dp_pow);
  cin >> d >> q;
  long long cd = d;
  for (long long i = 2; i * i <= d; i++) {
    long long cnt = 0;
    while (cd % i == 0) {
      cd /= i;
      cnt++;
    }
    if (cnt) prm.push_back(i);
  }
  if (cd != 1) prm.push_back(cd);
  while (q--) {
    long long u, v;
    cin >> u >> v;
    if (u == v) {
      cout << "1\n";
      continue;
    }
    long long g = gcd(u, v);
    long long ans = (dist(u / g) * dist(v / g)) % MOD;
    cout << ans << '\n';
  }
}

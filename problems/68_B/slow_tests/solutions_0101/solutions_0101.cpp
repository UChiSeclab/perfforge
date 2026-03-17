#include <bits/stdc++.h>
using namespace std;
const long long N = 200005, INF = 2000000000000000000;
long double pi = 3.1415926535897932, minn = 1e-11;
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(std::numeric_limits<double>::max_digits10);
  ;
  long long n;
  long double k, ans = 0;
  cin >> n >> k;
  long double ar[n];
  for (long long i = 0; i < n; i++) cin >> ar[i];
  long double l = 0, r = 1000.0;
  while ((r - l) > minn) {
    long double m = (l + r) / 2.0;
    map<long double, long long> mp;
    for (long long i = 0; i < n; i++) mp[ar[i]]++;
    long long f = 0;
    while (mp.size()) {
      auto it = mp.begin();
      long double cu = (*it).first;
      it = mp.end();
      it--;
      long double last = (*it).first;
      if (cu >= m) break;
      long double req = (100.0 * (m - cu)) / (100.0 - k);
      auto itr = mp.lower_bound(req + m);
      if (itr == mp.end()) {
        if (last <= m) {
          f = 1;
          break;
        }
        long double g = last - m;
        mp[last]--;
        if (mp[last] == 0) mp.erase(last);
        mp[cu]--;
        if (mp[cu] == 0) mp.erase(cu);
        mp[cu + (g * ((100.0 - k) / 100.0))]++;
      } else {
        long double fin = (*itr).first;
        mp[fin]--;
        if (mp[fin] == 0) mp.erase(fin);
        mp[fin - req]++;
        mp[cu]--;
        if (mp[cu] == 0) mp.erase(cu);
      }
    }
    if (f == 0) {
      ans = m;
      l = m;
    } else
      r = m;
  }
  cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
long long dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long expo(long long n, long long m, long long p) {
  long long r = 1;
  n = n % p;
  while (m > 0) {
    if (m % 2) r = (r * n) % p;
    n = (n * n) % p;
    m = m / 2;
  }
  return r % p;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long> z_function(string s) {
  long long n = (long long)s.length();
  vector<long long> z(n);
  for (long long i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (long long i = 1; i < n - 1; i++) {
    cin >> a[i];
  }
  vector<pair<long long, long long> > v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  long long l = 0, h = 1e12;
  while (l < h) {
    long long mid = (l + h) / 2;
    long long t = mid;
    bool ok = true;
    long long dis[n];
    long long par[n];
    for (long long i = 0; i < n; i++) dis[i] = -(1LL << 61), par[i] = -1;
    dis[0] = mid;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        for (long long k = 0; k < n; k++) {
          if (j == k) continue;
          if (dis[k] < dis[j] -
                           d * (abs(v[j].first - v[k].first) +
                                abs(v[j].second - v[k].second)) +
                           a[k] &&
              (dis[j] -
               d * (abs(v[j].first - v[k].first) +
                    abs(v[j].second - v[k].second)) +
               a[k]) >= 0) {
            dis[k] = dis[j] -
                     d * (abs(v[j].first - v[k].first) +
                          abs(v[j].second - v[k].second)) +
                     a[k];
            par[k] = j;
          }
        }
      }
    }
    if (dis[n - 1] < 0) ok = false;
    if (ok)
      h = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
}

#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const long long N = 1e4 + 1;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void solve() {
  long long p, q, l, r;
  cin >> p >> q >> l >> r;
  vector<long long> v(2000 + 7, 0);
  for (long long i = 0; i < p; i++) {
    long long f, s;
    cin >> f >> s;
    for (long long j = f; j <= s; j++) {
      v[j] = 1;
    }
  }
  vector<long long> c;
  for (long long i = 0; i < q; i++) {
    long long f, s;
    cin >> f >> s;
    for (__typeof(s + 1) j = (f) - ((f) > (s + 1));
         j != (s + 1) - ((f) > (s + 1)); j += 1 - 2 * ((f) > (s + 1))) {
      c.push_back(j);
    }
  }
  long long ans = 0;
  for (long long i = l; i <= r; i++) {
    for (auto x : c) {
      if (v[x + i]) {
        ans++;
        {
          string _s = "ans";
          replace(_s.begin(), _s.end(), ',', ' ');
          stringstream _ss(_s);
          istream_iterator<string> _it(_ss);
          err(_it, ans);
        };
        break;
      }
    }
  }
  cout << ans << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}

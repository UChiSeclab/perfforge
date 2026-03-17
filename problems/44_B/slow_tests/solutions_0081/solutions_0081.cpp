#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
void solve() {
  long long n, a, b, c, ans = 0;
  cin >> n >> a >> b >> c;
  for (long long i = 0; i <= c && 2 * i <= n; i++) {
    for (long long j = 0; j <= min(b, n - 2 * i); j++) {
      long long need = n - (2 * i + j);
      if (need * 2 <= a) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

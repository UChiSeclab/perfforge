#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9 + 9;
const int MAXN = 1000006;
ll n, a, r, m, h[MAXN], t[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> r >> m;
  ll s1 = 0, s2 = 0;
  m = min(m, a + r);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    t[i] = h[i];
    s2 += h[i];
  }
  sort(t, t + n);
  ll ans = 1e18;
  for (ll i = 0; i < n; ++i) {
    while (t[i + 1] == t[i]) {
      s1 += t[i];
      s2 -= t[i];
      ++i;
    }
    s1 += t[i];
    s2 -= t[i];
    ll mean = (s1 + s2 + n - 1) / n;
    if (t[i] <= mean and t[i + 1] >= mean) {
      ans = min(
          ans, (s2 - mean * (n - i - 1)) * (m - a) + (mean * (i + 1) - s1) * a);
    }
    if (t[i] * (i + 1) - s1 >= s2 - t[i] * (n - i - 1)) {
      ans = min(
          ans, (s2 - t[i] * (n - i - 1)) * (m - a) + (t[i] * (i + 1) - s1) * a);
    }
  }
  swap(s1, s2);
  for (ll i = 0; i < n; ++i) {
    while (t[i + 1] == t[i]) {
      s1 += t[i];
      s2 -= t[i];
      ++i;
    }
    s1 += t[i];
    s2 -= t[i];
    ll mean = (s1 + s2) / n;
    if (t[i] <= mean and t[i + 1] >= mean) {
      ans = min(
          ans, (s2 - mean * (n - i - 1)) * r + (mean * (i + 1) - s1) * (m - r));
    }
    if (t[i] * (i + 1) - s1 <= s2 - t[i] * (n - i - 1)) {
      ans = min(
          ans, (s2 - t[i] * (n - i - 1)) * r + (t[i] * (i + 1) - s1) * (m - r));
    }
  }
  cout << ans << endl;
}

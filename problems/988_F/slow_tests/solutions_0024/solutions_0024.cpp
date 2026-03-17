#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 1e10;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
const ll MAX = 2e5 + 1;
inline ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
inline ll sub(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }
inline ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll pwr(ll x, ll n) {
  if (!n) return 1;
  if (n & 1)
    return mul(x, pwr(mul(x, x), (n - 1) / 2));
  else
    return pwr(mul(x, x), n / 2);
}
ll modinv(ll n) { return pwr(n, mod - 2); }
ll n, m, q;
ll rain[2005], fatigue[2005], dp[2005][2005][2];
ll rec(ll i, ll j, ll f) {
  if (i > n) {
    return 0;
  }
  if (dp[i][j][f] != -1) {
    return dp[i][j][f];
  }
  if (f) {
    if (!rain[i]) {
      return dp[i][j][f] =
                 min(rec(i + 1, j, 1) + fatigue[j],
                     min(rec(i + 1, i, 1) + fatigue[i], rec(i + 1, n + 1, 0)));
    } else {
      return dp[i][j][f] = min(rec(i + 1, j, 1) + fatigue[j],
                               rec(i + 1, i, 1) + fatigue[i]);
    }
  } else {
    if (!rain[i]) {
      return dp[i][j][f] =
                 min(rec(i + 1, i, 1) + fatigue[i], rec(i + 1, n + 1, 0));
    } else {
      return dp[i][j][f] = rec(i + 1, i, 1) + fatigue[i];
    }
  }
}
void speed_solve() {
  cin >> n >> q >> m;
  memset(rain, 0, sizeof(rain));
  for (ll i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    for (ll j = l; j < r; j++) {
      rain[j] = 1;
    }
  }
  for (ll i = 0; i < 2005; i++) {
    fatigue[i] = inf;
  }
  for (ll i = 0; i < m; i++) {
    ll x, p;
    cin >> x >> p;
    fatigue[x] = min(fatigue[x], p);
  }
  memset(dp, -1, sizeof(dp));
  ll ans = rec(0, n + 1, 0);
  if (ans >= inf) {
    ans = -1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll test_cases = 1;
  for (ll i = 0; i < test_cases; i++) {
    speed_solve();
  }
  return 0;
}

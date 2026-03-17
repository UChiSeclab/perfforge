#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
void print() {}
template <class H, class... T>
void print(H&& h, T&&... t) {
  cout << h << " \n"[sizeof...(t) == 0];
  print(forward<T>(t)...);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  ll a[400010];
  for (ll i = (0); i < (N); i++) cin >> a[i];
  sort(a, a + N);
  ll ans = 0;
  for (ll bit = (31); bit >= (0); bit--) {
    ll n = (1LL << bit);
    ll n2 = n * 2;
    for (ll i = (0); i < (N); i++) {
      a[i] %= n2;
    }
    sort(a, a + N);
    ll res = 0;
    for (ll i = (0); i < (N); i++) {
      ll l1 = n - a[i], r1 = n2 - a[i] - 1;
      ll l2 = l1 + n2, r2 = r1 + n2 - 1;
      ll p1 = upper_bound(a, a + N, r1) - a;
      ll p2 = lower_bound(a, a + N, l1) - a;
      p2 = max(p2, i + 1);
      ll diff = p1 - p2;
      if (diff > 0) res += diff;
      p1 = upper_bound(a, a + N, r2) - a;
      p2 = lower_bound(a, a + N, l2) - a;
      p2 = max(p2, i + 1);
      diff = p1 - p2;
      if (diff > 0) res += diff;
    }
    if (res % 2 == 1) {
      ans += (1LL << bit);
    }
  }
  print(ans);
}

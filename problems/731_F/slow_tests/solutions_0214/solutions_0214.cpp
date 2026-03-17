#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using llu = unsigned long long;
ll mod = 1e9 + 7;
ll mode = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t, n, m, i, j, k;
  cin >> n;
  ll a[n];
  unordered_map<ll, ll> z;
  k = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    z[a[i]]++;
    k += a[i];
  }
  sort(a, a + n);
  ll ans = 0;
  if (a[0] == 1) {
    cout << k;
    return 0;
  }
  for (i = 2; i <= 200000; i++) {
    if (z[i]) {
      k = 0;
      for (j = i; j <= 200000; j += i) {
        ll it = lower_bound(a, a + n, j) - a;
        ll it1 = lower_bound(a, a + n, j + i) - a;
        k += (it1 - it) * j;
      }
      ans = max(ans, k);
    }
  }
  cout << ans;
}

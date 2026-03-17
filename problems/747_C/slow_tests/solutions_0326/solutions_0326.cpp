#include <bits/stdc++.h>
using namespace std;
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0LL) {
    x = 0LL;
    y = 1LL;
    return b;
  }
  long long xx, yy;
  long long val = egcd(b % a, a, xx, yy);
  x = yy - (b / a) * xx;
  y = xx;
  return val;
}
long long gcd(long long a, long long b) {
  while (true) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    long long p = b % a, q = a;
    a = p;
    b = q;
  }
}
long long powerMod(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
void solve() {
  int n, m, i, j, k, l, p;
  cin >> n >> m;
  vector<int> servers(n + 1, 0);
  vector<pair<pair<int, int>, int> > v(m);
  for (auto &i : v) {
    cin >> i.first.first >> i.first.second >> i.second;
  }
  for (int time = 1, cur = 0; time <= 1000000 && cur < m; time++) {
    if (v[cur].first.first == time) {
      for (i = 1, j = 0; i <= n; i++) {
        if (servers[i] == 0) j++;
      }
      if (j < v[cur].first.second) {
        cout << -1 << "\n";
      } else {
        for (i = 1, j = k = 0; i <= n && k < v[cur].first.second; i++) {
          if (servers[i] == 0) {
            servers[i] = v[cur].second;
            j += i;
            k++;
          }
        }
        cout << j << "\n";
      }
      cur++;
    }
    for (auto &i : servers) {
      if (i) i--;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

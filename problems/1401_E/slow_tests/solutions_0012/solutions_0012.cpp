#include <bits/stdc++.h>
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
ll gcd(ll n, ll m) {
  ll tmp;
  while (m != 0) {
    tmp = n % m;
    n = m;
    m = tmp;
  }
  return n;
}
ll lcm(ll n, ll m) { return abs(n) / gcd(n, m) * abs(m); }
using namespace std;
template <typename T>
struct BIT {
  vector<T> bit;
  int N;
  BIT(int n) : N(n) { bit.assign(++n, 0); }
  T sum(int i) {
    T s = 0;
    ++i;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, T x) {
    ++i;
    while (i < (int)bit.size()) {
      bit[i] += x;
      i += i & -i;
    }
  }
  T Lower_bound(T k) {
    if (k <= 0) return 0;
    T x = 0;
    T mul = 1;
    while (mul < N) {
      mul *= 2;
    }
    for (T i = mul; i > 0; i /= 2) {
      if (x + i <= N && bit[x + i] < k) {
        k -= bit[x + i];
        x += i;
      }
    }
    return x;
  }
};
using P = pair<ll, ll>;
void solve() {
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  vector<ll> x(m);
  vector<ll> ly(m), ry(m);
  vector<pair<ll, P>> v;
  for (int i = (int)0; i < (int)n; ++i) {
    ll y, lx, rx;
    cin >> y >> lx >> rx;
    v.emplace_back(y, P{lx, rx});
    if (lx == 0 && rx == 1e6) ++ans;
  }
  for (int i = (int)0; i < (int)m; ++i) {
    cin >> x[i];
    cin >> ly[i] >> ry[i];
    if (ly[i] == 0 && ry[i] == 1e6) ++ans;
  }
  vector<P> add(m), sub(m);
  for (int i = (int)0; i < (int)m; ++i) {
    add[i] = P{ry[i], x[i]};
    sub[i] = P{ly[i], x[i]};
  }
  sort(add.rbegin(), add.rend());
  sort(sub.rbegin(), sub.rend());
  sort(v.rbegin(), v.rend());
  int pos = 0, pos2 = 0, py = 0;
  BIT<ll> tree(1e6 + 1);
  for (int i = 1e6; i >= 0; --i) {
    while (pos < m && add[pos].first == i) {
      tree.add(add[pos].second, 1);
      ++pos;
    }
    if (py < n && v[py].first == i) {
      ans += tree.sum(v[py].second.second) - tree.sum(v[py].second.first - 1);
      ++py;
    }
    while (pos2 < m && sub[pos2].first == i) {
      tree.add(sub[pos2].second, -1);
      ++pos2;
    }
  }
  ans++;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  solve();
  return 0;
}

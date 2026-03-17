#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
bool maxi(A &a, const B &b) {
  return (a < b) ? (a = b, true) : false;
};
template <class A, class B>
bool mini(A &a, const B &b) {
  return (a > b) ? (a = b, true) : false;
};
const int MOD = 1e9 + 7, maxN = 1005, maxK = 10;
int power(const int n, const int k) {
  if (!k) return 1;
  int res = power(n, k >> 1);
  res = (1LL * (res) * (res) % MOD);
  if (k & 1) res = (1LL * (res) * (n) % MOD);
  return res;
}
int n, res, k, p[maxK];
void rec(const int i) {
  static function<bool(const int)> can = [&](const int x) -> bool {
    static int cnt = 0, vis[maxN];
    ++cnt;
    static function<bool(const int)> walk = [&](const int x) -> bool {
      if (x == 1) return true;
      if (vis[x] == cnt) return false;
      vis[x] = cnt;
      return walk(p[x]);
    };
    return walk(x);
  };
  if (i < 1) {
    for (int i = (2), _b = (k); i <= _b; ++i)
      if (!can(i)) return;
    res = (((res) + (1)) % MOD);
    return;
  }
  for (p[i] = 1; p[i] <= k; ++p[i]) rec(i - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  rec(k);
  res = (1LL * (res) * (power(n - k, n - k)) % MOD);
  cout << res << '\n';
  return 0;
}

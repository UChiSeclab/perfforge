#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2 * 1e5 + 10;
const long long inf = 1e18;
const long long ninf = -1e18;
long long gcd(long long, long long);
long long modPower(long long, long long, long long);
long long power(long long, long long);
long long modInverse(long long, long long);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modPower(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = modPower(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long p = power(x, y / 2);
  p = (p * p);
  return (y % 2 == 0) ? p : (x * p);
}
long long modInverse(long long a, long long m) {
  return ((modPower(a, m - 2, m) + mod) % mod);
}
long long modDivide(long long a, long long b, long long m) {
  a = a % m;
  long long inv = modInverse(b, m);
  if (inv == -1)
    return 0;
  else
    return (inv * a) % m;
}
struct comparepq {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
  }
};
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.first < b.first;
  return a.first < b.first;
}
vector<vector<int>> v(8);
int val[10];
map<pair<int, int>, int> cnt;
bool ok = 1;
int vis[10];
bool dfs(int src) {
  vis[src] = 1;
  for (auto i : v[src]) {
    if (val[src] != 0 && val[i] != 0) {
      pair<int, int> p = make_pair(val[src], val[i]);
      if (p.first > p.second) swap(p.first, p.second);
      if (!cnt.count(p)) cnt[p]++;
    }
    if (vis[i] != 1) {
      bool ok1 = dfs(i);
      if (!ok1) return false;
    }
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    int u, va;
    cin >> u >> va;
    v[u].push_back(va);
  }
  int ans = 0;
  for (int i1 = (0); i1 < (7); i1++) {
    val[1] = i1;
    for (int i2 = (0); i2 < (7); i2++) {
      val[2] = i2;
      for (int i3 = (0); i3 < (7); i3++) {
        val[3] = i3;
        for (int i4 = (0); i4 < (7); i4++) {
          val[4] = i4;
          for (int i5 = (0); i5 < (7); i5++) {
            val[5] = i5;
            for (int i6 = (0); i6 < (7); i6++) {
              val[6] = i6;
              for (int i7 = (0); i7 < (7); i7++) {
                val[7] = i7;
                memset(vis, -1, sizeof(vis));
                for (int i = (1); i < (8); i++) {
                  if (vis[i] != 1) ok = dfs(i);
                }
                if (ok) ans = max(ans, (int)cnt.size());
                ok = 1;
                cnt.clear();
              }
            }
          }
        }
      }
    }
  }
  cout << ans;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  for (int i = (0); i < (t); i++) {
    solve();
  }
  return 0;
}

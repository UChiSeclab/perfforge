#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
clock_t START;
inline long double TIME() {
  return (long double)(clock() - START) / CLOCKS_PER_SEC;
}
void SHOW() {
  cout << fixed << setprecision(10);
  cout << TIME() << " SECONDS FROM START\n";
}
long double TL = 2.0;
int calls = 0;
inline bool IS() {
  if (TL - TIME() < 0.1) return true;
  return false;
}
template <typename T1, typename T2>
inline bool amin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
inline bool amax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &u : v) is >> u;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto &u : v) os << u << ' ';
  return os;
}
int hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937},
    mod = hash_mod[rnd() % 4];
int hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];
int binpow(int first, int p) {
  int res = 1;
  while (p) {
    if (p % 2) res = (res * first) % mod;
    first = (first * first) % mod;
    p /= 2;
  }
  return res;
}
const int N = 1e6 + 7, NS = 2e3 + 7, lg = 20, sq = 550, inf = 2e9 + 7;
const long double eps = 1e-9, pi = 3.14159265359;
int cnt[2000], nw[2000];
void solve() {
  int n, k, first;
  cin >> n >> k >> first;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  for (int it = 0; it < k; it++) {
    int cur = 0;
    fill(nw, nw + 2000, 0);
    for (int i = 0; i < 2000; i++) {
      int t;
      if (cur % 2 == 0) {
        t = (cnt[i] + 1) / 2;
      } else {
        t = cnt[i] / 2;
      }
      nw[i ^ first] += t;
      nw[i] += cnt[i] - t;
      cur += cnt[i];
    }
    for (int i = 0; i < 2000; i++) cnt[i] = nw[i];
  }
  int mx, mn;
  for (int i = 0; i < 2000; i++) {
    if (cnt[i]) {
      mn = i;
      break;
    }
  }
  for (int i = 1999; i >= 0; i--) {
    if (cnt[i]) {
      mx = i;
      break;
    }
  }
  cout << mx << ' ' << mn;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}

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
long long calls = 0;
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
long long hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937},
          mod = hash_mod[rnd() % 4];
long long hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];
long long binpow(long long first, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2) res = (res * first) % mod;
    first = (first * first) % mod;
    p /= 2;
  }
  return res;
}

void check_recursion_depth(int currentDepth, int threshold) {
    if (currentDepth > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - deep recursive exploration!" << endl;
        abort();
    }
}

void check_state_combination(int stateCount, int threshold) {
    if (stateCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many states being explored!" << endl;
        abort();
    }
}

void check_high_branching_factor(int branchingFactor, int threshold) {
    if (branchingFactor > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

const long long N = 1e6 + 7, NS = 2e3 + 7, lg = 20, sq = 550, inf = 2e9 + 7;
const long double eps = 1e-8, pi = 3.14159265359;
long long a[N], mx = 61;
map<pair<long long, long long>, long long> d;
long long calc(long long i, long long mask, int depth) {
  check_recursion_depth(depth, 50);  // Check for deep recursion
  if (d.count(make_pair(i, mask))) return d[{i, mask}];
  vector<long long> can(mx, 0);
  for (long long k = 0; k < i; k++) {
    if (mask & (1ll << k)) {
      long long val = calc(i - (k + 1), (mask ^ (1 << k)), depth + 1);
      can[val] = 1;
    }
  }
  for (long long k = 0; k < mx; k++) {
    if (!can[k]) {
      check_state_combination(d.size(), 100000);  // Check for too many states
      return d[{i, mask}] = k;
    }
  }
}

void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    amax(mx, a[i]);
  }
  d[{0, 0}] = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long first = a[i];
    check_high_branching_factor(first, 30);  // Check for high branching factor
    ans ^= calc(first, (1ll << first) - 1, 0);
  }
  if (ans)
    cout << "NO";
  else
    cout << "YES";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
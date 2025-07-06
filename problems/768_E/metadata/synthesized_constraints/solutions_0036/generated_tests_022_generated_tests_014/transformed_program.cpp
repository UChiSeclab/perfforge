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
const long double eps = 1e-8, pi = 3.14159265359;
int a[N], mx = 61, cnt[N];
map<long long, int> d[62];

void check_recursive_depth_invariant(int stones) {
    if (stones >= 55) {  // Threshold chosen based on the maximum stone value (60)
        cerr << "Warning: Potential high recursion depth triggered due to large pile size!" << endl;
        abort();
    }
}

void check_memoization_efficiency_invariant(int uniqueStates) {
    if (uniqueStates > 100000) {  // Arbitrary large threshold for unique states
        cerr << "Warning: Memoization inefficiency triggered due to too many unique states!" << endl;
        abort();
    }
}

void check_stone_distribution_invariant(const vector<int>& stones) {
    int maxStone = *max_element(stones.begin(), stones.end());
    int minStone = *min_element(stones.begin(), stones.end());
    if ((maxStone - minStone) > 50) {  // Threshold based on a significant difference in stone counts
        cerr << "Warning: Complex state transitions triggered due to high stone distribution variance!" << endl;
        abort();
    }
}

int calc(int i, long long mask) {
  if (d[i].count(mask)) return d[i][mask];
  cnt[i]++;
  vector<int> can(mx, 0);
  for (int k = 0; k < i; k++) {
    if (mask & (1ll << k)) {
      int val = calc(i - (k + 1), (mask ^ (1 << k)));
      can[val] = 1;
    }
  }
  for (int k = 0; k < mx; k++) {
    if (!can[k]) {
      return d[i][mask] = k;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    amax(mx, a[i]);
  }
  
  // Insert checks after reading inputs
  for (int i = 0; i < n; i++) {
    check_recursive_depth_invariant(a[i]);
  }
  check_stone_distribution_invariant(vector<int>(a, a + n));

  d[0][0] = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int first = a[i];
    ans ^= calc(first, (1ll << first) - 1);
  }
  
  // Insert check for memoization efficiency
  check_memoization_efficiency_invariant(d[0].size());

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
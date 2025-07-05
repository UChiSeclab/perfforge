#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
clock_t START;
inline long double TIME() {
  return (long double)(clock() - START) / CLOCKS_PER_SEC;
}

void check_large_initial_pile(long long stone_count) {
    if (stone_count > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large initial stone pile!" << endl;
        abort();
    }
}

void check_recursion_depth(long long recursion_depth) {
    if (recursion_depth > 30) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

void check_backtracking_paths(long long explored_paths) {
    if (explored_paths > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive paths!" << endl;
        abort();
    }
}

void check_memoization_efficiency(long long memo_hits, long long total_calls) {
    if (total_calls > 0 && (memo_hits / (double)total_calls) < 0.1) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization!" << endl;
        abort();
    }
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
const long long N = 1e6 + 7, NS = 2e3 + 7, lg = 20, sq = 550, inf = 2e9 + 7;
const long double eps = 1e-8, pi = 3.14159265359;
long long a[N], mx = 61;
map<long long, long long> d[62];
long long memo_hits = 0, total_calls = 0;

long long calc(long long i, long long mask) {
  total_calls++;
  if (d[i].count(mask)) {
    memo_hits++;
    return d[i][mask];
  }
  vector<long long> can(mx, 0);
  for (long long k = 0; k < i; k++) {
    if (mask & (1ll << k)) {
      long long val = calc(i - (k + 1), (mask ^ (1 << k)));
      can[val] = 1;
    }
  }
  for (long long k = 0; k < mx; k++) {
    if (!can[k]) {
      return d[i][mask] = k;
    }
  }
}

void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    check_large_initial_pile(a[i]); // Check for large initial piles.
    amax(mx, a[i]);
  }
  d[0][0] = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long first = a[i];
    ans ^= calc(first, (1ll << first) - 1);
  }
  check_memoization_efficiency(memo_hits, total_calls); // Check memoization efficiency.
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
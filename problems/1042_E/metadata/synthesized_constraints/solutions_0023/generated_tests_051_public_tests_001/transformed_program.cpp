#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 998244353;
const int MAXN = 1010, LOG = 20;

// Function to calculate power with modulo
long long powmod(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * powmod(a * a % mod, b >> 1) % mod;
  return powmod(a * a % mod, b >> 1);
}

// Function to calculate modular inverse
long long inv(long long x) { return powmod(x, mod - 2); }

// Global variables
long long n, m, k, u, v, r, c, t, sdp, sx, sy, sxx, syy, ans;
int A[MAXN][MAXN];
pair<int, int> ind[MAXN * MAXN];
long long dp[MAXN][MAXN];

// Comparator function for sorting
bool cmp(pair<int, int> i, pair<int, int> j) {
  return A[i.first][i.second] < A[j.first][j.second];
}

// Checker functions for invariants
void check_sort_invariant(int distinct_elements, int total_elements) {
    if (distinct_elements < total_elements / 2) {
        cerr << "Warning: sort_invariant triggered - potential sorting bottleneck due to similar values" << endl;
        abort();
    }
}

void check_powmod_invariant(int n, int m) {
    if (n * m > 500000) {
        cerr << "Warning: powmod_invariant triggered - excessive calls to powmod due to large matrix size" << endl;
        abort();
    }
}

void check_iteration_invariant(int distinct_elements) {
    if (distinct_elements > 800) {
        cerr << "Warning: iteration_invariant triggered - high computation due to large number of distinct values" << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  // Ensure that the powmod invariant is checked after input size is known
  check_powmod_invariant(n, m);

  map<int, int> distinct_count;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> A[i][j];
      ind[t++] = {i, j};
      distinct_count[A[i][j]]++; // Track distinct elements
    }

  // Check sort invariant before sorting
  check_sort_invariant(distinct_count.size(), t);

  sort(ind, ind + t, cmp);

  for (int i = 0, j = i; i < t; i = ++j) {
    // Check iteration invariant in the loop
    check_iteration_invariant(j - i + 1);

    while (A[ind[i].first][ind[i].second] ==
           A[ind[j + 1].first][ind[j + 1].second])
      j++;

    for (int k = i; k <= j; k++) {
      long long x = ind[k].first, y = ind[k].second;
      dp[x][y] =
          (x * x * i + y * y * i + sdp - 2 * x * sx - 2 * y * sy + sxx + syy) %
          mod;
      dp[x][y] = dp[x][y] * inv(i) % mod;
    }
    for (int k = i; k <= j; k++) {
      long long x = ind[k].first, y = ind[k].second;
      dp[x][y] = (dp[x][y] + mod) % mod;
      sdp = (sdp + dp[x][y]) % mod;
      sx = (sx + x) % mod;
      sy = (sy + y) % mod;
      sxx = (sxx + x * x) % mod;
      syy = (syy + y * y) % mod;
    }
  }

  cin >> r >> c;
  cout << dp[r][c] << '\n';
  return 0;
}
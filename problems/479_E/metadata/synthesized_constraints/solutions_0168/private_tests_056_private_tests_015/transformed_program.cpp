#include <bits/stdc++.h>
using namespace std;

// Checkers to detect performance bottlenecks
void check_distance_invariant(int l, int r, int b) {
    if (r - l > 5000 / 2) { // Threshold based on half the maximum n
        cerr << "Warning: distance_invariant triggered - too many possible floor moves" << endl;
        abort();
    }
}

void check_loop_invariant(int k, int l, int r) {
    if ((r - l + 1) * k > 10000) { // Threshold based on k and range product
        cerr << "Warning: loop_invariant triggered - large range and trip count" << endl;
        abort();
    }
}

void check_ways_invariant(int l, int r, int b) {
    if (r - l > 5000 / 3) { // Threshold based on a third of the maximum n
        cerr << "Warning: ways_invariant triggered - excessive range in Ways function" << endl;
        abort();
    }
}

template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}

const int N = 5e3 + 7;
const int mod = (int)1e9 + 7;
int dp[N], tdp[N];
int l = 1, r, a, b, k;
int Ways(int x) { return dp[x]; }
int Ways(int l, int r) {
  if (l > r) return 0;
  int ret = Ways(r) - Ways(l - 1);
  return (ret % mod + mod) % mod;
}

int solve() {
  Int(r, a);
  Int(b, k);
  if (a < b) r = b - 1;
  if (a > b) l = b + 1;

  // Insert checkers to detect potential slow paths
  check_distance_invariant(l, r, b);
  check_loop_invariant(k, l, r);

  for (int i = l; i <= r; ++i) dp[i] = 1;
  for (int j = 1; j <= k; ++j) {
    for (int i = l; i <= r; ++i) {
      tdp[i] = 0;
      dp[i] += dp[i - 1];
      dp[i] %= mod;
    }
    for (int i = l; i <= r; ++i) {
      int mxDist = abs(b - i) - 1;
      // Check before using the Ways function
      check_ways_invariant(l, r, b);
      tdp[i] += Ways(max(l, i - mxDist), i - 1);
      tdp[i] += Ways(i + 1, min(r, i + mxDist));
      if (tdp[i] > mod) tdp[i] -= mod;
    }
    for (int i = l; i <= r; ++i) dp[i] = tdp[i];
  }
  printf("%d\n", dp[a]);
  return 0;
}

int main() {
  int tests = 1, CaseNo = 0;
  while (tests--) {
    solve();
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dp[N];
int n, m, s[N], x[N];
const int inf = 0x3f3f3f3f;
struct xds {
  int mn, l, r;
} t[N << 2];

void change(int p, int l, int r, int d) {
  if (l <= t[p].l && r >= t[p].r) {
    t[p].mn = min(t[p].mn, d);
    return;
  }
  int mid = (t[p].l + t[p].r) / 2;
  if (l <= mid) change(p * 2, l, r, d);
  if (r > mid) change(p * 2 + 1, l, r, d);
  t[p].mn = min(t[p * 2].mn, t[p * 2 + 1].mn);
}

void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r;
  t[p].mn = inf;
  if (l == r) {
    t[p].mn = inf;
    return;
  }
  int mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  t[p].mn = min(t[p * 2].mn, t[p * 2 + 1].mn);
}

long long ask(int p, int l, int r) {
  if (l <= t[p].l && r >= t[p].r) return t[p].mn;
  int mid = (t[p].l + t[p].r) / 2;
  long long val = inf;
  if (l <= mid) val = min(val, ask(p * 2, l, r));
  if (r > mid) val = min(val, ask(p * 2 + 1, l, r));
  return val;
}

// Checkers based on performance-characterizing invariants
void check_large_m_nested_loops(int n, int m) {
    if (m > 50000 && n > 10) {
        cerr << "Warning: Performance bottleneck due to large m and nested loops!" << endl;
        abort();
    }
}

void check_frequent_updates(int updateCount, int queryCount) {
    if (updateCount > 1000000 || queryCount > 2000000) {
        cerr << "Warning: Performance bottleneck due to frequent range updates/queries!" << endl;
        abort();
    }
}

void check_zero_scope_antennas(int zeroScopeCount) {
    if (zeroScopeCount > 10) {
        cerr << "Warning: Performance bottleneck due to many antennas with zero initial scope!" << endl;
        abort();
    }
}

void check_large_gaps(int largestGap) {
    if (largestGap > 10000) {
        cerr << "Warning: Performance bottleneck due to large gaps between antennas!" << endl;
        abort();
    }
}

int main() {
  cin >> n >> m;
  
  int zeroScopeCount = 0;
  int largestGap = 0;
  int previousX = 0;

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> s[i];
    if (s[i] == 0) zeroScopeCount++;
    if (i > 1) largestGap = max(largestGap, x[i] - previousX);
    previousX = x[i];
  }

  // Performance checkers
  check_large_m_nested_loops(n, m);
  check_zero_scope_antennas(zeroScopeCount);
  check_large_gaps(largestGap);

  build(1, 0, m);
  change(1, 0, 0, 0);
  int mxr = 0;
  int updateCount = 0;
  int queryCount = 0;

  for (int i = 0; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      int l = i + 1;
      if (x[j] < l) continue;
      int r = x[j] + x[j] - l;
      int c = x[j] - l - s[j];
      if (c < 0) r = r - c, c = 0;
      r = min(r, m);
      mxr = max(mxr, r);
      updateCount++;
      queryCount += 2;
      change(1, r, r, min(ask(1, r, r), c + ask(1, i, m)));
    }

  check_frequent_updates(updateCount, queryCount);

  long long ans = inf;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, ask(1, i, i) + m - i);
  }

  cout << ans << endl;
}
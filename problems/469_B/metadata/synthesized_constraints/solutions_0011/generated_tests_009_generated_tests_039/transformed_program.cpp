#include <bits/stdc++.h>
using namespace std;

struct s {
  int l, r;
} ab[55], cd[55];

int c[2111];

// Checker function for interval overlap complexity
void check_overlap_invariant(int overlapCount) {
    if (overlapCount > 2000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive interval overlap!" << endl;
        abort();
    }
}

// Checker function for high range of possible wake-up times
void check_wakeup_range_invariant(int range) {
    if (range > 500) {
        cerr << "Warning: Performance bottleneck condition triggered due to large wake-up time range!" << endl;
        abort();
    }
}

// Checker function for dense time intervals
void check_dense_intervals_invariant(int p, int q) {
    if (p * q > 1500) {
        cerr << "Warning: Performance bottleneck condition triggered due to dense time intervals!" << endl;
        abort();
    }
}

int getnum(int x) {
  if (x <= 0) return 0;
  int rnt = 0;
  for (int i = x; i <= 2111; i += (i & (-i))) {
    rnt += c[i];
  }
  return rnt;
}

void add(int i, int a) {
  while (i >= 1) {
    c[i] += a;
    i -= (i & (-i));
  }
}

int main() {
  int p, q, l, r;
  scanf("%d%d%d%d", &p, &q, &l, &r);

  // Check for dense time intervals
  check_dense_intervals_invariant(p, q);

  for (int i = 0; i < p; i++) scanf("%d%d", &ab[i].l, &ab[i].r);
  for (int i = 0; i < q; i++) scanf("%d%d", &cd[i].l, &cd[i].r);

  // Check for high range of possible wake-up times
  check_wakeup_range_invariant(r - l);

  int ans = 0;
  for (int i = l; i <= r; i++) {
    memset(c, 0, sizeof(c));
    for (int j = 0; j < p; j++) {
      add(ab[j].r, 1);
      add(ab[j].l - 1, -1);
    }
    for (int j = 0; j < q; j++) {
      add(cd[j].r + i, 1);
      add(cd[j].l - 1 + i, -1);
    }
    for (int j = 1; j < 2111; j++) {
      int overlapCount = getnum(j);
      
      // Check for excessive interval overlap
      check_overlap_invariant(overlapCount);

      if (overlapCount > 1) {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
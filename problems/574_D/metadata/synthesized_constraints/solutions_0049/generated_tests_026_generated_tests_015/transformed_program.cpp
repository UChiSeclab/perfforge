#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;

struct segtree_asc {
 public:
  segtree_asc(int _n) : n(_n) {
    num.resize(n << 2, inf);
    push.resize(n << 2, inf);
  }
  void update(int l, int r, int val) { _update(1, 1, n, l, r, val); }
  int get(int at) { return _get(1, 1, n, at); }

 private:
  void relax(int p, int l, int r) {
    if (push[p] != inf) {
      if (l < r) {
        int mid = (l + r) >> 1;
        push[p + p] = min(push[p + p], push[p]);
        push[p + p + 1] = min(push[p + p + 1], push[p] + (mid + 1 - l));
      } else {
        num[p] = min(num[p], push[p]);
      }
      push[p] = inf;
    }
  }
  void _update(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
      push[p] = min(push[p], val);
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    _update(p + p, l, mid, ll, rr, val);
    _update(p + p + 1, mid + 1, r, ll, rr, val + max(0, mid + 1 - max(l, ll)));
  }
  int _get(int p, int l, int r, int at) {
    relax(p, l, r);
    if (l == r) return num[p];
    int mid = (l + r) >> 1;
    if (at <= mid) {
      return _get(p + p, l, mid, at);
    } else {
      return _get(p + p + 1, mid + 1, r, at);
    }
  }
  int n;
  vector<int> num;
  vector<int> push;
};

struct segtree_des {
 public:
  segtree_des(int _n) : n(_n) {
    num.resize(n << 2, inf);
    push.resize(n << 2, inf);
  }
  void update(int l, int r, int val) { _update(1, 1, n, l, r, val); }
  int get(int at) { return _get(1, 1, n, at); }

 private:
  void relax(int p, int l, int r) {
    if (push[p] != inf) {
      if (l < r) {
        int mid = (l + r) >> 1;
        push[p + p] = min(push[p + p], push[p]);
        push[p + p + 1] = min(push[p + p + 1], push[p] - (mid + 1 - l));
      } else {
        num[p] = min(num[p], push[p]);
      }
      push[p] = inf;
    }
  }
  void _update(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] = min(push[p], val);
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    _update(p + p, l, mid, ll, rr, val);
    _update(p + p + 1, mid + 1, r, ll, rr, val - max(0, mid + 1 - max(l, ll)));
  }
  int _get(int p, int l, int r, int at) {
    relax(p, l, r);
    if (l == r) return num[p];
    int mid = (l + r) >> 1;
    if (at <= mid) {
      return _get(p + p, l, mid, at);
    } else {
      return _get(p + p + 1, mid + 1, r, at);
    }
  }
  int n;
  vector<int> num;
  vector<int> push;
};

int main() {
  int n;
  scanf("%d", &n);

  segtree_asc asc(n);
  segtree_des des(n);

  // Check for potential dense configurations or overlapping ranges
  vector<int> heights(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &heights[i]);
  }

  // Invariant 1: Check high frequency of updates
  int max_height = *max_element(heights.begin(), heights.end());
  int min_height = *min_element(heights.begin(), heights.end());
  check_high_frequency_updates(max_height - min_height < 5); // Arbitrary small difference threshold

  // Invariant 2: Check for exhaustive range queries
  int same_height_count = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (heights[i] == heights[i + 1]) {
      same_height_count++;
    }
  }
  check_exhaustive_range_queries(same_height_count > n / 2); // More than half have the same height

  // Invariant 3: Check for dense tower configurations
  // (Example threshold: many small towers)
  check_dense_tower_configurations(max_height < 10 && n > 50); // Arbitrary thresholds 

  asc.update(1, n, 1);
  des.update(1, n, n);
  for (int i = 1; i <= n; i++) {
    asc.update(i, n, heights[i-1]);
    des.update(1, i, heights[i-1] + i - 1);
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, min(asc.get(i), des.get(i)));
  }
  cout << ans << endl;
  return 0;
}
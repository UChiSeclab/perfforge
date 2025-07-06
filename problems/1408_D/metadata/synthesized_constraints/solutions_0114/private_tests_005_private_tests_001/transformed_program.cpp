#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const int mod = 0;
const int INF = 2e6 + 10;
pii pr[N], pl[N];
std::vector<pii> v;

struct Seg {
  int l;
  int r;
  int val;
  int lazy;
} seg[(int)4e6 + 10];

// Checker Functions
void check_large_coordinates(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large coordinate values!" << endl;
        abort();
    }
}

void check_dense_segment_operations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to dense segment tree operations!" << endl;
        abort();
    }
}

void check_large_range_iteration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to maximum range iteration!" << endl;
        abort();
    }
}

void build(int id, int l, int r) {
  seg[id].l = l, seg[id].r = r, seg[id].val = 0, seg[id].lazy = -1;
  if (l == r) return;
  int mid = l + r >> 1;
  build(id * 2, l, mid), build(id * 2 + 1, mid + 1, r);
}

void push(int id) {
  if (seg[id].l == seg[id].r || seg[id].lazy == -1) return;
  seg[2 * id].val = max(seg[2 * id].val, seg[id].lazy);
  seg[2 * id].lazy = max(seg[2 * id].lazy, seg[id].lazy);
  seg[2 * id + 1].val = max(seg[2 * id + 1].val, seg[id].lazy);
  seg[2 * id + 1].lazy = max(seg[2 * id + 1].lazy, seg[id].lazy);
  seg[id].lazy = -1;
  return;
}

int query(int id, int l, int r) {
  if (seg[id].l > r || seg[id].r < l) return INF;
  push(id);
  if (seg[id].l >= l && seg[id].r <= r) return seg[id].val;
  return min(query(2 * id, l, r), query(2 * id + 1, l, r));
}

void update(int id, int l, int r, int val) {
  if (seg[id].l > r || seg[id].r < l) return;
  push(id);
  seg[id].val = max(seg[id].val, val);
  if (seg[id].l >= l && seg[id].r <= r) {
    seg[id].lazy = max(seg[id].lazy, val);
    return;
  }
  update(2 * id, l, r, val);
  update(2 * id + 1, l, r, val);
}

int dp[(int)1e6 + 10];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &pr[i].first, &pr[i].second);
  }
  
  // Check for large coordinates
  for (int i = 1; i <= n; i++) {
    check_large_coordinates(pr[i].first >= 900000 || pr[i].second >= 900000);
  }
  
  for (int i = 0; i <= 1e6 + 5; i++) dp[i] = -1;
  int ma = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &pl[i].first, &pl[i].second);
    ma = max(ma, pl[i].second + 1);
    
    // Check for large coordinates for searchlights
    check_large_coordinates(pl[i].first >= 900000 || pl[i].second >= 900000);
  }
  
  build(1, 0, ma);
  
  // Check for dense segment operations
  check_dense_segment_operations(ma > 500000);
  
  sort(pl + 1, pl + m + 1);
  reverse(pl + 1, pl + m + 1);
  v.push_back({1e6 + 10, -1});
  pl[0] = {-1, -1};
  for (int i = 1; i <= m; i++) {
    if (pl[i].second > pl[i - 1].second) v.push_back(pl[i]);
  }
  v.push_back({-1, 1e6 + 10});
  for (int i = 1; i <= n; i++) {
    vector<pii> q;
    for (int j = 1; j < v.size(); j++) {
      pii it = v[j];
      if (it.first < pr[i].first) {
        int y = v[j - 1].second - pr[i].second + 1;
        if (y >= 0) q.push_back({y, 0});
        break;
      }
      if (it.second < pr[i].second) continue;
      int y = max(0, v[j - 1].second - pr[i].second + 1);
      q.push_back({y, it.first - pr[i].first + 1});
    }
    for (int k = 0; k < (int)q.size(); k++) {
      if (k != q.size() - 1)
        update(1, q[k].first, q[k + 1].first - 1, q[k].second);
      else
        update(1, q[k].first, ma, q[k].second);
    }
  }
  
  int mi = 3e6 + 10;
  
  // Check for large range iteration
  check_large_range_iteration(ma >= 900000);
  
  for (int i = 0; i <= ma; i++) {
    mi = min(mi, query(1, i, i) + i);
  }
  printf("%d", mi);
}
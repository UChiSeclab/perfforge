#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long inf = 1000000001;
const long long INF = (long long)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
const long long MOD = 1000000007;
template <typename T1, typename T2>
class LazySegmentTree {
 public:
  using F = function<T1(T1 &, T1 &)>;
  using G = function<T2(T2 &, T2 &)>;
  using H = function<T1(T1 &, T2 &, int, int)>;
  int n;
  vector<T1> node;
  vector<T2> lazy;
  T1 e1;
  T2 e2;
  F query_func;
  G update_func;
  H eval_func;
  LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1,
                  T2 e2)
      : query_func(query_func),
        update_func(update_func),
        eval_func(eval_func),
        e1(e1),
        e2(e2) {
    int _n = a.size();
    n = 1;
    while (n < _n) n *= 2;
    node.resize(2 * n - 1, e1);
    lazy.resize(2 * n - 1, e2);
    for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
    for (int i = n - 2; i >= 0; i--) {
      node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }
  inline void eval(int k, int l, int r) {
    if (lazy[k] != e2) {
      node[k] = eval_func(node[k], lazy[k], l, r);
      if (r - l > 1) {
        lazy[2 * k + 1] = update_func(lazy[2 * k + 1], lazy[k]);
        lazy[2 * k + 2] = update_func(lazy[2 * k + 2], lazy[k]);
      }
      lazy[k] = e2;
    }
  }
  void update(int a, int b, T2 x, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = update_func(lazy[k], x);
      eval(k, l, r);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
    }
  }
  T1 query(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return e1;
    if (a <= l && r <= b) return node[k];
    T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return query_func(resl, resr);
  }
};
pair<long long, long long> f1(pair<long long, long long> a,
                              pair<long long, long long> b) {
  return min(a, b);
}
int g1(int a, int b) { return a + b; }
pair<long long, long long> h1(pair<long long, long long> a, int b, int l,
                              int r) {
  pair<long long, long long> res = a;
  res.first += b;
  return res;
}
template <typename T>
class SegmentTree {
 public:
  using F = function<T(T &, T &)>;
  int n;
  vector<T> dat;
  T e;
  F query_func;
  F update_func;
  SegmentTree(vector<T> a, F query_func, F update_func, T e)
      : n(a.size()), query_func(query_func), update_func(update_func), e(e) {
    if (n == 0) {
      a.push_back(e);
      n++;
    }
    dat.resize(4 * n);
    init(0, 0, n, a);
  }
  void init(int k, int l, int r, vector<T> &a) {
    if (r - l == 1) {
      dat[k] = a[l];
    } else {
      int lch = 2 * k + 1, rch = 2 * k + 2;
      init(lch, l, (l + r) / 2, a);
      init(rch, (l + r) / 2, r, a);
      dat[k] = query_func(dat[lch], dat[rch]);
    }
  }
  void update(int k, T a, int v, int l, int r) {
    if (r - l == 1) {
      dat[v] = update_func(dat[v], a);
    } else {
      if (k < (l + r) / 2)
        update(k, a, 2 * v + 1, l, (l + r) / 2);
      else {
        update(k, a, 2 * v + 2, (l + r) / 2, r);
      }
      dat[v] = query_func(dat[v * 2 + 1], dat[v * 2 + 2]);
    }
  }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return e;
    }
    if (a <= l && r <= b) {
      return dat[k];
    } else {
      T ul = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T ur = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return query_func(ul, ur);
    }
  }
  int find(int a, int b, int k, int l, int r, int x) {
    if (dat[k] < x || r <= a || b <= l) return -1;
    if (l + 1 == r) {
      if (dat[k] >= x)
        return l;
      else
        return -1;
    }
    int rv = find(a, b, 2 * k + 2, (l + r) / 2, r, x);
    if (rv != -1) return rv;
    return find(a, b, 2 * k + 1, l, (l + r) / 2, x);
  }
};
int f(int a, int b) { return a + b; }
int g(int a, int b) { return a + b; }
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<pair<int, int>>> x2yi(n + 1);
  for (int i = 0; i < (int)(q); i++) {
    int x, y;
    cin >> x >> y;
    x2yi[x].push_back(pair<int, int>(y, i));
  }
  vector<pair<long long, long long>> temp(n);
  for (int i = 0; i < (int)(n); i++) {
    temp[i] = pair<int, int>(i - a[i], -i);
    if (temp[i].first < 0) {
      temp[i].first = 2 * inf;
    }
  }
  LazySegmentTree<pair<long long, long long>, int> seg1(
      temp, f1, g1, h1, pair<long long, long long>(3 * inf, 3 * inf), 0);
  SegmentTree<int> seg2(vector<int>(n), f, g, 0);
  vector<int> ans(q);
  for (int x = n; x >= 0; x--) {
    if (x == n) {
      for (pair<int, int> yi : x2yi[x]) {
        ans[yi.second] = 0;
      }
      continue;
    }
    while (true) {
      pair<int, int> mi = seg1.query(x, n, 0, 0, seg1.n);
      if (mi.first != 0) break;
      int idx = -mi.second;
      seg2.update(idx, 1, 0, 0, seg2.n);
      seg1.update(idx, idx + 1, 2 * inf, 0, 0, seg1.n);
      seg1.update(idx, n, -1, 0, 0, seg1.n);
    }
    for (pair<int, int> yi : x2yi[x]) {
      int r = n - yi.first;
      ans[yi.second] = seg2.query(x, r, 0, 0, seg2.n);
    }
  }
  for (int i = 0; i < (int)(q); i++) {
    cout << ans[i] << '\n';
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ;
  int t = 1;
  while (t--) solve();
}

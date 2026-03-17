#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MOD = 1000000000 + 7;
struct Fenwick {
  int n;
  vector<long long> bit;
  Fenwick(int _n) {
    n = _n + 1;
    bit.assign(n + 1, 0);
  }
  void upd(int i, int delta) {
    i++;
    while (i < n + 1) {
      bit[i] += delta;
      i += i & -i;
    }
  }
  long long query(int i) {
    i++;
    long long sum = 0;
    while (i > 0) {
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }
  long long query(int i, int j) { return query(j) - query(i - 1); }
  int lower_bound(long long sum) {
    if (sum < 0) return -1;
    if (sum == 0) return 0;
    int pos = 0;
    for (int pw = 1 << 22; pw; pw >>= 1) {
      if (pos + pw < (int)(bit).size() && bit[pos + pw] < sum)
        pos += pw, sum -= bit[pos];
    }
    if (pos == n) return n - 1;
    return pos;
  }
};
vector<pair<pair<int, int>, int>> h;
vector<pair<int, pair<int, int>>> v;
Fenwick ft = Fenwick(1000005);
vector<vector<int>> active(1000005);
void solve() {
  int n, m;
  cin >> n >> m;
  long long count = 1;
  for (int i = 0; i < (n); ++i) {
    int y, l, r;
    cin >> y >> l >> r;
    if (l == 0 && r == 1000000) count++;
    h.push_back({{l, r}, y});
  }
  h.push_back({{0, 1000000}, 0});
  h.push_back({{0, 1000000}, 1000000});
  for (int i = 0; i < (m); ++i) {
    int x, l, r;
    cin >> x >> l >> r;
    v.push_back({x, {l, r}});
  }
  v.push_back({0, {0, 1000000}});
  sort(begin(v), end(v));
  sort(begin(h), end(h));
  int last_x = 0;
  int last_h_idx = 0;
  for (auto &vertical : v) {
    int x = vertical.first;
    while (last_h_idx < (int)(h).size() && h[last_h_idx].first.first <= x) {
      pair<pair<int, int>, int> horizontal = h[last_h_idx];
      active[horizontal.first.second].push_back(horizontal.second);
      ft.upd(horizontal.second, 1);
      last_h_idx++;
    }
    while (last_x < x) {
      for (auto &yy : active[last_x]) ft.upd(yy, -1);
      active[last_x].clear();
      last_x++;
    }
    if (x != 0) {
      count += ft.query(vertical.second.first, vertical.second.second) - 1;
    }
  }
  cout << count << endl;
}
int main() {
  long long t = 1;
  for (int i = 0; i < (t); ++i) solve();
}

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")
using namespace std;
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T& a, U b) {
  if (a < b) a = b;
}
const int N = 2048;
const int M = N / 2;
const int inf = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> d(m);
  cin >> d;
  int g, r;
  cin >> g >> r;
  sort(d.begin(), d.end());
  vector<vector<int>> gr(m);
  for (int i = 0; i < m; ++i) {
    gr[i].reserve(g + 5);
  }
  auto calc = [&](int i) {
    bitset<N> mask = 0;
    int ind = i;
    while (ind >= 0) {
      if (d[i] - d[ind] <= g)
        mask[M - (d[i] - d[ind])] = 1;
      else
        break;
      --ind;
    }
    ind = i;
    while (ind < m) {
      if (d[ind] - d[i] <= g)
        mask[M + (d[ind] - d[i])] = 1;
      else
        break;
      ++ind;
    }
    bitset<N> gol = 0, gor = 0;
    gol[M] = 1;
    gor[M] = 1;
    for (int i = 0; i < g; ++i) {
      gor <<= 1;
      gol >>= 1;
      gor |= (gol & mask);
      gol |= (gor & mask);
    }
    mask &= (gol | gor);
    ind = i + 1;
    while (ind < m) {
      if (d[ind] - d[i] <= g) {
        if ((mask[M + (d[ind] - d[i])])) gr[i].push_back(ind);
      } else {
        break;
      }
      ++ind;
    }
  };
  vector<int> dist(m, inf);
  dist[0] = 0;
  for (int i = 0; i < m; ++i) {
    if (dist[i] != inf) {
      calc(i);
      for (auto k : gr[i]) {
        dist[k] = min(dist[k], dist[i] + 1);
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < m; ++i) {
    if (dist[i] == inf) continue;
    if (d[i] + g >= n) {
      if (ans == -1 || ans > dist[i] * (r + g) + (n - d[i]))
        ans = dist[i] * (r + g) + (n - d[i]);
    }
  }
  cout << ans << endl;
  return 0;
}

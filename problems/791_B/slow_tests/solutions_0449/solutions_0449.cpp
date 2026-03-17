#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
struct dsu {
  int *parent;
  int *size;
  void init(int n) {
    parent = new int[n];
    size = new int[n];
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int p(int x) {
    if (parent[x] == x) return x;
    return parent[x] = p(parent[x]);
  }
  void unite(int x, int y) {
    int supx = p(x);
    int supy = p(y);
    if (supx != supy) {
      if (size[x] > size[y]) {
        parent[supy] = supx;
        size[supx] += size[supy];
      } else {
        parent[supx] = supy;
        size[supy] += size[supx];
      }
    }
  }
};
unordered_map<int, vector<int>> o, l;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m, x, y;
  cin >> n >> m;
  dsu d;
  d.init(n);
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    x--;
    y--;
    o[x].push_back(y);
    o[y].push_back(x);
    d.unite(x, y);
  }
  for (int i = 0; i < n; ++i) {
    x = d.p(i);
    l[x].push_back(i);
  }
  for (auto i : l) {
    vector<int> v = i.second;
    for (auto j : i.second) {
      for (auto k : i.second) {
        if (k != j) {
          auto it = find(o[k].begin(), o[k].end(), j);
          if (it == o[k].end()) {
            cout << "NO";
            return 0;
          }
        }
      }
    }
  }
  cout << "YES";
  return 0;
}

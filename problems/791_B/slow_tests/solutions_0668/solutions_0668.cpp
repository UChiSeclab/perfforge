#include <bits/stdc++.h>
using namespace std;
class UnionFind {
 private:
  vector<int> p, r;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      r.push_back(0);
      p.push_back(i);
    }
  }
  int findSet(int n) { return p[n] != n ? (p[n] = findSet(p[n])) : n; }
  void merge(int x, int y) {
    int s1 = findSet(x);
    int s2 = findSet(y);
    if (s1 != s2) {
      if (r[s1] > r[s2]) {
        p[s2] = s1;
      } else {
        p[s1] = s2;
        if (r[s2] == r[s1]) {
          r[s2]++;
        }
      }
    }
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  vector<vector<int> > ma(n + 1);
  UnionFind uf(n + 1);
  vector<int> c(n + 1);
  for (int i = 0; i <= n; i++) {
    c[i] = 0;
  }
  while (m--) {
    cin >> a >> b;
    uf.merge(a, b);
    c[a]++;
    c[b]++;
  }
  for (int i = 1; i <= n; i++) {
    ma[uf.findSet(i)].push_back(i);
  }
  for (auto li : ma) {
    if (li.size() >= 3) {
      for (auto node : li) {
        if (c[node] != li.size() - 1) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}

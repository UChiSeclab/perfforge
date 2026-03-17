#include <bits/stdc++.h>
using namespace std;
template <class T>
istream &operator>>(istream &is, vector<T> &a) {
  for (int i = 0; i < a.size(); ++i) is >> a[i];
  return is;
}
vector<int> p, s;
set<int> par;
int get(int v) { return (p[v] == v) ? v : (p[v] = get(p[v])); }
void unite(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) return;
  if (s[a] < s[b]) swap(a, b);
  p[b] = a;
  s[a] += s[b];
  par.erase(b);
  par.insert(a);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  p.resize(n), s.resize(n);
  vector<vector<int> > g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (a < b) swap(a, b);
    g[a].push_back(b);
  }
  for (int v = 0; v < n; ++v) {
    p[v] = v, s[v] = 1;
    par.insert(v);
    map<int, int> cnt;
    for (int u : g[v]) ++cnt[get(u)];
    set<int> bb(par.begin(), par.end());
    for (int u : bb)
      if (u != v && cnt[u] < s[u]) unite(u, v);
  }
  cout << par.size() - 1;
}

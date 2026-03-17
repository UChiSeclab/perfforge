#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
vector<long long> v, r;
long long find_set(long long);
void union_set(long long x, long long y) {
  x = find_set(x);
  y = find_set(y);
  if (x != y) {
    if (r[x] > r[y]) {
      r[x] += r[y];
      v[y] = x;
    } else {
      r[y] += r[x];
      v[x] = y;
    }
  }
}
long long find_set(long long x) {
  if (v[x] == -1) return x;
  return v[x] = find_set(v[x]);
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n);
  vector<long long> b(n, -1), c(n, 1);
  g = a;
  v = b;
  r = c;
  for (long long x, y, i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
    union_set(x, y);
  }
  unordered_map<long long, vector<long long>> se;
  for (long long i = 0; i < n; i++)
    if (v[i] == -1) {
      vector<long long> v;
      se[i] = v;
    }
  for (long long i = 0; i < n; i++)
    if (v[i] != -1) se[v[i]].push_back(i);
  bool k = 1;
  for (auto x : se) {
    long long a = ((x.second.empty()) ? 0 : (x.second.size()));
    if (a)
      for (auto y : x.second)
        if (g[y].size() != a) {
          k = 0;
          break;
        }
    if (!k) break;
  }
  if (k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

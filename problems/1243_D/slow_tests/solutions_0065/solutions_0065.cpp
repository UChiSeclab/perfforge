#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  map<pair<int, int>, bool> vis;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    vis[{u, v}] = 1;
    vis[{v, u}] = 1;
  }
  set<int> st;
  for (int i = 1; i <= n; i++) st.insert(i);
  vector<int> cur, New;
  while (!st.empty()) {
    if (New.empty()) {
      ans++;
      New.push_back(*st.begin());
    }
    for (auto v : New) st.erase(v);
    cur.swap(New);
    New.clear();
    for (auto v : st) {
      for (auto u : cur) {
        if (vis[{u, v}]) continue;
        New.push_back(v);
        break;
      }
    }
  }
  cout << ans - 1 << endl;
  return 0;
}

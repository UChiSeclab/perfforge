#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
set<int> s;
void dfs(int x) {
  vector<int> vec;
  for (int i : s) {
    if (mp[{x, i}] == 0) {
      vec.push_back(i);
    }
  }
  for (int i : vec) {
    s.erase(i);
  }
  for (int i : vec) {
    dfs(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    mp[{u, v}] = 1;
    mp[{v, u}] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s.size()) {
      v = *s.begin();
      ans++;
      s.erase(v);
      dfs(v);
    } else
      break;
  }
  cout << ans - 1 << "\n";
  return 0;
}

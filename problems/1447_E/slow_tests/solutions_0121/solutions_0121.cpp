#include <bits/stdc++.h>
using namespace std;
int dfs(set<int> s, int t) {
  if (s.empty()) return 0;
  if (s.size() == 1) return 1;
  set<int> sd[2];
  for (int si : s) sd[si >> t & 1].insert(si);
  return max(dfs(sd[0], t - 1) + min((int)sd[1].size(), 1),
             dfs(sd[1], t - 1) + min((int)sd[0].size(), 1));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    s.insert(b);
  }
  cout << n - dfs(s, 29) << "\n";
  return 0;
}

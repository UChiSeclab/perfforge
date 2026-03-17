#include <bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_map<int, bool> > m;
int n, ma;
set<int> visited;
void DFS(int v) {
  if (visited.find(v) != visited.end()) visited.erase(visited.find(v));
  int cur = -1;
  while (1) {
    auto itx = visited.upper_bound(cur);
    if (itx == visited.end()) break;
    cur = *itx;
    if (m[v][*itx] == 1) continue;
    DFS(*itx);
  }
}
int main() {
  cin >> n >> ma;
  for (int i = 1; i <= ma; i++) {
    int a, b;
    cin >> a >> b;
    m[a][b] = 1;
    m[b][a] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    visited.insert(i);
  }
  int cur = -1;
  while (1) {
    auto itr = visited.upper_bound(cur);
    if (itr == visited.end()) break;
    DFS(*itr);
    cnt++;
  }
  cout << max(cnt - 1, 0);
}

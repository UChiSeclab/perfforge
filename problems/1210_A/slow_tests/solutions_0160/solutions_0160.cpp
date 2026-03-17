#include <bits/stdc++.h>
using namespace std;
int n, m;
int node[8];
vector<vector<int>> gr;
int countDom() {
  int dom[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) dom[i][j] = 0;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int v : gr[i]) {
      if (!dom[node[i]][node[v]]) {
        dom[node[i]][node[v]] = dom[node[v]][node[i]] = 1;
        ans++;
      }
    }
  }
  if (ans == 21) {
    for (int i = 0; i < n; i++) {
      cout << node[i] << " ";
    }
    cout << "\n";
  }
  return ans;
}
int solve() {
  int ans = 0;
  while (node[1] != 2) {
    int i = 7;
    ans = max(ans, countDom());
    while (++node[i] == 7) {
      node[i--] = 1;
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < 8; i++) node[i] = 1;
  gr.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  cout << solve();
  cin >> n;
  return 0;
}

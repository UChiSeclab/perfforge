#include <bits/stdc++.h>
using namespace std;
int n, m, res = 0;
vector<int> a[101];
int c[101];
bool b[101][101], visited[100];
void reset() {
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      b[i][j] = false;
    }
    visited[i] = false;
  }
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
}
int bfs(int u) {
  int coun = 0;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto i : a[u]) {
      if (!b[c[u]][c[i]]) {
        b[c[u]][c[i]] = true;
        b[c[i]][c[u]] = true;
        if (!visited[i]) q.push(i);
        visited[i] = true;
        coun++;
      }
    }
  }
  return coun;
}
void backtrack(int i) {
  for (int j = 1; j <= 6; j++) {
    c[i] = j;
    if (i < n) backtrack(i + 1);
    if (i == n) {
      int ans = 0;
      reset();
      for (int k = 1; k <= n; k++) {
        if (!visited[k]) {
          ans += bfs(k);
        }
      }
      res = max(res, ans);
    }
  }
}
void solve() {
  backtrack(1);
  cout << res;
}
int main() {
  reset();
  input();
  solve();
  return 0;
}

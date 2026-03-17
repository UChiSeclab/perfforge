#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int y, vector<vector<int> >& g, vector<vector<bool> >& used,
         int& ans, vector<int>& kek) {
  if (g[y][x + 1] == -1) ans++;
  if (g[y][x - 1] == -1) ans++;
  if (g[y + 1][x] == -1) ans++;
  if (g[y - 1][x] == -1) ans++;
  used[y][x] = true;
  kek.push_back(y);
  kek.push_back(x);
  if (g[y][x + 1] == 0 && (!used[y][x + 1])) dfs(x + 1, y, g, used, ans, kek);
  if (g[y][x - 1] == 0 && (!used[y][x - 1])) dfs(x - 1, y, g, used, ans, kek);
  if (g[y + 1][x] == 0 && (!used[y + 1][x])) dfs(x, y + 1, g, used, ans, kek);
  if (g[y - 1][x] == 0 && (!used[y - 1][x])) dfs(x, y - 1, g, used, ans, kek);
}
int main() {
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  vector<vector<int> > g(n, vector<int>(m));
  vector<vector<bool> > used(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if (ch == '.') {
        g[i][j] = 0;
      } else {
        g[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> y >> x;
    x--;
    y--;
    if (!used[y][x]) {
      vector<int> kek;
      dfs(x, y, g, used, ans, kek);
      cout << ans << endl;
      for (int j = 1; j < kek.size(); j += 2) {
        g[kek[j - 1]][kek[j]] = ans;
      }
      kek.clear();
      ans = 0;
    } else {
      cout << g[y][x] << endl;
    }
  }
}

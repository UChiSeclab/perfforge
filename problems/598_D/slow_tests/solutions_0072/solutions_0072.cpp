#include <bits/stdc++.h>
using namespace std;
char graph[1005][1005];
int cc[1005][1005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visited[1005][1005];
vector<pair<int, int> > curr;
int dfs(int i, int j) {
  if (graph[i][j] == '*' || visited[i][j]) return 0;
  visited[i][j] = true;
  int count = 0;
  curr.push_back(make_pair(i, j));
  for (int idx = 0; idx < 4; ++idx) {
    if (graph[i + dx[idx]][j + dy[idx]] == '*')
      count++;
    else if (graph[i + dx[idx]][j + dy[idx]] == '.')
      count += dfs(i + dx[idx], j + dy[idx]);
  }
  return count;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> graph[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (cc[i][j] != 0) continue;
      int tot = dfs(i, j);
      for (int k = 0; k < curr.size(); ++k) {
        cc[curr[k].first][curr[k].second] = tot;
      }
      curr.clear();
    }
  }
  while (k--) {
    int a, b;
    cin >> a >> b;
    cout << cc[a - 1][b - 1] << endl;
  }
  return 0;
}

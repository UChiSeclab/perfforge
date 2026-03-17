#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int n, m, k, last_number = 1;
unordered_map<int, int> ans;
bool inside(int y, int x) {
  if (y < 0 || y >= n || x < 0 || x >= m) return 0;
  return 1;
}
int bfs(int y, int x) {
  int walls = 0;
  queue<pair<int, int>> q;
  q.push({y, x});
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    if (arr[y][x] != -1) continue;
    arr[y][x] = last_number;
    for (int dr : {-1, 0, 1}) {
      for (int dc : {-1, 0, 1}) {
        if (abs(dr) == abs(dc)) continue;
        int new_row = y + dr;
        int new_col = x + dc;
        if (inside(new_row, new_col) && arr[new_row][new_col] == 0)
          walls++;
        else if (inside(new_row, new_col) && arr[new_row][new_col] == -1)
          q.push({new_row, new_col});
      }
    }
  }
  ans[last_number] = walls;
  last_number++;
  return walls;
}
int main() {
  cin >> n >> m >> k;
  arr = vector<vector<int>>(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < m; j++)
      if (x[j] == '*') arr[i][j] = 0;
  }
  while (k--) {
    int y, x;
    cin >> y >> x;
    y--, x--;
    if (ans.find(arr[y][x]) != ans.end())
      cout << ans[arr[y][x]] << endl;
    else
      cout << bfs(y, x) << endl;
  }
  return 0;
}

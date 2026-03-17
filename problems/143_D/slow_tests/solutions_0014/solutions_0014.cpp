#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isvalid(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    return true;
  }
  return false;
}
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int main() {
  cin >> n >> m;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<int>> col(n, vector<int>(m, -1));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        col[i][j] = 0;
        int co = 0, cz = 1;
        while (!q.empty()) {
          pair<int, int> temp = q.front();
          q.pop();
          int x = temp.first;
          int y = temp.second;
          for (int k = 0; k < 8; k++) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if (isvalid(nx, ny) && !vis[nx][ny]) {
              vis[nx][ny] = true;
              q.push({nx, ny});
              col[nx][ny] = col[x][y] ^ 1;
              if (col[nx][ny])
                co++;
              else
                cz++;
            }
          }
        }
        ans += max(co, cz);
      }
    }
  }
  cout << ans << endl;
}

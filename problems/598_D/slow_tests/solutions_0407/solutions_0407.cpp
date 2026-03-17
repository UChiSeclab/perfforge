#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<string> museum;
vector<vector<int> > pictures;
vector<vector<bool> > used;
queue<pair<int, int> > line;
vector<pair<int, int> > req;
void BFS(int& i, int& j) {
  line.push(make_pair(i, j));
  used[i][j] = true;
  int cnt = 0;
  req.clear();
  while (!line.empty()) {
    int x = line.front().first;
    int y = line.front().second;
    line.pop();
    req.push_back(make_pair(x, y));
    for (int z = 0; z < 4; z++) {
      int newI = x + dx[z];
      int newJ = y + dy[z];
      if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
          museum[newI][newJ] == '*') {
        cnt++;
      }
    }
    for (int z = 0; z < 4; z++) {
      int newI = x + dx[z];
      int newJ = y + dy[z];
      if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
          museum[newI][newJ] == '.' && !used[newI][newJ]) {
        used[newI][newJ] = true;
        line.push(make_pair(newI, newJ));
      }
    }
  }
  for (int z = 0; z < req.size(); z++) {
    pictures[req[z].first][req[z].second] = cnt;
  }
}
int main() {
  cin >> n >> m >> k;
  museum.resize(n);
  used.resize(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    cin >> museum[i];
  }
  pictures.resize(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (museum[i][j] == '.' && pictures[i][j] == -1) {
        BFS(i, j);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    printf("%d\n", pictures[x][y]);
  }
  return 0;
}

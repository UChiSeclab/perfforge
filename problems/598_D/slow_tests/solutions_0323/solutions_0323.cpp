#include <bits/stdc++.h>
using namespace std;
int n, m;
int st, en;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<string> v;
int cell[1005][1005], visited[1005][1005];
bool valid(int xx, int yy) {
  if (xx >= 0 && yy >= 0 && xx < n && yy < m && v[xx][yy] != '*') return 1;
  return 0;
}
int bfs() {
  int wx, wy, ans = 0;
  vector<pair<int, int> > vaa;
  queue<pair<int, int> > Q;
  Q.push(make_pair(st, en));
  visited[st][en] = 1;
  while (!Q.empty()) {
    st = Q.front().first;
    en = Q.front().second;
    vaa.push_back(make_pair(st, en));
    Q.pop();
    for (int i = 0; i < 4; i++) {
      wx = st + dx[i];
      wy = en + dy[i];
      if (!valid(wx, wy)) ans++;
      if (valid(wx, wy) && !visited[wx][wy]) {
        visited[wx][wy] = 1;
        Q.push(pair<int, int>(wx, wy));
      }
    }
  }
  for (int i = 0; i < vaa.size(); i++) cell[vaa[i].first][vaa[i].second] = ans;
  return ans;
}
int main() {
  int k;
  string s;
  cin >> n >> m >> k;
  memset(cell, -1, sizeof(cell));
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  while (k--) {
    cin >> st >> en;
    st--;
    en--;
    if (cell[st][en] != -1)
      cout << cell[st][en] << '\n';
    else
      cout << bfs() << '\n';
  }
  return 0;
}

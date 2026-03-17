#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > v;
void bfs(int start) {
  int n = v.size();
  queue<int> q;
  q.push(start);
  vector<bool> used(n);
  used[start] = true;
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (v[tmp][i]) {
        if (used[i])
          count++;
        else
          q.push(i);
        used[i] = true;
      }
    }
    if (count > 1) {
      cout << "no";
      return;
    }
  }
  if (find(used.begin(), used.end(), false) != used.end())
    cout << "no";
  else
    cout << "yes";
}
int main() {
  int n, m;
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x - 1][y - 1] = v[y - 1][x - 1] = true;
  }
  bfs(0);
}

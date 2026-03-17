#include <bits/stdc++.h>
using namespace std;
int a, b;
map<int, bool> vis;
int bfs() {
  queue<pair<int, int> > q;
  q.push(make_pair(a, 0));
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    vis[cur.first] = 1;
    if (cur.first == b) {
      return cur.second;
    }
    if (!vis[cur.first * 2] && cur.first <= b)
      q.push(make_pair(cur.first * 2, cur.second + 1));
    if (!vis[cur.first - 1]) q.push(make_pair(cur.first - 1, cur.second + 1));
  }
}
int main() {
  cin >> a >> b;
  cout << bfs() << endl;
  return 0;
}

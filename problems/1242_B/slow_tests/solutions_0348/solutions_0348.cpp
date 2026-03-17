#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << ", ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << ", ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
int n, m;
map<pair<int, int>, bool> edge;
set<int> node;
vector<bool> visited(200005, false);
void bfs(int s) {
  queue<int> q;
  q.push(s);
  vector<int> temp;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    visited[v] = true;
    temp.clear();
    for (int u : node) {
      if (!edge[{u, v}] && !visited[u]) {
        temp.push_back(u);
      }
    }
    for (int u : temp) {
      node.erase(u);
      q.push(u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    node.insert(i);
  }
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    edge[{x, y}] = 1;
    edge[{y, x}] = 1;
  }
  int cnt = 0;
  for (int start = 0; start < n; start++) {
    if (!visited[start]) {
      node.erase(start);
      bfs(start);
      cnt++;
    }
    if (node.empty()) break;
  }
  cout << cnt - 1 << endl;
}

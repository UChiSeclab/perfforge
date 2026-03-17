#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> edges;
set<int> vertex;
vector<int> comp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, u, v, cnt;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    vertex.insert(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    edges[{u, v}] = 1;
    edges[{v, u}] = 1;
  }
  while (!vertex.empty()) {
    u = *vertex.begin();
    cnt = 1;
    vertex.erase(vertex.begin());
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
      v = q.front();
      q.pop();
      auto itr = vertex.begin();
      while (itr != vertex.end()) {
        bool found = false;
        if (!edges[{*itr, v}]) {
          found = true;
        }
        if (found) {
          q.push(*itr);
          cnt++;
          itr = vertex.erase(itr);
        } else {
          itr++;
        }
      }
    }
    comp.push_back(cnt);
  }
  cout << comp.size() - 1 << endl;
}

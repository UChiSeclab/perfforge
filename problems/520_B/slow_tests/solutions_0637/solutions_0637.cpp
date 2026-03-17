#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
using namespace std;
int n, m;
struct node {
  int x, num;
} ne, pos;
int bfs() {
  queue<node> q;
  map<int, int> mp;
  mp[n] = 1;
  ne.x = n;
  ne.num = 0;
  q.push(ne);
  while (!q.empty()) {
    pos = q.front();
    q.pop();
    if (pos.x == m) return pos.num;
    ne.num = pos.num + 1;
    ne.x = pos.x * 2;
    if (ne.x <= maxn && mp[ne.x] == 0) {
      mp[ne.x] = 1;
      q.push(ne);
    }
    ne.x = pos.x - 1;
    if (ne.x >= 0 && mp[ne.x] == 0) {
      mp[ne.x] = 1;
      q.push(ne);
    }
  }
  return 0;
}
int main() {
  int ans;
  while (~scanf("%d%d", &n, &m)) {
    ans = bfs();
    cout << ans << endl;
  }
  return 0;
}

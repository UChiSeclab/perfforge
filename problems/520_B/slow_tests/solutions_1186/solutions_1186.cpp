#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int x, y;
int dis[N];
void dfs(int now, int d) {
  if (dis[now] <= d) return;
  dis[now] = d;
  if (now >= y) {
    dis[y] = min(dis[y], d + now - y);
    return;
  }
  dfs(now * 2, d + 1);
  if (now > 1) dfs(now - 1, d + 1);
}
int main() {
  cin >> x >> y;
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  dfs(x, 0);
  cout << dis[y] << endl;
  return 0;
}

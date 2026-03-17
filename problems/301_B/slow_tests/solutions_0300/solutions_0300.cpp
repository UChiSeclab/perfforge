#include <bits/stdc++.h>
using namespace std;
int a[102], x[102], y[102];
int n, d;
bool vis[102];
int dist(int a, int b) { return abs(x[a] - x[b]) + abs(y[a] - y[b]); }
bool first(long long val) {
  priority_queue<pair<long long, int> > q;
  q.push(make_pair(val, 1));
  memset(vis, false, sizeof(vis));
  while (!q.empty()) {
    pair<long long, int> now = q.top();
    q.pop();
    if (vis[now.second]) continue;
    vis[now.second] = true;
    if (now.second == n) return true;
    for (int i = 1; i <= n; i++) {
      if (now.first >= d * dist(now.second, i))
        q.push(make_pair(now.first - d * dist(now.second, i) + a[i], i));
    }
  }
  return false;
}
int main() {
  int i, j;
  scanf("%d", &n);
  scanf("%d", &d);
  for (i = 2; i < n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
  }
  long long lo = 0, hi = (long long)1e15;
  while (hi - lo > 1) {
    long long mid = (hi + lo) / 2;
    if (first(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << hi << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  for (long long tt = 1; tt <= T; tt++) {
    int n, mn = 1e9;
    cin >> n;
    n *= 2;
    vector<int> ls(n);
    for (int &x : ls) cin >> x;
    sort(ls.begin(), ls.end());
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (v != u) {
          map<int, int> vis;
          vis[u] = vis[v] = 1;
          int w = 0, x = 0, sm = 0;
          while (x < n) {
            while (vis[w]) w++;
            while (vis[x] || x == w) x++;
            if (x < n) sm += ls[x] - ls[w], vis[w] = vis[x] = 1;
            w++, x++;
          }
          mn = min(mn, sm);
        }
      }
    }
    cout << mn;
    cout << '\n';
  }
}

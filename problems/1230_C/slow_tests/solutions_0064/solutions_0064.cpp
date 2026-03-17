#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const long long base = 1000000007LL;
const int N = 105;
int n, m, a[8], res = 0;
pair<int, int> edge[30];
void Try(int x) {
  if (x > n) {
    set<pair<int, int> > S;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      u = a[edge[i].first];
      v = a[edge[i].second];
      if (u > v) swap(u, v);
      S.insert(make_pair(u, v));
    }
    res = max(res, (int)S.size());
    return;
  }
  for (int i = 1; i <= 6; ++i) {
    a[x] = i;
    Try(x + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> edge[i].first >> edge[i].second;
  Try(1);
  cout << res;
  return 0;
}

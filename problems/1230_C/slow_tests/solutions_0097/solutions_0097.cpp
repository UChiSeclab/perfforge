#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)1e18 + 10;
map<pair<long long int, long long int>, long long int> m;
vector<pair<long long int, long long int> > v;
long long int ans = 0;
long long int val[10];
void dfs(long long int x) {
  for (long long int i = 1; i <= 6; i++) {
    val[x] = i;
    if (x != 1)
      dfs(x - 1);
    else {
      long long int cnt = 0;
      for (long long int j = 0; j < v.size(); j++) {
        long long int f = v[j].first, t = v[j].second;
        if (m.find({val[f], val[t]}) == m.end())
          m[{val[f], val[t]}] = 1, m[{val[t], val[f]}] = 1, cnt++;
      }
      ans = max(ans, cnt);
      m.clear();
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, me, x, y;
  cin >> n >> me;
  for (long long int i = 1; i <= me; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  dfs(n);
  cout << ans << endl;
}

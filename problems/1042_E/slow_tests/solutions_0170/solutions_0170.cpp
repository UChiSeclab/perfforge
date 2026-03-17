#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1007][1007];
long long f[1007][1007], sumx = 0, sumsq = 0, cur = 0, sumdp = 0, sumy = 0;
vector<pair<int, pair<int, int> > > st;
long long ans = 0;
const long long mod = 998244353;
long long pw(long long x, long long y) {
  if (y == 0) return 1LL;
  if (y == 1) return x;
  long long ret = pw(x, y / 2);
  if (y % 2 == 0)
    return ret * ret % mod;
  else
    return ret * ret % mod * x % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      st.push_back(make_pair(a[i][j], make_pair(i, j)));
    }
  }
  sort(st.begin(), st.end());
  for (int i = 0; i < (int)st.size(); i++) {
    long long val = st[i].first, x = st[i].second.first,
              y = st[i].second.second;
    while (cur < i && st[cur].first < val) {
      sumdp = (sumdp + f[st[cur].second.first][st[cur].second.second]) % mod;
      sumsq = ((sumsq + st[cur].second.second * st[cur].second.second) % mod +
               st[cur].second.first * st[cur].second.first) %
              mod;
      sumx = (sumx + st[cur].second.first) % mod;
      sumy = (sumy + st[cur].second.second) % mod;
      cur++;
    }
    if (cur == 0) {
      f[x][y] = 0;
      continue;
    }
    f[x][y] =
        ((((((sumdp + sumsq) % mod + cur * x * x) % mod) + cur * y * y) % mod -
          (2LL * x * sumx % mod) + mod) %
             mod -
         (2LL * y * sumy % mod) + mod) %
        mod;
    f[x][y] = (f[x][y] * pw(cur, mod - 2)) % mod;
  }
  int px = 0, py = 0;
  cin >> px >> py;
  cout << f[px][py];
}

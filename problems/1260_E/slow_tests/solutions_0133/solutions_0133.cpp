#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = (1 << 30) - 1, mod = 998244353;
int solve(vector<pair<int, int> > v) {
  int ret = 0;
  while (v.size() != 1) {
    vector<pair<int, int> > tmp;
    for (int i = 0; i < v.size(); i += 2) {
      if (v[i].first == -1) {
        tmp.push_back(v[i]);
        if (v[i + 1].second > v[i].second) ret += v[i + 1].first;
      } else if (v[i + 1].first == -1) {
        tmp.push_back(v[i + 1]);
        if (v[i].second > v[i + 1].second) ret += v[i].first;
      } else {
        if (v[i].second > v[i + 1].second)
          tmp.push_back(v[i]);
        else
          tmp.push_back(v[i + 1]);
      }
    }
    v = tmp;
  }
  return ret;
}
vector<pair<int, int> > cu;
int stress(vector<pair<int, int> > v) {
  int mn = 1e9;
  do {
    if (solve(v) < mn) {
      mn = solve(v);
      cu = v;
    }
  } while (next_permutation(v.begin(), v.end()));
  return mn;
}
vector<int> s;
long long z[20], dp[int(1 << 18) + 5][20], m;
long long solve(int idx, int p) {
  if (idx >= m) return 0;
  long long &ret = dp[idx][p];
  if (~ret) return ret;
  ret = 1e18;
  if (idx < z[p]) ret = min(ret, solve(idx + 1, p));
  ret = min(ret, solve(idx + 1, p + 1) + s[idx]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(time(0));
  s.clear();
  memset(dp, -1, sizeof dp);
  int n = 8;
  cin >> n;
  vector<pair<int, int> > v, vv;
  bool bo = 0;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    vv.push_back({x, i});
    a.push_back(x);
    if (bo) v.push_back({x, i}), s.push_back(x);
    if (x == -1) bo = 1;
  }
  reverse(s.begin(), s.end());
  m = s.size();
  z[0] = 0;
  for (int i = 1; i < 20; i++) z[i] = n / (1 << i), z[i] += z[i - 1];
  sort(v.begin(), v.end());
  sort(vv.begin(), vv.end());
  int cur, c = n / 2;
  long long ans = 0;
  ans = solve(0, 0);
  cout << ans;
  return 0;
}

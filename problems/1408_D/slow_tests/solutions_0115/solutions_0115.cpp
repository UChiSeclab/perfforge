#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> P(n);
  vector<pair<int, int>> Q(m);
  for (int i = (int)(0); i < (int)(n); i++) cin >> P[i].first >> P[i].second;
  for (int i = (int)(0); i < (int)(m); i++) cin >> Q[i].first >> Q[i].second;
  set<pair<int, int>> st;
  for (int i = (int)(0); i < (int)(n); i++)
    for (int j = (int)(0); j < (int)(m); j++) {
      int x = Q[j].first - P[i].first;
      int y = Q[j].second - P[i].second;
      if (x < 0 || y < 0) continue;
      st.insert({x, y});
    }
  multiset<long long> mostR;
  for (auto ele : st) mostR.insert(ele.second);
  int ans = inf;
  for (int i = 0; i <= 1000005; i++) {
    if (mostR.empty()) {
      chmin(ans, i);
      break;
    } else {
      chmin(ans, i + *mostR.rbegin() + 1);
    }
    for (auto itr = st.lower_bound({i, 0}); itr != st.upper_bound({i, inf});
         itr++) {
      mostR.erase(mostR.find(itr->second));
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while (T--) solve();
  return 0;
}

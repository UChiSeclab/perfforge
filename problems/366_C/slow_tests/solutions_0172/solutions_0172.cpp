#include <bits/stdc++.h>
using namespace std;
const int N = 110;
set<int> sve;
map<int, int> dp;
int a[N], b[N], n, k;
vector<pair<int, int> > v;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] *= k;
  }
  for (int i = 1; i <= n; i++) {
    v.clear();
    for (auto it : sve) {
      int sum = it;
      v.push_back(make_pair(sum + a[i] - b[i], dp[sum] + a[i]));
    }
    for (int j = 0; j < v.size(); j++) {
      int best = dp[v[j].first];
      best = max(best, v[j].second);
      dp[v[j].first] = best;
      sve.insert(v[j].first);
    }
    if (sve.find(a[i] - b[i]) == sve.end()) {
      sve.insert(a[i] - b[i]);
      dp[a[i] - b[i]] = a[i];
    } else {
      int best = dp[a[i] - b[i]];
      best = max(best, a[i]);
      dp[a[i] - b[i]] = best;
    }
  }
  if (dp.count(0) == 0)
    cout << "-1";
  else
    cout << dp[0];
  return 0;
}

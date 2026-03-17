#include <bits/stdc++.h>
using namespace std;
struct soldier {
  long long location;
  long long disarm;
  long long danger;
};
vector<soldier> soldiers;
long long m, n, k, t;
bool success(long long agility) {
  const long long START = 0;
  const long long END = 1;
  vector<pair<long long, long long>> intervals;
  for (long long i = 0; i < k; i++) {
    struct soldier s = soldiers[i];
    if (s.danger > agility) {
      intervals.push_back(make_pair(s.location, START));
      intervals.push_back(make_pair(s.disarm, END));
    }
  }
  sort(intervals.begin(), intervals.end());
  long long result = 0;
  long long Counter = 0;
  for (unsigned i = 0; i < intervals.size(); i++) {
    if (Counter == 0) result++;
    if (Counter) result += (intervals[i].first - intervals[i - 1].first);
    (intervals[i].second) ? Counter-- : Counter++;
  }
  long long totaltime = n + 1 + 2 * result;
  return totaltime <= t;
}
signed main() {
  cin >> m >> n >> k >> t;
  vector<long long> a(m, 0);
  long long maxAgil = 0;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    maxAgil = max(maxAgil, a[i]);
  }
  for (long long i = 0; i < k; i++) {
    long long location, disarm, danger;
    cin >> location >> disarm >> danger;
    soldiers.push_back(
        {.location = location, .disarm = disarm, .danger = danger});
  }
  long long l = 0, r = maxAgil, mid, ans = 1e9;
  while (l <= r) {
    mid = (l + r) / 2;
    if (success(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  long long pass = 0;
  for (long long i = 0; i < m; i++) {
    if (a[i] >= ans) {
      pass++;
    }
  }
  cout << pass;
}

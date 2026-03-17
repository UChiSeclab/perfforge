#include <bits/stdc++.h>
using namespace std;
pair<double, double> middle(pair<double, double> a, pair<double, double> b) {
  return make_pair((a.first + b.first) / 2, (b.second + a.second) / 2);
}
signed main() {
  long long n;
  cin >> n;
  vector<pair<double, double> > v(n);
  set<pair<double, double> > points;
  for (long long i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second, points.insert(v[i]);
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      res += points.count(middle(v[i], v[j]));
    }
  }
  cout << res << endl;
  return 0;
}

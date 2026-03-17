#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j;
  cin >> n;
  vector<pair<double, double> > v(n);
  map<pair<double, double>, long long> mp;
  for (i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    mp[{a, b}] = i;
    v[i] = {a, b};
  }
  long long ans = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      double a = (v[i].first + v[j].first) / 2.0;
      double b = (v[i].second + v[j].second) / 2.0;
      if (mp.find({a, b}) != mp.end()) {
        long long c = mp[{a, b}];
        if (c != i && c != j) ans++;
      }
    }
  }
  cout << ans;
}

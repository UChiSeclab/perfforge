#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
set<pair<float, float> > s;
float x[3010], y[3010];
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    s.insert({x[i], y[i]});
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i == j) continue;
      float tmpx = (x[i] + x[j]) / 2, tmpy = (y[i] + y[j]) / 2;
      if (s.find({tmpx, tmpy}) != s.end()) {
        ans++;
      }
    }
  }
  cout << ans;
}

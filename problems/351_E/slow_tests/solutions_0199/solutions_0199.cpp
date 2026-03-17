#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(10);
  int t = 1;
  while (t--) solve();
  return 0;
}
vector<int> v[101010];
bool res[101010];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v[abs(a)].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i <= 100005; ++i) {
    int allHave = 0;
    for (int j = 0; j < n; ++j) {
      if (res[j]) ++allHave;
    }
    for (int pos : v[i]) {
      int invPositive = 0;
      for (int j = pos + 1; j < n; ++j) {
        if (res[j]) ++invPositive;
      }
      ans += min(invPositive, allHave - invPositive);
      res[pos] = true;
    }
  }
  cout << ans;
}

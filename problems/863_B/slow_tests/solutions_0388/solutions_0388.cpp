#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen("cbarn"
            ".in",
            "r")) {
    freopen(
        "cbarn"
        ".in",
        "r", stdin);
    freopen(
        "cbarn"
        ".out",
        "w", stdout);
  }
  int n;
  cin >> n;
  vector<int> w(n * 2);
  for (auto& x : w) cin >> x;
  sort(w.begin(), w.end());
  int ans = INT_MAX;
  for (int i = 0; i < n * 2; ++i) {
    for (int j = i + 1; j < n * 2; ++j) {
      multiset<int> unpaired(w.begin(), w.end());
      unpaired.erase(unpaired.find(w[i]));
      unpaired.erase(unpaired.find(w[j]));
      int cur = 0;
      while (!unpaired.empty()) {
        cur -= *unpaired.begin();
        unpaired.erase(unpaired.begin());
        cur += *unpaired.begin();
        unpaired.erase(unpaired.begin());
      }
      ans = min(ans, cur);
    }
  }
  cout << ans;
}

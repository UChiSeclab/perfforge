#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<int> divs(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      res.push_back(i);
      if (x / i != i) res.push_back(x / i);
    }
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> d(*max_element(a.begin(), a.end()) + 1, 0);
  d[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j : divs(a[i])) d[j] = (d[j] % MOD + d[j - 1] % MOD) % MOD;
  }
  int ans = 0;
  for (int i = 1; i < d.size(); i++) ans = (ans % MOD + d[i] % MOD) % MOD;
  cout << ans;
}

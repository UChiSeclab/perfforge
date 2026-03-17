#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i <= n - 1; i++) cin >> a[i];
  long long u = 1e14;
  u = (long long)pow(u, ((double)1.0) / (n - 1));
  long long ans = 1e18;
  sort(a, a + n);
  for (long long c = 1; c <= u; c++) {
    long long cur_ans = 0;
    for (long long i = 0; i < n; i++) {
      cur_ans += abs(a[i] - (long long)pow(c, i));
    }
    ans = min(ans, cur_ans);
  }
  cout << ans;
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}

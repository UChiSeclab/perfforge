#include <bits/stdc++.h>
using namespace std;
int32_t main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int n, m, sum = 0, ans = 0;
  cin >> n >> m;
  vector<long long int> a(n + 1);
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  a[0] = 1;
  if (n == 1 || sum == n) {
    cout << 0;
    return 0;
  }
  sort(a.begin(), a.end());
  long long int th = a[n];
  for (long long int i = n - 1; i >= 0; i--) {
    if (i == 0)
      ans += th;
    else if (a[i + 1] == 1 || a[i] >= th - 1) {
      ans++;
      th = max(1LL, th - 1);
    } else {
      ans += th - a[i];
      th = a[i];
    }
    cerr << sum - ans << " ";
  }
  cerr << '\n';
  cout << sum - ans;
}

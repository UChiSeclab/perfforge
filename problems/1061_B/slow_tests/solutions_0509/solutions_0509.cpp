#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], m, sum, ans;
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]), sum += a[i];
  sort(a + 1, a + 1 + n);
  long long now = 0;
  for (long long i = 1; i <= n; i++) {
    now++;
    if (now > a[i]) now = a[i];
    ans++;
  }
  ans += max(0ll, a[n] - now);
  cout << sum - ans << endl;
  return 0;
}

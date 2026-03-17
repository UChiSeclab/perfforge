#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long sum[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  int ans = a[n / 2 + 1];
  int pos = n / 2 + 2, cnt = 1;
  while (pos <= n && a[pos] == a[pos - 1]) {
    ++pos;
    ++cnt;
  }
  while (k >= cnt) {
    k -= cnt;
    ++ans;
    if (pos <= n && ans == a[pos]) {
      ++cnt;
      ++pos;
    }
    if (pos > n) {
      ans += k / cnt;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

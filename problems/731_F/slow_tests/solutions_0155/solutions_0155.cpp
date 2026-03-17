#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 233;
int a[maxn];
int main() {
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  a[n + 1] = 2e9;
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;
    long long j = a[i];
    long long sum = 0;
    while (j <= 200000) {
      int l = lower_bound(a + 1, a + 1 + n, j) - a;
      int r = lower_bound(a + 1, a + 1 + n, j + a[i]) - a;
      sum += (r - l) * (j / a[i]);
      j += a[i];
    }
    sum *= a[i];
    if (sum > ans) ans = sum;
  }
  cout << ans << endl;
  return 0;
}

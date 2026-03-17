#include <bits/stdc++.h>
using namespace std;
int n, a[400005], sum[400005], c[400005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[a[i]]++, sum[a[i] + 1]++;
  for (int i = 1; i <= 400003; i++) sum[i] += sum[i - 1];
  if (c[1]) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    cout << ans;
    return 0;
  }
  long long ans = 0;
  for (int i = 2; i <= 200000; i++)
    if (c[i]) {
      long long tot = 0;
      for (int j = i; j <= 200000; j += i) {
        tot += (long long)(sum[j + i] - sum[j]) * j;
      }
      ans = max(ans, tot);
    }
  cout << ans;
  return 0;
}

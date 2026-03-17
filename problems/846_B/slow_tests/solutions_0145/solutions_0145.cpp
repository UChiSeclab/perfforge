#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
int a[maxn], dp[maxn * maxn];
int n, k, m;
int main() {
  while (~scanf("%d%d%d", &n, &k, &m)) {
    memset((dp), (0x3f), sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + k);
    for (int i = 1; i <= k; i++) {
      a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
      for (int j = n * (k + 1); j >= 0; j--)
        for (int s = 1; s <= k; s++) {
          dp[j + s + (s == k)] = min(dp[j + s + (s == k)], dp[j] + a[s]);
        }
    int ans = 0;
    for (int i = 0; i <= (k + 1) * n; i++) {
      if (dp[i] <= m) {
        ans = i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

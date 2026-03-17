#include <bits/stdc++.h>
using namespace std;
int n, x, *a, *cnt, *p2, *dp;
int main() {
  std::ios::sync_with_stdio(false);
  std::istream_iterator<int> cit(std::cin);
  n = *cit++;
  p2 = new int[n + 1];
  a = new int[n];
  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = p2[i - 1] * 2;
    if (p2[i] > 1000000007) p2[i] -= 1000000007;
  }
  for (int i = 0; i < n; i++) a[i] = *cit++;
  const int maxn = *std::max_element(a, a + n);
  dp = new int[maxn + 1]();
  cnt = new int[maxn + 1]();
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  for (int i = maxn, sum; i; i--) {
    sum = 0;
    for (int j = i; j <= maxn; j += i) sum = (sum + cnt[j]) % 1000000007;
    dp[i] = p2[sum] - 1;
    for (int j = 2 * i; j <= maxn; j += i)
      dp[i] = (dp[i] - dp[j] + 1000000007) % 1000000007;
  }
  std::cout << dp[1] << '\n';
  return 0;
}

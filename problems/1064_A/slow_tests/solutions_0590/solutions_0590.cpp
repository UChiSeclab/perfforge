#include <bits/stdc++.h>
using namespace std;
static long long gcd(long long x, long long y) {
  return y == 0 ? x : gcd(y, x % y);
}
int solve() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int ans = 1000000009;
  for (int i = 0; i < 256; ++i)
    for (int j = 0; j < 256; ++j)
      for (int k = 0; k < 256; ++k) {
        if ((a + i) < (b + j) + (c + k) && (b + j) < (a + i) + (c + k) &&
            (c + k) < (a + i) + (b + j)) {
          ans = std::min(ans, i + j + k);
        }
      }
  printf("%d\n", ans);
  return 0;
}
int main() {
  ::std::ios::sync_with_stdio(false);
  ::std::cin.tie(0);
  ::std::cout.tie(0);
  int t = 1;
  while (t--) solve();
}

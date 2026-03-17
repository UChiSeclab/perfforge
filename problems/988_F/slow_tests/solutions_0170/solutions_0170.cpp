#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = numeric_limits<int>::max();
int a, n, m, w[2001], dp[2001];
bool rain[2000];
int main() {
  scanf("%d %d %d", &a, &n, &m);
  fill(dp, dp + a + 1, MAX);
  while (n-- > 0) {
    int l, r;
    scanf("%d %d", &l, &r);
    while (l < r) rain[l++] = true;
  }
  while (m-- > 0) {
    int x, p;
    scanf("%d %d", &x, &p);
    if (x < a) {
      x++;
      if (w[x] == 0 || w[x] > p) w[x] = p;
    }
  }
  for (int i = 0; i < a; i++) {
    int m = i == 0 ? 0 : *min_element(dp, dp + i + 1);
    dp[0] = rain[i] ? MAX : m;
    dp[i + 1] = m < MAX && w[i + 1] > 0 ? m + w[i + 1] : MAX;
    for (int j = 1; j <= i; j++) {
      if (dp[j] < MAX) dp[j] += w[j];
    }
  }
  int ans = *min_element(dp, dp + a + 1);
  printf("%d\n", ans < MAX ? ans : -1);
  return 0;
}

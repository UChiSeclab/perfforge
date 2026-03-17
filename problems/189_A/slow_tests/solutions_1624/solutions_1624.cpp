#include <bits/stdc++.h>
using namespace std;
int n, t, a, b, c, ans;
void solve() {
  ans = -1;
  for (int i = (0), _b = (n); i <= _b; i++) {
    for (int j = (0), _b = (n); j <= _b; j++) {
      int tmp = n - i - j;
      if (tmp < 0) continue;
      if (i % a == 0 && j % b == 0 && tmp % c == 0) {
        int tmp2 = i / a + j / b + tmp / c;
        ans = max(ans, tmp2);
      }
    }
  }
  cout << ans << endl;
}
int main() {
  scanf("%d", &n);
  scanf("%d %d %d", &a, &b, &c);
  solve();
  return 0;
}

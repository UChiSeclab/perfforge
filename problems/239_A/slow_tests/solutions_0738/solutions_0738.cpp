#include <bits/stdc++.h>
using namespace std;
int ans[100010];
int main() {
  int y, n, k;
  while (scanf("%d%d%d", &y, &k, &n) != EOF) {
    int cot = 0;
    int now = k - y;
    while (now < 1) now += k;
    while (now + y <= n) {
      ans[cot++] = now;
      now += k;
    }
    if (cot == 0)
      cout << "-1" << endl;
    else {
      sort(ans, ans + cot);
      cout << ans[0];
      for (int i = 1; i < cot; i++) printf(" %d", ans[i]);
      cout << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int ans = 10000;
void go(int msk, int carry, int tot) {
  if (tot > 6) return;
  if (msk == 63) {
    ans = min(ans, tot);
    return;
  }
  for (int i = 0; i < 6; i++) {
    if ((msk & (1 << i)) == 0) {
      if (i <= 3) {
        if (carry >= a) go(msk | (1 << i), carry - a, tot);
        go(msk | (1 << i), n - a, tot + 1);
      } else {
        if (carry >= b) go(msk | (1 << i), carry - b, tot);
        go(msk | (1 << i), n - b, tot + 1);
      }
    }
  }
}
int main() {
  int i, j;
  cin >> n >> a >> b;
  go(0, 0, 0);
  cout << ans << endl;
}

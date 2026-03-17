#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, y, ans;
  cin >> p >> y;
  for (int i = y; i >= 2; i--) {
    bool ok = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) ok &= (j > p) && (i / j > p);
    }
    if (ok) {
      ans = i;
      break;
    }
  }
  if (ans <= p) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}

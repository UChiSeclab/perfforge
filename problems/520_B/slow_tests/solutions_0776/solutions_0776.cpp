#include <bits/stdc++.h>
using namespace std;
bool vis[2][10000 + 10];
int main(void) {
  int n, m;
  cin >> n >> m;
  vis[0][n] = true;
  for (int ans = 0;; ans++) {
    int nop = ans % 2;
    int nxp = nop ^ 1;
    if (vis[nop][m]) {
      cout << ans;
      return 0;
    }
    for (int i = 1; i <= 10000; i++) {
      if (vis[nop][i]) {
        vis[nxp][i] = true;
        if (i > 1) vis[nxp][i - 1] = true;
        if (i * 2 <= 10000) vis[nxp][i * 2] = true;
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int myfor(int i, int n, function<void(int)> f) {
  return (i < n ? (f(i), myfor(i + 1, n, f)) : 0);
}
int main() {
  int w[11][11];
  int n;
  cin >> n;
  myfor(0, n, [&](int i) { myfor(0, n, [&](int j) { cin >> w[i][j]; }); });
  myfor(0, n, [&](int k) {
    myfor(0, n, [&](int i) {
      myfor(0, n, [&](int j) { w[i][j] = min(w[i][j], w[i][k] + w[k][j]); });
    });
  });
  int ans = 0;
  myfor(0, n,
        [&](int i) { myfor(0, n, [&](int j) { ans = max(ans, w[i][j]); }); });
  cout << ans << endl;
}

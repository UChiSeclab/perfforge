#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, ans = 0;
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    double j = (double)x / i;
    if (j - round(j) == 0 && j <= n) ++ans;
  }
  cout << ans << endl;
  return 0;
}

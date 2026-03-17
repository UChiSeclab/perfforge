#include <bits/stdc++.h>
using namespace std;
int n, m, ans, c[10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int a[m], b[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    if (c[b[i] - 1] == 0) {
      c[b[i] - 1] = i + 1;
    } else {
      a[c[b[i] - 1] - 1] += a[i];
    }
  }
  sort(b, b + m, greater<int>());
  for (int i = 0; i < m && b[i] && n > 0; i++) {
    while (a[c[b[i] - 1] - 1]-- > 0 && n-- > 0) {
      ans += b[i];
    }
  }
  cout << ans;
}

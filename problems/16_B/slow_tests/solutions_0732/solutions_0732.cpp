#include <bits/stdc++.h>
using namespace std;
int n, m, a[10001], b[10001], ans = 0;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i] > b[j]) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
      }
    }
  }
  for (int i = 0;; i++) {
    if (a[i] >= n) {
      ans += n * b[i];
      break;
    } else {
      ans += b[i] * a[i];
      n -= a[i];
    }
  }
  cout << ans;
}

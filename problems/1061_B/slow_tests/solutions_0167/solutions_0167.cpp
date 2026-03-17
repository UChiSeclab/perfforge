#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) { return x > y; }
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n], cnt = 0, h = 0;
  for (int k = 0; k < n; k++) {
    cin >> a[k];
    h = max(h, a[k]);
    cnt += a[k];
  }
  sort(a, a + n, cmp);
  if (n == 1) {
    cout << 0;
    return 0;
  }
  long long k = 1, r = h, x = 0;
  while (h > 1) {
    if (a[k] >= h - 1) k++;
    h--;
    if (k == n) break;
  }
  long long ans = cnt - r - (n - k);
  cout << ans;
  return 0;
}

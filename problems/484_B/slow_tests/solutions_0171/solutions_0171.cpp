#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int MAX = 1000006;
int a[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  n = unique(a, a + n) - a;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 2 * a[i]; j < MAX; j += a[i]) {
      ans = max(ans, *(lower_bound(a, a + n, j) - 1) % a[i]);
    }
    ans = max(ans, a[n - 1] % a[i]);
  }
  cout << ans << endl;
  return 0;
}

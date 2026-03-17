#include <bits/stdc++.h>
using namespace std;
int a[120], vis[1200];
int n;
int doit(int x, int y) {
  bool use[120] = {0};
  use[x] = use[y] = 1;
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    int dif = n;
    if (use[i]) continue;
    for (int j = i + 1; j <= n; j++) {
      if (use[j]) continue;
      if (abs(a[i] - a[j]) < abs(a[i] - a[dif])) {
        dif = j;
      }
    }
    use[i] = 1;
    use[dif] = 1;
    tmp += abs(a[i] - a[dif]);
  }
  return tmp;
}
int main() {
  scanf("%d", &n);
  n *= 2;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans = min(ans, doit(i, j));
    }
  }
  cout << ans;
}

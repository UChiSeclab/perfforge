#include <bits/stdc++.h>
const int N = (int)4e3 + 228;
using namespace std;
int n, a[N], new_a[N], k, x;
int main() {
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 1; i <= n; i++) {
    int y;
    scanf("%d", &y);
    a[y]++;
  }
  for (int i = 1; i <= k; i++) {
    int cur = 0;
    for (int j = 0; j <= 4000; j++) {
      if (a[j]) {
        if (cur % 2 == 0) {
          new_a[j ^ x] += (a[j] + 1) / 2;
          new_a[j] += a[j] / 2;
        } else {
          new_a[j ^ x] += a[j] / 2;
          new_a[j] += (a[j] + 1) / 2;
        }
        cur += a[j];
      }
    }
    for (int j = 0; j <= 4000; j++) {
      a[j] = new_a[j];
      new_a[j] = 0;
    }
  }
  int mn = N, mx = -1;
  for (int i = 0; i < N; i++) {
    if (a[i]) {
      mn = min(mn, i);
      mx = max(mn, i);
    }
  }
  cout << mx << ' ' << mn << endl;
  return 0;
}

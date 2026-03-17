#include <bits/stdc++.h>
using namespace std;
int n, num, ans, sum;
int a[110], b[110];
int main() {
  ans = 0x3f3f3f3f;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) cin >> a[i];
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      if (i == j) continue;
      sum = 0;
      num = 0;
      memset(b, 0, sizeof(b));
      for (int k = 1; k <= 2 * n; k++) {
        if (k != i && k != j) {
          num++;
          b[num] = a[k];
        }
      }
      sort(b + 1, b + num + 1);
      for (int k = 1; k <= num; k += 2) {
        sum += (b[k + 1] - b[k]);
      }
      ans = min(ans, sum);
    }
  }
  cout << ans;
  return 0;
}

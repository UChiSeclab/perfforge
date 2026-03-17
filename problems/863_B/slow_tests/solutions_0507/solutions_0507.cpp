#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[110];
int main() {
  int n;
  cin >> n;
  n *= 2;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 10000005;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      memset(b, 0, sizeof(b));
      int num = 0;
      for (int k = 1; k <= n; k++)
        if (k != i && k != j) b[num++] = a[k];
      sort(b, b + num);
      int sum = 0;
      for (int k = 0; k < num; k += 2) sum += b[k + 1] - b[k];
      ans = min(sum, ans);
    }
  }
  cout << ans << endl;
  return 0;
}

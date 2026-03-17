#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c, n, i, s1 = 100000, sum = 0;
  cin >> n;
  int a[2 * n];
  for (i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a, a + 2 * n);
  for (int j = 0; j < 2 * n - 1; j++) {
    for (int k = j + 1; k < 2 * n; k++) {
      sum = 0;
      c = 1;
      for (i = 0; i < 2 * n; i++) {
        if (i != k && i != j) {
          sum += (pow(-1, c) * a[i]);
          c++;
        }
      }
      s1 = min(s1, sum);
    }
  }
  cout << s1;
  return 0;
}

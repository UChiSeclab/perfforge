#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int p = a[1];
  int q = a[n];
  int k = 1, cnt = 0;
  for (int i = p; i <= q; i++) {
    if (i == a[k]) {
      k++;
    } else {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

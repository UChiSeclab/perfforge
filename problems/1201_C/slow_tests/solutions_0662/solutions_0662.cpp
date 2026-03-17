#include <bits/stdc++.h>
using namespace std;
int n, k, m, i;
int main() {
  cin >> n >> k;
  int a[200004];
  m = n / 2;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = a[m]; k > 0; i++) {
    while (i == a[m + 1]) m++;
    k = k - (m - n / 2 + 1);
  }
  if (k == 0)
    cout << i;
  else
    cout << i - 1;
}

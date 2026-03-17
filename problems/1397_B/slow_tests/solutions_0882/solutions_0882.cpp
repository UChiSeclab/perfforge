#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, j, k, x, y, z, n, mi = 1e16, sum = 0;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n == 1 || n == 2) {
    cout << a[0] - 1;
    return;
  }
  z = (long long)pow(1e18, 1.0 / (n - 1));
  if (n == 3) {
    z = (long long)pow(10, 7);
  }
  for (i = 1; i <= z; i++) {
    sum = 0;
    for (j = 0; j < n; j++) {
      y = (long long)pow(i, j);
      sum += abs(a[j] - y);
    }
    mi = min(mi, sum);
  }
  cout << mi;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t-- > 0) {
    solve();
  }
}

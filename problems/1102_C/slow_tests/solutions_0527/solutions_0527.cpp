#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = LLONG_MAX;
const long long N = 1e5 + 10;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long k, z;
  if (x > y) {
    cout << n << endl;
    return 0;
  } else {
    while (1) {
      sort(a, a + n);
      for (long long j = 0; j < n; j++) {
        if (a[j] != 0) {
          z = a[j];
          k = j;
          break;
        }
      }
      if (z > x) {
        cout << k << endl;
        return 0;
      } else {
        a[k] = 0;
        if ((k + 1) == n) {
          cout << k + 1 << endl;
          return 0;
        }
      }
      if (a[k] == 0) {
        a[k + 1] = a[k + 1] + y;
      } else {
        a[k] = a[k] + y;
      }
    }
  }
}

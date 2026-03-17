#include <bits/stdc++.h>
using namespace std;
const long long mxn = 100000;
long long c[mxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    c[1] = 2;
    for (int i = 2; i < mxn; i++) {
      c[i] = ((i - 1) * 3) + 2 + c[i - 1];
    }
    for (int i = mxn - 1; i >= 1; i--) {
      if (n >= c[i]) {
        ans += n / c[i];
        n = n % c[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T-- > 0) {
    long long n, k;
    cin >> n >> k;
    int m;
    for (m = 2; m <= n; m++) {
      if (n % m == 0) break;
    }
    long long ans = n + m + (k - 1) * 2;
    cout << ans << endl;
  }
  return 0;
}

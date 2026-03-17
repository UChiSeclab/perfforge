#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string ans(n, 'a');
    for (int i = n - 2; i >= 0; i--) {
      if (k <= n - i - 1) {
        ans[i] = ans[n - k] = 'b';
        break;
      }
      k -= (n - i - 1);
    }
    cout << ans << endl;
  }
  return 0;
}

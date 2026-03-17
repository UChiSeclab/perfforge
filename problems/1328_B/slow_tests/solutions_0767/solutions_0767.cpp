#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < int(t); tt++) {
    int n, k;
    cin >> n >> k;
    string s(n, 'a');
    for (int i = n - 2; i >= 0; i--) {
      if (k <= (n - i - 1)) {
        s[i] = 'b';
        s[n - k] = 'b';
        cout << s << endl;
        break;
      }
      k -= (n - i - 1);
    }
  }
}

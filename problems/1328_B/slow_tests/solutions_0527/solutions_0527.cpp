#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
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
      k -= n - i - 1;
    }
  }
}

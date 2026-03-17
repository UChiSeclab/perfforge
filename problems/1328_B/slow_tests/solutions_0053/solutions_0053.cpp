#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string str(n, 'a');
    for (int i = n - 2; i >= 0; --i) {
      if (k <= n - i - 1) {
        str[i] = 'b';
        str[n - k] = 'b';
        cout << str << endl;
        break;
      } else {
        k -= n - i - 1;
      }
    }
  }
  return 0;
}

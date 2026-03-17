#include <bits/stdc++.h>
using namespace std;
int main() {
  iostream::sync_with_stdio(0);
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) {
    int n;
    cin >> n;
    bool r = true;
    for (int a = 0; a <= 100; a++) {
      for (int b = 0; b <= 100; b++) {
        if (a * 3 + b * 7 == n && r) {
          cout << "YES" << endl;
          r = false;
          break;
        }
      }
    }
    if (r) cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mn = min(min(a, b), c);
  if (mn > 3) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < 60; j++) {
      for (int k = 0; k < 60; k++) {
        int cnt = 0;
        for (int t = 0; t <= 27; t++) {
          if ((t - i) % a == 0 or (t - j) % b == 0 or (t - k) % c == 0) {
            cnt++;
          }
        }
        if (cnt == 28) {
          cout << "YES\n";
          return 0;
        }
      }
    }
  }
  cout << "NO\n";
  return 0;
}

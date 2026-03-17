#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, a, b, c, t, n;
  cin >> a >> b >> c;
  if (a == c || b == c || a + b == c) {
    cout << "YES" << endl;
    return 0;
  } else {
    for (i = 0; i <= 10000; i++) {
      for (j = 0; j <= 10000; j++) {
        if (a * i + b * j == c) {
          cout << "YES" << endl;
          return 0;
        } else
          continue;
      }
    }
    cout << "NO" << endl;
  }
}

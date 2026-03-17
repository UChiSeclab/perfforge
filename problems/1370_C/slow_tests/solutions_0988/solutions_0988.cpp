#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m = 1;
    cin >> n;
    while (n % 2 == 0) {
      n /= 2;
      m *= 2;
    }
    int x = 1;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) x = 0;
    }
    if ((n == 1 && m != 2) || (n != 1 && m == 2 && x))
      cout << "FastestFinger";
    else
      cout << "Ashishgup";
    cout << endl;
  }
}

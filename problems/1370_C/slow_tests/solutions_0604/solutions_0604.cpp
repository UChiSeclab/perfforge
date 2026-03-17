#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, c = 1, b, x = 1, y = 0, f1 = 0, f2 = 0, m = 0, k, d = -1,
                     g = -1, a;
    cin >> n;
    vector<long long int> x1, y1;
    if (n % 2 != 0 && n != 1)
      cout << "Ashishgup"
           << "\n";
    else if (n == 1)
      cout << "FastestFinger"
           << "\n";
    else if (n == 2)
      cout << "Ashishgup"
           << "\n";
    else {
      for (long long int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
          if (i % 2 != 0 || (n / i) % 2 != 0) {
            f1 = 1;
            if ((n / i) % 2 != 0 && i <= 2) {
              f1 = 0;
              continue;
            }
            break;
          }
        }
      }
      if (f1 == 1)
        cout << "Ashishgup"
             << "\n";
      else
        cout << "FastestFinger"
             << "\n";
    }
  }
  return 0;
}

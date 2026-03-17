#include <bits/stdc++.h>
using namespace std;
long long t, n;
bool solve() {
  if (n == 2) return true;
  int n1 = 0;
  long long t = n;
  for (long long a = 2; a <= sqrt(n) && a <= t; a++) {
    while (t % a == 0) {
      t /= a;
      if (a % 2 == 1) n1++;
    }
  }
  if (t > 1 && t % 2 == 1) {
    n1++;
  }
  if (n % 2 == 0 && (n / 2) % 2 == 1) {
    return n1 > 1;
  }
  return n1 >= 1;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (solve()) {
      cout << "Ashishgup" << endl;
    } else {
      cout << "FastestFinger" << endl;
    }
  }
  return 0;
}

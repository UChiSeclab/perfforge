#include <bits/stdc++.h>
using namespace std;
int sum(int n) {
  int ans = 0;
  for (int ii = 1; ii <= n; ii++) {
    ans = ans + ii;
  }
  return ans;
}
int main() {
  int test, n, a, x, b, countp = 0;
  cin >> test;
  for (int ss = 0; ss < test; ss++) {
    countp = 0;
    cin >> n;
    while (n >= 2) {
      x = 1;
      while (1 == 1) {
        a = sum(x);
        b = 3 * a - x;
        if (b > n) {
          x--;
          break;
        }
        x++;
      }
      b = 3 * sum(x) - x;
      n = n - b;
      countp++;
    }
    cout << countp << endl;
  }
  return 0;
}

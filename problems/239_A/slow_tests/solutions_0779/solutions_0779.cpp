#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 1e6 + 7;
int y, k, n, t;
int main() {
  cin >> y >> k >> n;
  int c = 1;
  for (int i = 1;; ++i) {
    if (k * i > y) {
      c = k * i - y;
      break;
    }
  }
  for (int i = c;; i += k) {
    if (i + y > n) {
      break;
    }
    if ((i + y) % k == 0) {
      cout << i << ' ';
      t = 1;
    }
  }
  if (!t) {
    cout << -1;
  }
}

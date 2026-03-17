#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;
  if (k == 1 || l == 1 || m == 1 || n == 1)
    cout << d;
  else {
    int t = 0;
    for (int i = 1; i <= d; i++)
      if (i % k == 0)
        ++t;
      else if (i % l == 0)
        ++t;
      else if (i % m == 0)
        ++t;
      else if (i % n == 0)
        ++t;
    cout << t;
  }
}

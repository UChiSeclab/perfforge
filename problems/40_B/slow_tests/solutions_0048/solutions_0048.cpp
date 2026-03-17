#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, s = 0;
  cin >> n >> m >> x;
  for (long long i = x; i <= n - x + 1; i++) {
    for (long long j = x; j <= m - x + 1; j++) {
      if (i % 2 == j % 2)
        if (min(min(i, j), min(n - i + 1, m - j + 1)) == x) ++s;
    }
  }
  cout << s;
  return 0;
}

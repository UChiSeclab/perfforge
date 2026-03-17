#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int a[n + 1];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (x > y)
    cout << n;
  else {
    int c = 0;
    map<int, int> m;
    for (int i = 1; i <= n; ++i) m[a[i]]++;
    for (int i = 1; i <= x; ++i) {
      if (m[i] > 0) c += m[i];
    }
    if (c % 2 == 0)
      cout << c / 2;
    else
      cout << c / 2 + 1;
  }
  return 0;
}

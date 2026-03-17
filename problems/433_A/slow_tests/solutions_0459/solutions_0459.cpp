#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, ca = 0, cb = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 100)
      ++ca;
    else
      ++cb;
    sum += x;
  }
  if (sum % 2 == 1)
    cout << "NO\n";
  else {
    bool ok = 0;
    for (int i = 0; i <= ca; ++i)
      for (int j = 0; j <= cb; ++j)
        if (i * 100 + j * 200 == sum / 2) ok = 1;
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

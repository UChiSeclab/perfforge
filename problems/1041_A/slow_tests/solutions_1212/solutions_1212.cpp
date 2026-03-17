#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, c = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  x = a[0];
  for (i = 0; i < n; i++, x++) {
    if (a[i] == x)
      continue;
    else {
      c++;
      i--;
    }
  }
  cout << c;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (b != d && b < 1e8) {
    b < d ? b += a : d += c;
  }
  if (b == d)
    cout << b << endl;
  else
    cout << "-1\n";
  return 0;
}

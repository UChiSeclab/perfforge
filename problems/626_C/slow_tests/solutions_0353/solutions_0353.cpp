#include <bits/stdc++.h>
using namespace std;
const int MX = 30 * 1e6 + 10;
int n;
bool vi[MX];
int main() {
  int o, oo, n, m;
  cin >> o >> oo;
  for (int j = 1; j <= MX; j++) {
    int two = j / 2, three = j / 3, six = j / 6;
    two -= six;
    three -= six;
    n = o, m = oo;
    n -= min(n, two);
    m -= min(m, three);
    if (six >= n + m) {
      cout << j << endl;
      return 0;
    }
  }
}

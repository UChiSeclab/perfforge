#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, m, n;
  cin >> m;
  while (m--) {
    k = 0;
    cin >> n;
    for (i = 0; i < 100; i++)
      for (j = 0; j < 100; j++)
        if ((3 * i + j * 7) == n) k++;
    if (k > 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

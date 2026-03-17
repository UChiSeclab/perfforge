#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, ans = 0;
  cin >> n >> m >> x;
  for (int i = 0; i < n - 2 * x + 2; i++)
    for (int j = 0; j < m - 2 * x + 2; j++)
      if (i % 2 == j % 2) ans++;
  for (int i = 0; i < n - 2 * (x + 1) + 2; i++)
    for (int j = 0; j < m - 2 * (x + 1) + 2; j++)
      if (i % 2 == j % 2) ans--;
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, ans = 0;
  cin >> n >> x;
  for (i = ceil(sqrt((double)x)); i <= n; i++)
    if (i * i == x)
      ans++;
    else if (!(x % i))
      ans += 2;
  cout << ans;
  return 0;
}

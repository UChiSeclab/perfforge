#include <bits/stdc++.h>
using namespace std;
int n, x, b[100005], l, r;
long long ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> x;
  for (int i = 2; i * i <= n; i++)
    if (b[i] == 0)
      for (int j = i + i; j <= n; j += i) b[j] = 1;
  for (int i = 1; i <= n; i++)
    if (((x % i == 0 and i <= x and x / i <= n) and (i != 1 or n >= x))) ans++;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0 and i == x) {
      if (n >= x)
        l = 1;
      else
        r = 1;
    }
  }
  if (x == 1)
    cout << 1;
  else if (l == 1)
    cout << 2;
  else if (r == 1)
    cout << 0;
  else
    cout << ans;
}

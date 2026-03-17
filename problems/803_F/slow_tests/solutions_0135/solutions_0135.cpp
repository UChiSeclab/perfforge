#include <bits/stdc++.h>
using namespace std;
int n, a[100001], h[100001], g[100001], x, m, f[100001];
int main() {
  cin >> n;
  a[0] = 1;
  for (int i = 1; i <= n; i++)
    a[i] = a[i - 1] * 2 % 1000000007, cin >> x, f[x]++, m = max(m, x);
  for (int i = m; i >= 1; i--) {
    for (int j = i; j <= m; j += i)
      g[i] += f[j], h[i] = (h[i] - h[j] + 1000000007) % 1000000007;
    h[i] = (h[i] + a[g[i]] - 1) % 1000000007;
  }
  cout << h[1];
}

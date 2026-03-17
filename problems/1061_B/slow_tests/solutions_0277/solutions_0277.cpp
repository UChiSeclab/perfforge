#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, m, ar[N], ans, mx, res[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%I64d", &ar[i]);
  sort(ar + 1, ar + n + 1);
  mx = ar[n] - 1;
  for (int i = n - 1; i >= 1; i--) {
    ans += ar[i] - 1;
    mx = min(mx, ar[i]);
    if (mx > 0) mx--, ans++;
  }
  cout << ans << endl;
}

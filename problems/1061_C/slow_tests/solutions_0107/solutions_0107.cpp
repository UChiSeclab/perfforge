#include <bits/stdc++.h>
using namespace std;
vector<int> x[1000005];
int a[100005];
long long f[1000005];
int main() {
  int n, i, mx = 0, j;
  long long ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]), mx = max(a[i], mx);
  for (i = 1; i <= mx; ++i)
    for (j = i; j <= mx; j += i) x[j].push_back(i);
  for (i = 1; i <= mx; ++i) sort(x[i].begin(), x[i].end());
  f[0] = 1;
  for (i = 1; i <= n; ++i)
    for (j = x[a[i]].size() - 1; j >= 0; --j)
      f[x[a[i]][j]] = (f[x[a[i]][j]] + f[x[a[i]][j] - 1]) % 1000000007ll;
  for (i = 1; i <= n; ++i) ans = (ans + f[i]) % 1000000007ll;
  printf("%I64d", ans);
}

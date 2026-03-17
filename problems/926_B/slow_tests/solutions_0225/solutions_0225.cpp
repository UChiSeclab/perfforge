#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
long long a[N];
bool go(long long n, long long m) {
  long long i, l = (a[n - 1] - a[0]) / m;
  for (i = 1; i < n; i++) {
    if (((a[i] - a[0]) % l) != 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, n, m, l, r, ans = -1;
  scanf("%lld", &n);
  ;
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  ;
  sort(a, a + n);
  l = a[n - 1] - a[0];
  vector<long long> v;
  for (i = 1; i <= (l / i); i++) {
    if (l % i == 0) {
      if (i >= (n - 1)) v.push_back(i);
      if (i != (l / i) && (l / i) >= (n - 1)) v.push_back(l / i);
    }
  }
  sort(v.begin(), v.end());
  r = 0;
  while (ans == -1) {
    if (go(n, v[r]) == true) ans = v[r] - n + 1;
    r++;
  }
  printf("%lld\n", ans);
  return 0;
}

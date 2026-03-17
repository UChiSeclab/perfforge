#include <bits/stdc++.h>
using namespace std;
long long a[1000009];
vector<long long> v;
int main() {
  long long i, j, k, n, m;
  while (scanf("%lld", &n) == 1) {
    memset(a, 0, sizeof(a));
    v.clear();
    long long mx = 0;
    for (i = 0; i < n; i++) {
      scanf("%lld", &k);
      mx = max(k, mx);
      a[k]++;
    }
    long long pre = 0;
    for (i = mx; i >= 1; i--) {
      if (pre) {
        if (a[i] % 2) {
          a[i]++;
          pre = 0;
        } else if (a[i] == 0)
          pre = 0;
        else
          pre = 1;
      } else {
        if (a[i] % 2) {
          a[i]--;
          pre = 1;
        } else
          pre = 0;
      }
      a[i] /= 2;
    }
    long long ans = 0;
    for (i = mx; i >= 1; i--) {
      for (j = 0; j < a[i]; j++) v.push_back(i);
    }
    for (i = 0; i + 1 < v.size(); i += 2) {
      ans += v[i] * v[i + 1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}

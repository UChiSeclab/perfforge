#include <bits/stdc++.h>
using namespace std;
int main() {
  long long(n), (k);
  scanf("%lld%lld", &(n), &(k));
  ;
  long long n2 = n;
  vector<long long> vec;
  while (n) {
    vec.push_back(n);
    if (n - 1 > 0) vec.push_back(n - 1);
    n /= 2;
  }
  long long maxi = 1;
  auto allok = [&](long long v) {
    long long mi = v, ma = (v % 2) ? v : v + 1;
    long long c = ma - mi + 1;
    while (ma <= n2) {
      mi *= 2;
      ma = 2 * ma + 1;
      if (mi < n2) c += min(ma, n2) - mi + 1;
    }
    return c >= k;
  };
  for (auto i : vec) {
    while (i <= n2) {
      if (allok(i)) maxi = max(maxi, i);
      i *= 2;
    }
  }
  printf("%lld\n", maxi);
  return 0;
}

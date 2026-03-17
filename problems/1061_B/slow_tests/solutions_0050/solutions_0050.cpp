#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  multiset<long long> S;
  long long maxi = 0, sum = 0;
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    S.insert(a[i]);
    maxi = max(maxi, a[i]);
    sum += a[i];
  }
  if (n == 1 || maxi == 1) {
    printf("0\n");
    return 0;
  }
  long long pos = 1, cnt = 0;
  while (!S.empty() and pos <= maxi) {
    auto it = S.lower_bound(pos);
    if (it == S.end()) break;
    S.erase(it);
    cnt++;
    pos++;
  }
  long long res = 0;
  if (pos > maxi)
    res = sum - n;
  else
    res = sum - (maxi - cnt) - n;
  printf("%lld\n", res);
  return 0;
}

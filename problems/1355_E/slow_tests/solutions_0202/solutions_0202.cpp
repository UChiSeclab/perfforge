#include <bits/stdc++.h>
using namespace std;
int h[100005];
int n, a, r, m;
long long costMv(long long x, long long y) { return x * m + y * (a + r); }
long long cost(int target) {
  long long dp = 0;
  long long dm = 0;
  for (int(i) = 0; (i) < (n); (i)++) {
    if (h[i] > target) {
      dp += h[i] - target;
    }
    if (h[i] < target) {
      dm += target - h[i];
    }
  }
  long long mv = min(dp, dm);
  long long ans = (dp - mv) * r + (dm - mv) * a;
  long long l = 0, r = mv;
  while (r - l > 2) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    if (costMv(m1, mv - m1) > costMv(m2, mv - m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  long long tmp = costMv(l, mv - l);
  for (long long i = l; i <= r; i++) {
    tmp = min(tmp, costMv(i, mv - i));
  }
  ans += tmp;
  return ans;
}
int main(void) {
  scanf("%d%d%d%d", &n, &a, &r, &m);
  for (int(i) = 0; (i) < (n); (i)++) {
    scanf("%d", &h[i]);
  }
  int l = 0, r = 1000000000;
  while (r - l > 2) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (cost(m1) > cost(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  long long ans = cost(l);
  for (int(i) = (l); (i) < (r + 1); (i)++) {
    ans = min(ans, cost(i));
  }
  printf("%lld\n", ans);
}

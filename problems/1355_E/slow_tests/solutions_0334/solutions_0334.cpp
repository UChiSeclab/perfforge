#include <bits/stdc++.h>
int main() {
  int n;
  long long a, b, c;
  std::cin >> n >> a >> b >> c;
  std::vector<long long> h(n);
  for (int i = 0; i < n; i++) std::cin >> h[i];
  std::sort(h.rbegin(), h.rend());
  auto func = [&](long long targ) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) cnt += std::max(0LL, h[i] - targ);
    long long ret = 0;
    bool ok[100003] = {};
    for (int i = 0; i < n; i++) {
      if (targ - h[i] > cnt) break;
      ret += std::max(0LL, targ - h[i]) * std::min(a + b, c);
      cnt -= std::max(0LL, targ - h[i]);
      ok[i] = true;
    }
    for (int i = 0; i < n; i++) {
      if (ok[i]) continue;
      long long res = targ - h[i];
      if (cnt > 0) {
        res -= cnt;
        ret += cnt * std::min(a + b, c);
        cnt = 0;
      }
      ret += res * a;
    }
    if (cnt > 0) ret += cnt * b;
    return ret;
  };
  long long lo = -1, hi = 1e9 + 1;
  while (hi - lo > 1) {
    long long mid = lo + (hi - lo) / 2;
    long long l = func(mid);
    long long r = func(mid + 1);
    if (l > r)
      lo = mid;
    else
      hi = mid;
  }
  std::cout << std::min(func(lo), func(hi)) << std::endl;
  return 0;
}

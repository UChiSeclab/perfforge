#include <bits/stdc++.h>
using namespace std;
int a[1000100];
int main(int argc, char const *argv[]) {
  int n, mx = 0;
  scanf("%d", &n);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    ++a[x];
    mx = max(mx, x);
  }
  for (int i = mx; i >= 2; --i) {
    if (a[i] & 1) {
      --a[i];
      if (a[i - 1] > 0) ++a[i - 1];
    }
  }
  long long ans = 0;
  pair<int, int> left = {0, 0};
  for (int i = mx; i >= 2; --i) {
    if (a[i] == 0) continue;
    if (left.second == 2 && a[i] >= 2) {
      ans += 1LL * left.first * i;
      a[i] -= 2;
    }
    if (a[i] > 2) {
      ans += (1LL * i * i) * (a[i] / 4LL);
      a[i] -= (a[i] / 4LL) * 4LL;
    }
    left.first = i;
    left.second = a[i];
  }
  printf("%lld\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool check(int x, int n, int g) {
  int low = 1, high = n;
  while (low <= high) {
    int mid = (low + high) >> 1;
    long long tmp = (long long)x * mid;
    if (tmp == g) return true;
    if (tmp < g)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}
int main() {
  int n, x;
  while (scanf("%d%d", &n, &x) == 2) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (check(i, n, x)) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}

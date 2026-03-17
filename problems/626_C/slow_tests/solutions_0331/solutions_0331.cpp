#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int mx1 = n * 2, mx2 = m * 3;
  map<int, int> mp;
  for (int i = 2; i <= n * 2; i += 2) {
    mp[i]++;
  }
  for (int j = 3; j <= m * 3; j += 3) {
    mp[j]++;
  }
  for (int i = 1; i <= max(mx1, mx2); i++) {
    if (mp[i] > 1) {
      if (mx1 + 2 < mx2 + 3) {
        mx1 += 2;
        mp[mx1]++;
      } else {
        mx2 += 3;
        mp[mx2]++;
      }
    }
  }
  printf("%d\n", max(mx1, mx2));
  return 0;
}

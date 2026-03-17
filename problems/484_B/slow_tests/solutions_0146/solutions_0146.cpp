#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int lim = 1000000;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    if (i > 0 and v[i] == v[i - 1]) continue;
    int cur = 2 * v[i];
    while (1) {
      auto it = lower_bound(v.begin(), v.end(), cur - 1);
      if (it == v.end()) {
        ans = max(ans, v[n - 1] % v[i]);
      } else {
        if (*it == cur - 1)
          ans = max(ans, *(it) % v[i]);
        else
          ans = max(ans, *(--it) % v[i]);
      }
      if (cur > lim) break;
      cur += v[i];
    }
  }
  cout << ans << endl;
  return 0;
}

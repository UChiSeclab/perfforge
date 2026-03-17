#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
vector<int> a;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  set<int> s(a.begin(), a.end());
  a.assign(s.begin(), s.end());
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 2; a[i] * j <= 2 * MAXN; j++) {
      int d = lower_bound(a.begin(), a.end(), j * a[i]) - a.begin();
      if (d >= i + 1 && d - 1 < a.size()) ans = max(ans, a[d - 1] % a[i]);
    }
  }
  printf("%d\n", ans);
}

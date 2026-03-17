#include <bits/stdc++.h>
using namespace std;
int a[(int)1e5 + 1000], b[(int)1e5 + 1000];
int FF[(int)1e5 + 1000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) b[i] *= k;
  for (int i = 1; i <= n; i++) FF[i] = a[i] - b[i];
  map<int, int> now, trans;
  now[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (auto c : now) {
      trans[c.first + FF[i]] = c.second + a[i];
    }
    for (auto c : trans) {
      now[c.first] = max(now[c.first], c.second);
    }
    trans.clear();
  }
  if (now[0] == 0) {
    printf("-1\n");
  } else {
    printf("%d\n", now[0]);
  }
}

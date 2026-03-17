#include <bits/stdc++.h>
using namespace std;
const int maxn = 500500;
vector<int> b[maxn];
int a[maxn], s[maxn];
int main(void) {
  int n, c;
  scanf("%d%d", &n, &c);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]].push_back(i);
    mx = max(mx, a[i]);
  }
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (a[i] == c);
  int ans = 0;
  for (int i = 1; i <= mx; i++) {
    int tmp = b[i].size() > 0 ? (s[b[i][0] - 1] - 0) : 0;
    for (int j = 0; j < b[i].size(); j++) {
      tmp = max(tmp, s[b[i][j] - 1] - j);
      ans = max(ans, s[n] + 1 + tmp + j - s[b[i][j]]);
    }
  }
  printf("%d\n", ans);
  return 0;
}

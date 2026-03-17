#include <bits/stdc++.h>
using namespace std;
int a[100100], b[100100], c[1001000];
char s[1010000];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 0; i < n; i++) {
    c[i] = s[i] - '0';
    if (c[i]) cnt++;
  }
  int ans = cnt;
  if (cnt == n)
    printf("%d\n", n);
  else {
    for (int i = 1; i < 10000; i++) {
      for (int j = 0; j < n; j++) {
        if (i < b[j]) continue;
        if (i == b[j] || (i - b[j]) % a[j] == 0) {
          if (c[j]) {
            cnt--;
            c[j] = 0;
          } else {
            cnt++;
            c[j] = 1;
          }
        }
      }
      ans = max(ans, cnt);
      if (ans >= n) {
        ans = n;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

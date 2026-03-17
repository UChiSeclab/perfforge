#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int n;
char s[maxn];
int a[maxn], b[maxn];
int sta[maxn];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1')
      sta[i] = 1, ans++;
    else
      sta[i] = 0;
  }
  for (int time = 1; time <= 50000; time++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (time > b[i]) {
        if ((time - b[i]) % a[i] == 0) sta[i] ^= 1;
      } else if (time == b[i])
        sta[i] ^= 1;
      if (sta[i]) cnt++;
    }
    ans = max(ans, cnt);
    if (ans == n) break;
  }
  printf("%d\n", ans);
  return 0;
}

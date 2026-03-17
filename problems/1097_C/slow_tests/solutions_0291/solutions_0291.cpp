#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
char s[maxn];
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    a[i] = 0;
    bool flag = false;
    for (int j = 0; s[j]; j++) {
      if (s[j] == '(')
        a[i]++;
      else
        a[i]--;
      if (a[i] < 0) flag = true;
    }
    if (a[i] >= 0 && flag) a[i] = maxn;
    if (a[i] < 0) {
      int tmp = 0;
      for (int j = strlen(s) - 1; j >= 0; j--) {
        if (s[j] == ')')
          tmp++;
        else
          tmp--;
        if (tmp < 0) {
          a[i] = maxn;
          break;
        }
      }
    }
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  int i = 1, j = n;
  while (i < j) {
    if (a[i] + a[j] == 0)
      i++, j--, ans++;
    else {
      while (a[j] > -a[i]) j--;
      while (a[i] < -a[j]) i++;
    }
  }
  printf("%d\n", ans);
  return 0;
}

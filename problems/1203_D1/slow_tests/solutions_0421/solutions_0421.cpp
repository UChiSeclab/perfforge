#include <bits/stdc++.h>
using namespace std;
char s[220], t[220], r[220];
int main(void) {
  int n, m, l;
  int i, j, k;
  int p;
  int o;
  scanf("%s", s);
  scanf("%s", t);
  n = strlen(s);
  m = strlen(t);
  for (i = o = 0; i < n; i++)
    for (j = i; j < n; j++) {
      for (k = l = 0; k < n; k++)
        if (k < i || j < k) r[l++] = s[k];
      for (k = p = 0; k < l && p < m; k++)
        if (r[k] == t[p]) ++p;
      if (p == m) o = max(o, j - i + 1);
    }
  printf("%d\n", o);
  return 0;
}

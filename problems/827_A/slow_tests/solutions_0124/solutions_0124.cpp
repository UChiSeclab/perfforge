#include <bits/stdc++.h>
using namespace std;
char ans[2000006];
int main() {
  int n, a, b, i, l, len = 0, tot;
  scanf("%d", &n);
  while (n--) {
    string str;
    cin >> str;
    scanf("%d", &b);
    l = str.length();
    tot = 0;
    while (b--) {
      scanf("%d", &a);
      a--;
      len = max(len, a + l);
      for (i = max(a, tot); i < a + l; i++) ans[i] = str[i - a];
      tot = a + l;
    }
  }
  for (i = 0; i < len; i++) {
    if (ans[i] == '\0')
      printf("a");
    else
      printf("%c", ans[i]);
  }
  return 0;
}

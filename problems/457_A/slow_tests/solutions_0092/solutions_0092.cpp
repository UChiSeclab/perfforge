#include <bits/stdc++.h>
char a[100005];
char b[100005];
char *operate(char *c) {
  int i = 4;
  while (c[i++])
    ;
  for (int k = 4; k < i; ++k) {
    for (int j = k; c[j] > '0' && c[j - 1] > '0'; j -= 2) {
      --c[j];
      --c[j - 1];
      c[j - 2] = '1';
    }
  }
  i = 0;
  while (c[++i] <= '0' && i < 100005)
    ;
  return c + i;
}
int len(char *c) {
  int i = 0;
  while (c[i++])
    ;
  return i;
}
int main() {
  scanf("%s%s", a + 4, b + 4);
  char *ap = operate(a);
  char *bp = operate(b);
  int al = len(ap), bl = len(bp);
  if (al > bl) {
    printf(">\n");
    return 0;
  } else if (al < bl) {
    printf("<\n");
    return 0;
  } else {
    for (int k = 0; k < al; ++k) {
      if (ap[k] > bp[k]) {
        printf(">\n");
        return 0;
      } else if (ap[k] < bp[k]) {
        printf("<\n");
        return 0;
      }
    }
    printf("=\n");
  }
  return 0;
}

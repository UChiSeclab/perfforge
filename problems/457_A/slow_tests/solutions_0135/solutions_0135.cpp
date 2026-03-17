#include <bits/stdc++.h>
using namespace std;
char a[300006];
char b[300005];
int sa[300006];
int sb[300005];
void conv(int* s, int n) {
  for (int i = n; i >= 0; i--) {
    if (s[i] >= 3) {
      s[i] -= 3;
      s[i + 2]++;
      if (i - 2 >= 0)
        s[i - 2]++;
      else if (i - 1 >= 0)
        s[i - 1]++;
      i += 4;
    } else if (s[i] == 2) {
      s[i] -= 2;
      s[i + 1]++;
      if (i - 2 >= 0)
        s[i - 2]++;
      else if (i - 1 >= 0)
        s[i - 1]++;
      i += 4;
    } else if (i > 0 && s[i] == 1 && s[i - 1] > 0) {
      s[i - 1]--;
      s[i]--;
      s[i + 1]++;
      i += 4;
    }
  }
}
int main() {
  scanf("%s", a);
  scanf("%s", b);
  int na = strlen(a);
  int nb = strlen(b);
  reverse(a, a + na);
  reverse(b, b + nb);
  for (int i = 2; i < na; i++) sa[i - 2] = a[i] - '0';
  if (a[1] == '1') sa[0]++;
  for (int i = 2; i < nb; i++) sb[i - 2] = b[i] - '0';
  if (b[1] == '1') sb[0]++;
  conv(sa, 300000);
  conv(sb, 300000);
  bool eq = 1;
  int la = 0, lb = 0;
  for (int i = 0; i < 300000; i++)
    if (sa[i] != sb[i]) {
      eq = 0;
      break;
    }
  for (int i = 300000; i >= 0; i--)
    if (sa[i] != sb[i]) {
      if (sa[i] > sb[i])
        la = 1;
      else
        lb = 1;
      break;
    }
  memset(sa, 0, sizeof(sa));
  memset(sb, 0, sizeof(sb));
  for (int i = 3; i < na; i++) sa[i - 3] = a[i] - '0';
  if (a[0] == '1') sa[0]++;
  if (a[2] == '1') sa[0]++;
  for (int i = 3; i < nb; i++) sb[i - 3] = b[i] - '0';
  if (b[0] == '1') sb[0]++;
  if (b[2] == '1') sb[0]++;
  conv(sa, 300000);
  conv(sb, 300000);
  for (int i = 0; i < 300000; i++) {
    if (sa[i] != sb[i]) {
      eq = 0;
      break;
    }
  }
  if (eq)
    printf("=\n");
  else {
    if (la > lb)
      printf(">\n");
    else if (la < lb)
      printf("<\n");
    else {
      for (int i = 300000; i >= 0; i--)
        if (sa[i] != sb[i]) {
          if (sa[i] > sb[i])
            la = 1;
          else
            lb = 1;
          break;
        }
      if (la > lb)
        printf(">\n");
      else if (la < lb)
        printf("<\n");
      else
        printf("=\n");
    }
  }
  return 0;
}

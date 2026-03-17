#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w, ans, ww;
char s[15];
int A[100005], tmp[30], add[500005], minu[500005];
int main() {
  scanf("%d %d", &n, &k);
  ww = k;
  for (int i = (0); i <= (n); i++) A[i] = -10001;
  for (int i = (0); i <= (n); i++) {
    scanf("%s", s);
    if (s[0] == '?')
      x++;
    else {
      m = strlen(s);
      y = 0;
      if (s[0] == '-')
        for (int j = (1); j < (m); j++) {
          y *= 10;
          y += (s[j] - 48);
        }
      else
        for (int j = (0); j < (m); j++) {
          y *= 10;
          y += (s[j] - 48);
        }
      if (s[0] == '-') y = -y;
      A[i] = y;
      z++;
    }
  }
  if (k == 0) {
    if (A[0] == 0)
      printf("Yes\n");
    else if (A[0] == -10001 && z % 2 == 1)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
  }
  if (x != 0) {
    if (n % 2 == 1)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
  }
  if (k == 1 || k == -1) {
    ans = 0;
    for (int i = (0); i <= (n); i++) {
      if (k < 0 && i % 2 == 1)
        w = -1;
      else
        w = 1;
      A[i] *= w;
      ans += A[i];
    }
    if (ans == 0)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
  }
  for (int i = (0); i <= (n); i++) {
    k = ww;
    if (k < 0 && i % 2 == 1)
      w = -1;
    else
      w = 1;
    k = abs(k);
    if (A[i] * w > 0) {
      w = 0;
      x = abs(A[i]);
      while (x > 0) {
        tmp[w++] = x % k;
        x /= k;
      }
      for (int j = (0); j < (w); j++) add[j + i] += tmp[j];
    } else if (A[i] * w < 0) {
      w = 0;
      x = abs(A[i]);
      while (x > 0) {
        tmp[w++] = x % k;
        x /= k;
      }
      for (int j = (0); j < (w); j++) minu[j + i] += tmp[j];
    }
  }
  k = abs(k);
  for (int i = (0); i < (200000); i++) {
    add[i + 1] += add[i] / k;
    add[i] %= k;
  }
  for (int i = (0); i < (200000); i++) {
    minu[i + 1] += minu[i] / k;
    minu[i] %= k;
  }
  for (int i = (0); i < (200000); i++)
    if (add[i] != minu[i]) {
      printf("No\n");
      return 0;
    }
  printf("Yes\n");
  return 0;
}

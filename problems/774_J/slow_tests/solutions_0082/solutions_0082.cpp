#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  char str[101];
  scanf("%s%n", str, &n);
  char cur[101];
  for (int i = 0; i + k - 1 < n; ++i) {
    char cur[101];
    int j = i + k - 1;
    for (int l = 0; l < n; ++l) {
      cur[l] = str[l];
    }
    for (int l = 0; l < n; ++l) {
      if (i <= l && l <= j) {
        if (str[l] == '?') {
          cur[l] = 'N';
        }
      } else {
        if (str[l] == '?') {
          cur[l] = 'Y';
        }
      }
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      while (i < n && cur[i] == 'N') {
        ++cnt;
        ++i;
      }
      if (cnt > 0) {
        --i;
        if (cnt > mx) {
          mx = cnt;
        }
      }
    }
    if (mx == k) {
      printf("%c%c%c", 'Y', 'E', 'S');
      return 0;
    }
  }
  printf("%c%c", 'N', 'O');
  return 0;
}

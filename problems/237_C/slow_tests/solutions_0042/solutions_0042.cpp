#include <bits/stdc++.h>
using namespace std;
int a, b, k, l = 1;
int lEnd, xEnd;
int arr[1000002];
int m = -1;
int start = 1, en;
bool flag;
int srch(int s, int e) { return (s + e) / 2; }
bool check(int p) {
  if (p < 2) return false;
  if (p == 2) return true;
  for (int i = 2; i <= sqrt(p); i++) {
    if ((p % i) == 0) return false;
  }
  return true;
}
int main() {
  scanf("%d%d%d", &a, &b, &k);
  arr[a] = 0;
  lEnd = b - a + 1;
  m = -1;
  int h;
  en = lEnd;
  start = 1;
  l = (start + en) / 2;
  h = en;
  int cnt = 0;
  bool flag;
  while (start <= en || start == (en + 2)) {
    xEnd = b - l + 1;
    for (int i = a + cnt; i <= xEnd + l; i++) {
      if (check(i))
        arr[i + 1] = arr[i] + 1;
      else
        arr[i + 1] = arr[i];
      cnt++;
    }
    en = h;
    for (int i = a; i <= xEnd; i++) {
      if (arr[i + l] - arr[i] >= k)
        flag = true;
      else {
        flag = false;
        break;
      }
    }
    if (flag) {
      m = l;
      en = l - 1;
      l = (l - 1 + start) / 2;
    } else {
      start = l + 1;
      l = (en + l + 1) / 2;
    }
  }
  printf("%d", m);
  return 0;
}

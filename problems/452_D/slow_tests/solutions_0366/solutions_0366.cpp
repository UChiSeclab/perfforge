#include <bits/stdc++.h>
using namespace std;
int k, n1, n2, n3, t1, t2, t3, t, num;
int a[10000], b[10000], c[10000], l, r;
bool check1(int x) {
  num = 0;
  for (int i = l; i < r; i++)
    if (a[i] > x) num++;
  if (num < n1) return 1;
  return 0;
}
bool check2(int x) {
  num = 0;
  for (int i = l; i < r; i++)
    if (b[i] > x) num++;
  if (num < n2) return 1;
  return 0;
}
bool check3(int x) {
  num = 0;
  for (int i = l; i < r; i++)
    if (c[i] > x) num++;
  if (num < n3) return 1;
  return 0;
}
int main() {
  scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
  for (t = 0; l < k; t++) {
    while (r < k && check1(t) && check2(t + t1) && check3(t + t1 + t2)) {
      a[r] = t + t1;
      b[r] = t + t1 + t2;
      c[r] = t + t1 + t2 + t3;
      r++;
    }
    while (t == c[l] && l <= r) l++;
  }
  printf("%d\n", t - 1);
}

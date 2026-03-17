#include <bits/stdc++.h>
int ins[10];
int num;
int dp[10100];
int finds(int l, int r, int tt, int number) {
  if (l == r) {
    if (dp[l] < tt) {
      return number - l - 1;
    } else {
      return number - l;
    }
  }
  int mid = (l + r) / 2;
  if (dp[mid] < tt) {
    return finds(mid + 1, r, tt, number);
  } else {
    return finds(l, mid, tt, number);
  }
}
int ask1(int x, int number) {
  int tt = x - ins[4] + 1;
  if (tt < 0) tt = 0;
  int ks = finds(1, number - 1, tt, number);
  return ks;
}
int ask2(int x, int number) {
  int tt = x - ins[5] + 1;
  if (tt < 0) tt = 0;
  int ks = finds(1, number - 1, tt, number);
  return ks;
}
int ask3(int x, int number) {
  int tt = x - ins[6] + 1;
  if (tt < 0) tt = 0;
  int ks = finds(1, number - 1, tt, number);
  return ks;
}
int ok(int x, int number) {
  int wt1 = ask1(x, number);
  if (wt1 >= ins[1]) {
    return 0;
  }
  int wt2 = ask2(x, number);
  if (wt2 >= ins[2]) {
    return 0;
  }
  int wt3 = ask3(x, number);
  if (wt3 >= ins[3]) {
    return 0;
  }
  return 1;
}
int gvdp(int l, int r, int number) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (ok(mid, number)) {
    return gvdp(l, mid, number);
  } else {
    return gvdp(mid + 1, r, number);
  }
}
int main() {
  while (scanf("%d", &num) != EOF) {
    for (int i = 1; i <= 6; i++) {
      scanf("%d", &ins[i]);
    }
    dp[1] = 0;
    for (int i = 2; i <= num; i++) {
      int t1 = dp[i - 1];
      int t2 = t1 + 1001;
      dp[i] = gvdp(t1, t2, i);
    }
    printf("%d\n", dp[num] + ins[4] + ins[5] + ins[6]);
  }
  return 0;
}

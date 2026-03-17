#include <bits/stdc++.h>
using namespace std;
int k[1000005], d[1000005], s[1000005], n, q, maxx, freee;
int ti, ki, di;
void settFree(int sec) {
  for (int i = 1; i <= n; ++i)
    if (sec == s[i]) s[i] = 0;
}
int countFree() {
  int ret = 0;
  for (int i = 1; i <= n; ++i)
    if (!s[i]) ++ret;
  return ret;
}
int getAns(int sec, int cnt, int time) {
  int ret = 0, solved = 0;
  for (int i = 1; i <= n; ++i) {
    if (!s[i]) {
      s[i] = sec + time;
      ret += i;
      ++solved;
      if (solved == cnt) return ret;
    }
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d %d", &ti, &ki, &di);
    k[ti] = ki;
    d[ti] = di;
    maxx = max(maxx, ti);
  }
  for (int i = 1; i <= maxx; ++i) {
    settFree(i);
    if (!k[i]) continue;
    freee = countFree();
    if (freee < k[i]) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", getAns(i, k[i], d[i]));
  }
  return 0;
}

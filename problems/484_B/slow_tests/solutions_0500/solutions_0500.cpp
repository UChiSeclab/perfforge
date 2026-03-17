#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXV = 1000000;
int N;
int it[MAXV * 4 + 100];
bool dau[MAXV + 10];
int fast_int() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int res = 0;
  while (c >= '0' && c <= '9') {
    res = res * 10 + (c - '0');
    c = getchar();
  }
  return res;
}
void nhap() {
  N = fast_int();
  memset(dau, 0, sizeof(dau));
  for (int i = 1; i <= N; i++) {
    int t = fast_int();
    dau[t] = 1;
  }
}
void update(int u, int l, int r, int k) {
  it[k] = max(it[k], u);
  if (l == r) return;
  int mid = (l + r) / 2;
  if (u <= mid)
    update(u, l, mid, (k << 1));
  else
    update(u, mid + 1, r, (k << 1) + 1);
}
int get(int u, int v, int l, int r, int k) {
  if (u > r || v < l) return 0;
  if (u <= l && v >= r) return it[k];
  if (it[k] == 0) return 0;
  int mid = (l + r) / 2;
  int t2 = get(u, v, mid + 1, r, (k << 1) + 1);
  if (t2 > 0) return t2;
  int t1 = get(u, v, l, mid, (k << 1));
  return t1;
}
void tinh() {
  int res = 0;
  memset(it, 0, sizeof(it));
  for (int i = MAXV; i >= 1; i--)
    if (dau[i]) {
      if (res > i) break;
      update(i, 1, MAXV, 1);
      int l = i;
      while (l <= MAXV) {
        int r = min(l + i - 1, MAXV);
        int t = get(l, r, 1, MAXV, 1);
        if (t != 0) {
          res = max(res, t - l);
        }
        if (t == i - 1) break;
        l = r + 1;
      }
    }
  printf("%d\n", res);
}
int main() {
  nhap();
  tinh();
  fclose(stdin);
  return 0;
}

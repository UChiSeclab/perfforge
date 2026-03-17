#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int cnt[N];
int a[N][2];
int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    int foo;
    scanf("%d", &foo);
    ++cnt[foo];
  }
  while (k--) {
    for (int i = 0, j = 0; i < N; ++i) {
      a[i][j] = cnt[i] / 2;
      a[i][1 - j] = (cnt[i] + 1) / 2;
      j = (j + cnt[i]) % 2;
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < N; ++i) {
      cnt[i] += a[i][0];
      cnt[i ^ x] += a[i][1];
    }
  }
  int mx = -1, mn = N;
  for (int i = 0; i < N; ++i) {
    if (cnt[i]) mx = i;
    if (cnt[N - 1 - i]) mn = N - 1 - i;
  }
  printf("%d %d", mx, mn);
}

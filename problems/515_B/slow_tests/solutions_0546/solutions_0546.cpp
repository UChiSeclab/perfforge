#include <bits/stdc++.h>
using namespace std;
bool m[105], h[105];
int n, M, fm, fh, x;
bool dp[105][105];
int main() {
  scanf("%d%d%d", &n, &M, &fm);
  for (int i = 0; i < fm; ++i) {
    scanf("%d", &x);
    m[x] = 1;
  }
  scanf("%d", &fh);
  for (int i = 0; i < fh; ++i) {
    scanf("%d", &x);
    h[x] = 1;
  }
  if (fm == n && fh == M) {
    puts("Yes");
    return 0;
  }
  int d, i, j;
  d = i = j = 0;
  while (d <= 1000000) {
    dp[i][j] = 1;
    if (m[i] || h[j]) {
      if (!m[i]) fm++;
      if (!h[j]) fh++;
      m[i] = h[j] = 1;
    }
    if (fm == n && fh == M) {
      puts("Yes");
      return 0;
    }
    d++;
    i = d % n;
    j = d % M;
  }
  if (fm == n && fh == M)
    puts("Yes");
  else
    puts("No");
  return 0;
}

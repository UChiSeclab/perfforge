#include <bits/stdc++.h>
using namespace std;
long long n, t[5000005], save[5000005], a[1000005], b[1000005], pown, l, r, ad;
void solv(long long x) {
  for (int i = x - 1; i >= 1; i--) {
    a[i] -= b[i];
    a[i] = max(a[i], 0LL);
    long long ind = i - 1;
    if (!ind && x != 1) ind = n;
    if (a[i] > 0 && b[ind] < a[i]) {
      printf("NO\n");
      return;
    }
    b[ind] -= a[i];
  }
  for (int i = n; i >= x; i--) {
    a[i] -= b[i];
    a[i] = max(a[i], 0LL);
    long long ind = i - 1;
    if (i == x) ind = 0;
    if (a[i] > 0 && a[i] > b[ind]) {
      printf("NO\n");
      return;
    }
    b[ind] -= a[i];
  }
  printf("YES\n");
}
void add(long long x, long long L, long long R) {
  if (L > r || R < l) return;
  if (L >= l && R <= r) {
    t[x] += ad;
    save[x] += ad;
    return;
  }
  if (save[x]) {
    t[2 * x] += save[x];
    t[2 * x + 1] += save[x];
    save[2 * x] += save[x];
    save[2 * x + 1] += save[x];
    save[x] = 0;
  }
  add(2 * x, L, (L + R) / 2);
  add(2 * x + 1, (L + R) / 2 + 1, R);
  t[x] = t[2 * x];
  if (t[2 * x + 1] < t[x]) t[x] = t[2 * x + 1];
}
void solve() {
  scanf("%I64d", &n);
  pown = 1;
  while (pown <= n) pown *= 2;
  for (int i = 1; i <= 2 * pown; i++) {
    t[i] = 0;
    save[i] = 0;
  }
  long long asum = 0, bsum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    asum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &b[i]);
    bsum += b[i];
  }
  for (int i = 1; i <= n; i++) {
    l = i, r = n, ad = b[i] - a[i];
    add(1, 1, pown);
  }
  if (t[1] >= 0) {
    solv(1);
    return;
  }
  for (int i = 1; i < n; i++) {
    l = 1, r = pown, ad = -(b[i] - a[i]);
    add(1, 1, pown);
    l = i, r = i, ad = -asum + a[i] + bsum - b[i] + (b[i] - a[i]);
    add(1, 1, pown);
    if (t[1] >= 0) {
      solv(i + 1);
      return;
    }
  }
  printf("NO\n");
}
int main() {
  long long q;
  cin >> q;
  while (q--) solve();
  return 0;
}

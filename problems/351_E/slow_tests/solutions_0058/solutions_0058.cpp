#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, maxm = 1e5 + 5;
int a[maxn], b[maxn], seg[4 * maxm];
void add(int id, int L, int R, int idx, int x) {
  if (idx < L || idx >= R) return;
  if (R == L + 1) {
    seg[id] += x;
    return;
  }
  int mid = (L + R) / 2;
  add(2 * id + 0, L, mid, idx, x);
  add(2 * id + 1, mid, R, idx, x);
  seg[id] = seg[2 * id + 0] + seg[2 * id + 1];
}
int get(int id, int L, int R, int l, int r) {
  if (R <= l || r <= L) return 0;
  if (L >= l && R <= r) return seg[id];
  int mid = (L + R) / 2;
  return get(2 * id + 0, L, mid, l, r) + get(2 * id + 1, mid, R, l, r);
}
int main() {
  int n;
  cin >> n;
  int inv = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
    inv += get(1, 0, maxm, a[i] + 1, maxm);
    b[i] = get(1, 0, maxm, 0, a[i]);
    add(1, 0, maxm, a[i], +1);
  }
  for (int i = 0; i < n; i++) {
    int c = get(1, 0, maxm, 0, a[i]);
    c -= b[i];
    if (c > b[i]) inv -= c - b[i];
  }
  cout << inv;
}

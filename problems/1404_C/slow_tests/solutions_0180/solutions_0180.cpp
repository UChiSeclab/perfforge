#include <bits/stdc++.h>
using namespace std;
const long oo = 1e9 + 7, o = 300005;
long n, q, a, rm[4 * o], kq[o];
pair<pair<long, long>, long> tv[o];
pair<long, long> mx[4 * o];
void downmx(long first) {
  mx[2 * first].first += mx[first].second;
  mx[2 * first].second += mx[first].second;
  mx[2 * first + 1].first += mx[first].second;
  mx[2 * first + 1].second += mx[first].second;
  mx[first].second = 0;
}
void upmx(long first, long l, long r, long u, long v, long gt) {
  if (v < l || u > r) return;
  if (u <= l && r <= v) {
    mx[first].first += gt;
    mx[first].second += gt;
    return;
  }
  downmx(first);
  long mid = (l + r) >> 1;
  upmx(2 * first, l, mid, u, v, gt);
  upmx(2 * first + 1, mid + 1, r, u, v, gt);
  mx[first].first = max(mx[2 * first].first, mx[2 * first + 1].first);
}
long getmx(long first, long l, long r, long u, long v) {
  if (v < l || u > r) return -oo;
  if (u <= l && r <= v) return mx[first].first;
  downmx(first);
  long mid = (l + r) >> 1;
  long g1 = getmx(2 * first, l, mid, u, v);
  long g2 = getmx(2 * first + 1, mid + 1, r, u, v);
  return max(g1, g2);
}
void uprm(long first, long l, long r, long vt, long gt) {
  if (vt < l || vt > r) return;
  if (l == r) {
    rm[first] += gt;
    return;
  }
  long mid = (l + r) >> 1;
  uprm(2 * first, l, mid, vt, gt);
  uprm(2 * first + 1, mid + 1, r, vt, gt);
  rm[first] = rm[2 * first] + rm[2 * first + 1];
}
long getrm(long first, long l, long r, long u, long v) {
  if (v < l || u > r || u > v) return 0;
  if (u <= l && r <= v) return rm[first];
  long mid = (l + r) >> 1;
  long g1 = getrm(2 * first, l, mid, u, v);
  long g2 = getrm(2 * first + 1, mid + 1, r, u, v);
  return g1 + g2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long i = 1; i <= n; i++) {
    cin >> a;
    if (a > i) a = -oo;
    upmx(1, 1, n, i, i, a - i);
  }
  for (long i = 1; i <= q; i++) {
    cin >> tv[i].first.first >> tv[i].first.second;
    tv[i].first.first += 1;
    tv[i].first.second = n - tv[i].first.second;
    tv[i].second = i;
  }
  sort(tv + 1, tv + 1 + q);
  for (long i = q; i >= 1; i--) {
    while (1) {
      long l = tv[i].first.first, r = n, mid;
      while (l < r) {
        long mid = (l + r + 1) >> 1;
        if (getmx(1, 1, n, mid, n) >= 0)
          l = mid;
        else
          r = mid - 1;
      }
      if (getmx(1, 1, n, l, n) != 0) break;
      upmx(1, 1, n, l, l, -oo);
      upmx(1, 1, n, l + 1, n, 1);
      uprm(1, 1, n, l, 1);
    }
    kq[tv[i].second] = getrm(1, 1, n, tv[i].first.first, tv[i].first.second);
  }
  for (long i = 1; i <= q; i++) cout << kq[i] << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 1000000007LL;
int n;
vector<int64_t> a(5), b(5), c(5), s(5);
int64_t maxscore(int64_t s, int64_t n) {
  if (s * 2 > n) return 500;
  if (s * 4 > n) return 1000;
  if (s * 8 > n) return 1500;
  if (s * 16 > n) return 2000;
  if (s * 32 > n) return 2500;
  return 3000;
}
bool win(int64_t mid) {
  int64_t sa = 0, sb = 0;
  for (int i = 0; i < 5; i++) {
    int64_t m = maxscore(s[i] + c[i] * mid, n + mid);
    if (a[i] >= 0) sa += m * (250 - a[i]) / 250;
    if (b[i] >= 0) sb += m * (250 - b[i]) / 250;
  }
  return sa > sb;
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int64_t x;
      cin >> x;
      if (x >= 0) s[j]++;
      if (i == 0) a[j] = x;
      if (i == 1) b[j] = x;
    }
  }
  int64_t minx = -1;
  for (int i = 0; i < 32; i++) {
    bool ok = true;
    for (int j = 0; j < 5; j++) {
      c[j] = (i >> j) & 1;
      if (c[j] && a[j] < 0) ok = false;
    }
    if (!ok) continue;
    int64_t x;
    for (x = 0; x < 100000; x++)
      if (win(x)) break;
    if (x == 100000) x = -1;
    for (int j = 0; j < 5; j++) cerr << c[j];
    cerr << ' ' << x << endl;
    minx = x >= 0 && (minx < 0 || x < minx) ? x : minx;
  }
  cout << minx << endl;
  return 0;
}

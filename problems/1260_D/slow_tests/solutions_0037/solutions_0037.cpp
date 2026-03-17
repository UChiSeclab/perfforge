#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 * 2;
long long n, m, k, t, niz[MAXN + 5], r, najm, najv, br, nes[MAXN + 5];
pair<long long, pair<long long, long long> > niz1[MAXN + 5];
int main() {
  cin >> n >> k >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> niz[i];
  }
  sort(niz, niz + n);
  for (int i = 0; i < m; i++) {
    cin >> niz1[i].first >> niz1[i].second.first >> niz1[i].second.second;
  }
  long long hi = n, mid, lo = 0;
  while (hi > lo) {
    najv = 0;
    mid = (hi + lo) / 2;
    r = niz[mid];
    for (int i = 0; i < m; i++) {
      if (r < niz1[i].second.second && niz1[i].second.first >= niz1[i].first) {
        nes[niz1[i].second.first]--;
        nes[niz1[i].first - 1]++;
      }
    }
    br = 0;
    for (int i = 0; i < MAXN + 3; i++) {
      br += nes[i];
      nes[i] = 0;
      if (br > 0) {
        najv += 2;
      }
    }
    if (najv + k + 1 <= t) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << n - hi;
  return 0;
}

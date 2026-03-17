#include <bits/stdc++.h>
using namespace std;
long long n, m, a[400005], sum, le, ri, mid, mp[400005], f, ans, v[400005], cnt,
    raod;
pair<long long, long long> b[400005];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  sort(b + 1, b + m + 1);
  le = 1;
  ri = 2 * sum;
  while (le <= ri) {
    raod = 0;
    mid = (le + ri) / 2;
    f = 0;
    cnt = 0;
    for (int i = 1; i <= 400005; i++) {
      v[i] = 0;
      mp[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      if (b[i].first <= mid) {
        mp[b[i].second] = b[i].first;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (mp[i]) v[mp[i]] += a[i];
    }
    raod = sum;
    for (int i = 1; i <= mid; i++) {
      cnt++;
      if (v[i] <= cnt) {
        cnt -= v[i];
        raod -= v[i];
      } else {
        raod -= cnt;
        cnt = 0;
      }
    }
    if (cnt - 2 * raod >= 0) {
      ans = mid;
      ri = mid - 1;
    } else {
      le = mid + 1;
    }
  }
  cout << ans << endl;
}

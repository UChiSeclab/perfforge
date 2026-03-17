#include <bits/stdc++.h>
using namespace std;
void smain();
int main() {
  ios_base::sync_with_stdio(0);
  smain();
  return 0;
}
long long n, t;
long long a[1001], d[1001];
long long pd[1001];
long long naive() {
  vector<long long> dp(n, 1);
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < i; j++)
      if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
  for (long long k = 0; k < t - 1; k++) {
    for (long long i = 0; i < n; i++) {
      long long cur = 0;
      for (long long j = 0; j < n; j++)
        if (a[j] <= a[i]) cur = max(cur, dp[j] + 1);
      dp[i] = cur;
    }
  }
  return *max_element(dp.begin(), dp.end());
}
long long solve() {
  for (long long i = 0; i < n; i++) d[i] = 1;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < i; j++)
      if (a[j] <= a[i]) d[i] = max(d[j] + 1, d[i]);
  for (long long i = 0; i < n; i++) pd[i] = d[i];
  vector<long long> p(n), np(n);
  long long k = t - 1;
  for (; k > 0; --k) {
    for (long long i = 0; i < n; i++) {
      long long cur = 0;
      for (long long j = 0; j < n; j++)
        if (a[j] <= a[i]) cur = max(cur, d[j] + 1);
      np[i] = cur - d[i];
      pd[i] = d[i];
      d[i] = cur;
    }
    bool ok = true;
    for (long long i = 0; i < n; i++)
      if (p[i] != np[i]) {
        ok = false;
        break;
      }
    swap(p, np);
    if (ok) break;
  }
  if (k == 0) return *max_element(d, d + n);
  long long res = 0;
  for (long long i = 0; i < n; i++) res = max(res, pd[i] + p[i] * k);
  return res;
}
void smain() {
  for (; cin >> n >> t;) {
    for (long long i = 0; i < n; i++) cin >> a[i];
    cout << solve() << endl;
  }
}

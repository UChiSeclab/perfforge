#include <bits/stdc++.h>
using namespace std;
long long n, r1, r2, r3, d;
long long it[1000001];
long long pre[1000001];
long long pre2[1000001];
long long dp[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (long long i = 0; i < n; i++) {
    cin >> it[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long mi = it[i] * r1 + r3;
    mi = min(mi, min(r2 + r1, (it[i] + 2) * r1));
    pre2[i + 1] = pre2[i] + mi;
  }
  multiset<long long> cur;
  multiset<long long> cur2;
  long long ba = 0;
  for (long long i = 0; i < n; i++) {
    dp[i] = pre2[i + 1] + 2 * d * i;
    if (i == 0) {
      dp[i] += 2 * d;
    }
    if (cur.size() > 0) {
      long long xx = *cur.begin();
      dp[i] = min(dp[i], pre2[i + 1] + xx + 2 * i * d);
    }
    if (i > 0) {
      dp[i] = min(dp[i], dp[i - 1] + it[i] * r1 + r3);
    } else {
      dp[i] = min(dp[i], it[i] * r1 + r3);
    }
    if (i == n - 1) {
      long long ans = dp[n - 1];
      long long xx = *cur2.begin();
      ans = min(ans, pre2[i + 1] + xx + i * d + 2 * d);
      ans = min(ans, pre2[i] + xx + i * d + it[i] * r1 + r3);
      ans = min(ans, dp[n - 3] + pre2[i + 1] - pre2[i - 1] + 2 * d);
      cout << ans + (n - 1) * d << endl;
      return 0;
    }
    long long cot = 0;
    if (i > 0) {
      cot = dp[i - 1];
    }
    cur.insert(-pre2[i] - 2 * i * d + cot);
    cur2.insert(-pre2[i] - i * d + cot);
  }
  return 0;
  for (long long i = 0; i < n; i++) {
    long long kk = 0;
    if (cur.size()) {
      long long xx = *(cur.begin());
      xx += pre2[i + 1];
      xx += i * d * 2;
      kk = xx;
    }
    cur.insert(ba - pre2[i] - i * 2 * d);
    cur2.insert(ba - pre2[i] - i * d);
    ba = ba + it[i] * r1 + r3;
    ba = min(ba, kk + it[i] * r1 + r3);
    cout << ba << ":" << kk << endl;
    if (i == n - 1) {
      long long ans = ba;
      long long xx = *(cur2.begin());
      xx += pre2[i] +
            min(it[i] * r1 + r3, 2 * d + min(r2 + r1, (it[i] + 2) * r1));
      xx += i * d;
      ans = min(ans, xx);
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
  for (long long i = 0; i < n; i++) {
    long long mi = it[i] * r1 + r3;
    mi = min(mi, 2 * d + min(r2 + r1, (it[i] + 2) * r1));
    pre[i] = mi;
    if (i > 0) {
      pre[i] += pre[i - 1];
    }
  }
  ans += pre[n - 1];
  for (long long i = 0; i < n; i++) {
    cout << pre[i] << ":";
  }
  cout << endl;
  long long su = 0;
  long long ii = n - 1;
  long long mii = it[ii] * r1 + r3;
  mii = min(mii, 3 * d + min(r2 + r1, (it[ii] + 2) * r1));
  su += mii;
  long long maa = it[ii] * r1 + r3;
  maa = min(maa, min(r2 + r1, (it[ii] + 2) * r1));
  cout << mii << "//" << maa << endl;
  for (long long i = n - 2; i >= 0; i--) {
    su += d;
    long long ma = it[i] * r1 + r3;
    ma = min(ma, min(r2 + r1, (it[i] + 2) * r1));
    su += ma;
    long long coo = 0;
    if (i > 0) {
      coo += pre[i - 1];
    }
    ans = min(ans, su + coo);
    long long cot = su + coo + (n - 1 - i) * d;
    cot -= mii;
    cot += maa;
    ans = min(ans, cot);
    cout << coo + su << ":";
  }
  cout << endl;
  cout << ans + (n - 1) * d << endl;
  return 0;
}

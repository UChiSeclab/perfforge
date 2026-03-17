#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 998244353;
long long int hash1[400005];
long long int a[400005];
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    hash1[a[i]]++;
  }
  for (long long int i = 1; i <= 400000; i++) {
    hash1[i] += hash1[i - 1];
  }
  long long int ans = INT_MAX;
  for (long long int i = 1; i <= 200000; i++) {
    long long int ck = 0;
    long long int j = i;
    long long int tt = hash1[j] - hash1[j - 1];
    if (tt >= k) {
      ans = min(ans, 0LL);
      break;
    }
    j *= 2;
    long long int cur = 0;
    long long int ok = 2;
    while (j <= 200000) {
      long long int freq = hash1[j + ok - 1] - hash1[j - 1];
      if (tt + freq > k) {
        freq = k - tt;
      }
      tt += freq;
      ck++;
      cur = cur + ck * freq;
      j *= 2;
      ok *= 2;
      if (tt >= k) break;
    }
    if (tt >= k) ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
long long arr[N], l[N], d[N], r[N], m, n, k, t;
long long first(long long m1) {
  long long num = arr[m1], time1 = 0;
  long long arr1[200005];
  memset(arr1, 0, sizeof(arr));
  for (int i = 1; i <= k; i++) {
    if (d[i] > num) {
      arr1[l[i]]++;
      arr1[r[i] + 1]--;
    }
  }
  for (int i = 1; i < 200005; i++) arr1[i] += arr1[i - 1];
  for (int i = 0; i <= n; i++) {
    if (arr1[i + 1] == 0) {
      time1++;
      continue;
    } else {
      long long track = i, count1 = 0;
      while (track <= n && arr1[track + 1] > 0) {
        track++;
        count1++;
      }
      time1 += 3 * count1;
      i += count1 - 1;
    }
  }
  return (time1);
}
long long binary_search(long long l1, long long h1) {
  while (l1 < h1) {
    long long m1 = l1 + (h1 - l1) / 2;
    if (first(m1) <= t)
      h1 = m1;
    else
      l1 = m1 + 1;
  }
  return (l1);
}
void solve() {
  cin >> m >> n >> k >> t;
  for (int i = 1; i <= m; i++) cin >> arr[i];
  sort(arr + 1, arr + m + 1);
  for (int i = 1; i <= k; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }
  if (first(m) > t) {
    cout << "0\n";
    return;
  }
  cout << m - binary_search(1, m) + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}

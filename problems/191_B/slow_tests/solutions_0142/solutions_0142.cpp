#include <bits/stdc++.h>
using namespace std;
long long n, k, b, s, ans;
int main() {
  cin >> n >> k >> b;
  vector<pair<long long, long long> > a(n - 1);
  for (int i = 0; i < n - 1; i++) cin >> a[i].first, a[i].second = i;
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < k - 1; i++) s += a[i].first;
  ans = n - 1;
  for (int i = k; i < n - 1; i++)
    if (s + a[i].first > b) ans = min(ans, a[i].second);
  s += a[k - 1].first;
  if (s > b)
    for (int i = 0; i < k; i++) ans = min(ans, a[i].second);
  cout << ans + 1;
}

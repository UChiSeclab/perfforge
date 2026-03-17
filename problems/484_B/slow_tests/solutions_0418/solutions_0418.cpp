#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long has[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a;
  cin >> n;
  vector<long long> s;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    has[a] = 1;
    s.push_back(a);
  }
  sort(s.begin(), s.end());
  long long ans = 0;
  for (long long i = 1; i <= N; i++) {
    if (has[i])
      for (long long j = 2 * i; j <= N + i; j += i) {
        auto it = lower_bound(s.begin(), s.end(), j);
        if (it != s.begin()) {
          it--;
          ans = max(ans, *it % i);
        }
      }
  }
  cout << ans;
}

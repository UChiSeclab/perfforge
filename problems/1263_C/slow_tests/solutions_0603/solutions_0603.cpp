#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i;
    cin >> n;
    vector<long long> ans;
    ans.push_back(0);
    map<long long, long long> m;
    for (i = 1; i * i <= n; i++) {
      long long j = n / i;
      if (m[j] == 0) {
        m[j]++;
        ans.push_back(j);
      }
      j = n / j;
      if (m[j] == 0) {
        m[j]++;
        ans.push_back(j);
      }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}

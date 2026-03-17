#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, d, ans, count;
  cin >> t;
  vector<int> v(101);
  vector<bool> taken(101, false);
  while (t--) {
    cin >> n >> k >> d;
    ans = INT_MAX;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i + d <= n; i++) {
      count = 0;
      fill(taken.begin(), taken.end(), 0);
      for (int j = i; j < i + d; j++) {
        if (taken[v[j]] == false) count++;
        taken[v[j]] = true;
      }
      ans = min(ans, count);
    }
    cout << ans << "\n";
  }
}

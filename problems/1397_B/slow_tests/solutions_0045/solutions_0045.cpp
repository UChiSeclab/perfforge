#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  if (n > 32) {
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans = ans + arr[i] - 1;
    }
    cout << ans << "\n";
  } else {
    unsigned long long ans = 1e16;
    unsigned long long a1 = 0;
    for (int i = 1; i <= sqrt(arr[n - 1]) + 1; i++) {
      a1 = 0;
      for (int j = 0; j < n; j++) {
        a1 = a1 + (long long)abs((long long)pow(i, j) - arr[j]);
        a1 = min((unsigned long long)1e16, a1);
      }
      ans = min(ans, a1);
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long t = 1;
  while (t--) solve();
}

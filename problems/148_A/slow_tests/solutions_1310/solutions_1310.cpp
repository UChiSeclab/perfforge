#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long d;
  long long arr[4];
  for (long long i = 0; i < 4; i++) cin >> arr[i];
  cin >> d;
  if (arr[0] == 1 || arr[1] == 1 || arr[2] == 1 || arr[3] == 1) {
    cout << d << "\n";
  } else {
    vector<bool> damage(d + 1, 1);
    for (long long i = 0; i < 4; i++) {
      for (long long j = arr[i]; j <= d; j += arr[i]) {
        damage[j] = 0;
      }
    }
    long long ans = 0;
    for (long long i = 1; i <= d; i++) {
      ans += damage[i];
    }
    cout << d - ans << "\n";
  }
  return 0;
}

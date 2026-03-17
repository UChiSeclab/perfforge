#include <bits/stdc++.h>
using namespace std;
long long arr[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int x = 14;
    if (x % (n - 1))
      x = x / (n - 1) + 1;
    else
      x = x / (n - 1);
    int range = 1;
    for (int i = 0; i < x; i++) range = range * 10;
    long long res = 1e18;
    for (int c = 1; c <= range; c++) {
      long long val = 1;
      long long tmp = 0;
      bool flag = true;
      for (int j = 0; j < n; j++) {
        if (val > 1e16 || val < 0 || tmp > 1e16 || tmp < 0) {
          flag = false;
          break;
        }
        if (arr[j] != val) tmp += abs(val - arr[j]);
        val = val * c;
      }
      if (flag) res = min(res, tmp);
    }
    cout << res << "\n";
  }
  return 0;
}

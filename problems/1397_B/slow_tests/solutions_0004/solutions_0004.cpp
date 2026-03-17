#include <bits/stdc++.h>
using namespace std;
void solve(vector<long long> a, long long n) {
  long long big = (long long)1e15;
  long long ans = big, c = 1, k = 0;
  while (1) {
    long long val = 0, pw = 1;
    for (long long i = 0; i < n; i++, pw *= c) {
      if (pw >= big) {
        val = -1;
        break;
      }
      val += abs(pw - a[i]);
    }
    if (val == -1) break;
    ans = min(ans, val);
    c++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  solve(arr, n);
  return 0;
}

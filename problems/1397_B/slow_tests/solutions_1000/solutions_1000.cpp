#include <bits/stdc++.h>
using namespace std;
long long int cost(vector<long long int> a, long long int n, long long int c) {
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    ans += abs(a[i] - pow(c, i));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (n >= 60) {
    cout << cost(a, n, 1) << '\n';
  } else {
    long long int l = 1;
    double temp = 18 / (n + 0.0);
    long long int r = floor(pow(10, temp));
    long long int ans = LLONG_MAX;
    for (long long int i = l; i <= r; i++) {
      ans = min(ans, cost(a, n, i));
    }
    cout << ans << '\n';
  }
}

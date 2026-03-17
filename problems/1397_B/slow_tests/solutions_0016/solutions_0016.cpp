#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long c = 1, minCost = 1e17, f = 0, ans;
  while (pow(c, n - 1) < 1e13) {
    long long cost = 0;
    for (int i = 0; i < n; i++) {
      cost += abs(a[i] - pow(c, i));
    }
    minCost = min(minCost, cost);
    c++;
  }
  cout << minCost << "\n";
}
int main() {
  fast_io();
  solve();
  return 0;
}

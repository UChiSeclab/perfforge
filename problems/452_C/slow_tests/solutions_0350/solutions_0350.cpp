#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
int n, m;
double ans;
double logC(int n, int r) {
  double ans = 0;
  for (int i = 1; i <= r; i++) ans += log(n - i + 1);
  for (int i = 1; i <= r; i++) ans -= log(i);
  return ans;
}
double calc(int k) {
  return logC((n - 1) * m, (n - k)) + logC(m, k) + log(k) * 2 - log(n) * 2;
}
int main() {
  ios ::sync_with_stdio(0);
  cin >> n >> m;
  double mul = log(n) - logC(n * m, n);
  for (int i = 1; i <= min(n, m); i++) ans += exp(calc(i) + mul);
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}

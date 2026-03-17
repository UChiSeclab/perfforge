#include <bits/stdc++.h>
using namespace std;
long double nCr(unsigned long long n, unsigned long long r) {
  if (n < r) return 0;
  if (n == r) return 1;
  return (nCr(n - 1, r) / (n - r)) * n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  h--;
  n--;
  int sum = 0;
  vector<int> vec(m);
  for (auto i = 0; i < (long long)(m); i++) {
    cin >> vec[i];
    sum += vec[i];
  }
  sum--;
  vec[h]--;
  if (sum < n) return cout << -1, 0;
  long double res = 0;
  for (auto i = 1; i <= (long long)(vec[h]); i++) {
    int remR = n - i;
    int remN = sum - vec[h];
    long double a = nCr(remN, remR);
    long double b = nCr(vec[h], i);
    long double d = nCr(sum, n);
    res += (a / d) * b;
  }
  cout << fixed << setprecision(9) << res << '\n';
  return 0;
}

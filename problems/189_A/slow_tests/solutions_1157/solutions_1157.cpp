#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long i, j;
long long temp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long max = 0;
  for (i = 0; i < n + 1; i++) {
    for (j = 0; j < n + 1; j++) {
      long long k;
      k = n - (a * i + b * j);
      k /= c;
      if (a * i + b * j + c * k == n && i + j + k > max && k >= 0) {
        max = i + j + k;
      }
    }
  }
  cout << max;
  return 0;
}

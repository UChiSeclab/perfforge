#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, b;
  cin >> n >> b;
  map<long long, long long> m;
  for (long long i = 2; i <= sqrt(b); i++) {
    while (b % i == 0) {
      b /= i;
      m[i] += 1;
    }
  }
  if (b > 1) m[b] += 1;
  long long ans = 1e18;
  for (auto i : m) {
    long long x = i.first;
    long long temp = 0;
    while (x <= n) {
      temp += n / x;
      if (x <= (n / i.first)) {
        x *= i.first;
      } else {
        break;
      }
    }
    temp /= i.second;
    ans = min(ans, temp);
  }
  cout << ans << "\n";
}

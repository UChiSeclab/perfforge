#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6 + 100;
long long n, b, mn = 1e18 + 1000;
bool mark[MX];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> b;
  long long c = b;
  for (long long i = 2; i <= sqrt(c); i++) {
    if (c % i != 0 || mark[i]) continue;
    for (long long j = 2; j * i < MX; j++) mark[i * j] = 1;
    long long cnt = 0;
    while (b % i == 0) cnt++, b /= i;
    long long a = n, sum = 0;
    while (a) sum += a / i, a = a / i;
    mn = min(mn, sum / cnt);
  }
  if (b > 1) {
    long long a = n, sum = 0;
    while (a) sum += a = a / b;
    mn = min(mn, sum);
  }
  cout << mn << endl;
  return 0;
}

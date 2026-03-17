#include <bits/stdc++.h>
using namespace std;
long long int C(long long int n, long long int r);
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int kmin = 0, kmax = 0;
  long long int rem = n - m;
  kmax = (m == n ? 0 : C(rem + 1, 2));
  long long int nmin = 1;
  while (rem >= m) {
    rem -= m;
    nmin++;
  }
  kmin = (rem)*C(nmin + 1, 2) + (m - rem) * C(nmin, 2);
  cout << kmin << " " << kmax << '\n';
  return 0;
}
long long int C(long long int n, long long int r) {
  long long int i;
  long long int num = 1, den = 1;
  while (r) {
    num *= n - r + 1;
    den *= r;
    r--;
  }
  return num / den;
}

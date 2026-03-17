#include <bits/stdc++.h>
using namespace std;
long long int po(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return po((x * x) % 1000000007, n / 2);
  else
    return (x * po((x * x) % 1000000007, (n - 1) / 2)) % 1000000007;
}
long long int GCD(long long int A, long long int B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  long long int an = 0;
  for (int i = 1; i < b; ++i) {
    long long int d = i * a;
    long long int r = d / i;
    an += r * i;
    an %= 1000000007;
    long long int e = (r * (r + 1)) / 2;
    e %= 1000000007;
    e *= i;
    e %= 1000000007;
    e *= b;
    e %= 1000000007;
    an += e;
    an %= 1000000007;
  }
  cout << an;
}

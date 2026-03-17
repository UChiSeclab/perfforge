#include <bits/stdc++.h>
using namespace std;
long long in() {
  long long a;
  scanf("%lld", &a);
  return a;
}
bool isprime(long long n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n % 2) return 0;
  for (int i = 2; i <= sqrt(n) + 2; i++)
    if (n % i == 0) return 0;
  return 1;
}
long long dao(long long n) {
  for (int i = 2; i <= (sqrt(n)); i++)
    if (n % i == 0) return i;
}
int main() {
  long long a = in(), b = in();
  if (a == b) cout << -1 << endl, exit(0);
  if (a == 2) {
    if (b & 1)
      cout << b << endl;
    else
      cout << --b << endl;
    exit(0);
  }
  for (long long i = b; i >= a; i--) {
    if (dao(i) > a || isprime(i)) cout << i << endl, exit(0);
  }
  cout << -1 << endl;
}

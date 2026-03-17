#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long f(long long n) {
  if (n == 0) return a;
  if (n == 1) return b;
  return f(n - 1) + f(n - 2);
}
int main() {
  long long n;
  cin >> a >> b;
  cin >> n;
  cout << f(n);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void ok(int x) {
  cout << x << '\n';
  exit(0);
}
int main() {
  int n, p;
  cin >> n >> p;
  for (int k = 0; k < int(1e8); k++) {
    long long n1 = n - 1LL * p * k;
    if (n1 < 0) continue;
    if (n1 >= k && k >= __builtin_popcountll(n1)) ok(k);
  }
  ok(-1);
}

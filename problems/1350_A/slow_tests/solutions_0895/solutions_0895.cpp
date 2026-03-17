#include <bits/stdc++.h>
using namespace std;
void solve() {
  unsigned long long int n, k;
  cin >> n >> k;
  unsigned long long int temp = -1;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      temp = i;
      break;
    }
  }
  if (n & 1) {
    n = n + temp;
    k--;
  }
  cout << (n + k * 2) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unsigned long long int test;
  cin >> test;
  while (test--) solve();
  return 0;
}

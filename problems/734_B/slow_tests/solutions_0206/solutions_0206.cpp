#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int val[maxn];
long long res = 0;
int main() {
  ios::sync_with_stdio(false);
  int k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;
  for (int i = 0; i <= k2; i++) {
    if (i <= k2 and i <= k5 and i <= k6) {
      long long sum = i * 256;
      sum += min(k3, k2 - i) * 32;
      res = max(res, sum);
    }
  }
  cout << res;
}

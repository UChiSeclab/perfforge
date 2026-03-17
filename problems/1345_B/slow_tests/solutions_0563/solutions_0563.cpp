#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long sum[N];
int main() {
  sum[1] = 2;
  for (int i = 2; i < N; i++) sum[i] = sum[i - 1] + 3 * i - 1;
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int ans = 0;
    int l = N - 10;
    while (l) {
      if (!n) break;
      if (n >= sum[l]) {
        ans += n / sum[l];
        n %= sum[l];
      }
      l--;
    }
    cout << ans << endl;
  }
}

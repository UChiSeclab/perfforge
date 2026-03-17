#include <bits/stdc++.h>
using namespace std;
const int S = 2e5 + 1, inf = 1e9;
int n, k;
int a[S];
int cnt[S], res[S];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], cnt[a[i]]++;
    if (cnt[a[i]] >= k) {
      cout << 0;
      return 0;
    }
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    int tmp = a[i] >> 1;
    int b = 0;
    while (tmp) {
      b++;
      if (cnt[tmp] < k) {
        cnt[tmp]++;
        res[tmp] += b;
      }
      tmp >>= 1;
    }
  }
  int ans = inf;
  for (int i = 1; i <= S - 1; i++)
    if (cnt[i] >= k && ans > res[i]) ans = res[i];
  cout << ans;
}

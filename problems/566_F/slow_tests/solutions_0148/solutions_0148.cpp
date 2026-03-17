#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int cnt[maxn + 10];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    cnt[val] = max(cnt[val], 1);
    for (int tmp = val * 2; tmp <= maxn; tmp += val)
      cnt[tmp] = max(cnt[tmp], cnt[val] + 1);
    ans = max(ans, cnt[val]);
  }
  cout << ans << '\n';
  return 0;
}

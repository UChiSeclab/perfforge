#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mxn = 1e6;
int n, cnt[mxn + 5][2];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    ++cnt[l][0];
  }
  for (int i = 1e6; i >= 2; --i) {
    if ((cnt[i][0] & 1) && cnt[i][1] != cnt[i][0]) {
      --cnt[i][0];
      ++cnt[i - 1][0];
      ++cnt[i - 1][1];
    }
  }
  int j = 1e6;
  ll ans = 0;
  for (int i = 1e6; i >= 1; --i) {
    if (cnt[i][0] <= 1) continue;
    ans += cnt[i][0] / 4 * 1ll * i * i;
    cnt[i][0] %= 4;
    while (j > 0 && (j >= i || cnt[j][0] <= 1)) --j;
    if (j == 0) break;
    int add = min(cnt[j][0] / 2, cnt[i][0] / 2);
    ans += add * 1ll * i * j;
    cnt[j][0] -= add;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) solve();
}

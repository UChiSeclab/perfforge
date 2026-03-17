#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int leftt = 100000000;
int rightt = 0;
int le[5005];
int ri[5005];
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    r--;
    le[i] = l;
    ri[i] = r;
    dp[l]++;
    dp[r + 1]--;
  }
  for (int i = 1; i <= 1000000; i++) {
    dp[i] += dp[i - 1];
    if (dp[i] > 2) {
      cout << 0;
      return 0;
    }
  }
  for (int i = 0; i <= 1000000; i++) {
    if (dp[i] == 2) {
      leftt = min(leftt, i);
      rightt = max(rightt, i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (le[i] <= leftt && rightt <= ri[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) cout << i + 1 << " ";
  return 0;
}

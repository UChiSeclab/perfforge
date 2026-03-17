#include <bits/stdc++.h>
using namespace std;
int ans[300005];
int main() {
  int n;
  cin >> n;
  vector<int> cnt;
  for (int i = 0; i < n * 2; i++) {
    int x;
    cin >> x;
    cnt.push_back(x);
  }
  int ans = INT_MAX;
  for (int i = 0; i < cnt.size(); i++) {
    for (int e = 0; e < cnt.size(); e++) {
      if (i != e) {
        vector<int> tmp;
        for (int j = 0; j < cnt.size(); j++) {
          if (j != e && j != i) {
            tmp.push_back(cnt[j]);
          }
        }
        sort(tmp.begin(), tmp.end());
        int t = 0;
        for (int j = 1; j < tmp.size(); j += 2) {
          t += (tmp[j] - tmp[j - 1]);
        }
        ans = min(ans, t);
      }
    }
  }
  cout << ans;
  return 0;
}

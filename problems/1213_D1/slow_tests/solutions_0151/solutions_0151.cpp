#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long inf64 = 1e18;
const int mod = inf + 7;
const int N = 2e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  vector<int> values;
  for (int i = 0; i < n; i++) {
    int temp = a[i];
    while (temp) {
      values.push_back(temp);
      temp >>= 1;
    }
  }
  int ans = inf;
  for (int x : values) {
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
      int cur = 0, temp = a[i];
      while (temp > x) {
        temp >>= 1;
        cur++;
      }
      if (temp == x) cnt.push_back(cur);
    }
    if ((int)cnt.size() < k) continue;
    sort((cnt).begin(), (cnt).end());
    ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
  }
  cout << ans;
}

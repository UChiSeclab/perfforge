#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100 * 2 + 10;
long long int a[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = MAXN;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < MAXN; i++) {
    vector<int> v;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      int t = a[j], c = 0;
      while (t > i) {
        c++;
        t /= 2;
      }
      if (t == i) {
        cnt++;
        v.push_back(c);
      }
    }
    if (cnt >= k) {
      sort(v.begin(), v.end());
      int d = 0;
      for (int j = 0; j < k; j++) {
        d += v[j];
      }
      ans = min(ans, d);
    }
  }
  cout << ans << endl;
  return 0;
}

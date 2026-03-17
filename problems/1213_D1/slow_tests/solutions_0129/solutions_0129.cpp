#include <bits/stdc++.h>
int mod = 1000000007;
const double pi = 3.141592653689793238460;
const int inf = 0x3f3f3f3f;
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[10005];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 0) {
      pos.push_back(x);
      x /= 2;
    }
  }
  int ans = inf;
  for (auto x : pos) {
    vector<int> cur;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      int y = a[i];
      while (y > x) {
        y /= 2;
        cnt++;
      }
      if (y == x) {
        cur.push_back(cnt);
      }
    }
    if (cur.size() < k) continue;
    sort(cur.begin(), cur.end());
    ans = min(ans, accumulate(cur.begin(), cur.begin() + k, 0));
  }
  cout << ans << endl;
}

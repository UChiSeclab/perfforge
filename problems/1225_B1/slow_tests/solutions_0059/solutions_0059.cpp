#include <bits/stdc++.h>
using namespace std;
int n, k, d;
const int MAXN = 2e5 + 7;
const int MAXK = 1e6 + 7;
int hist[MAXK], arr[MAXN];
int uniq = 0;
inline void add(int pos, int x) {
  if (x == 1 && hist[pos] == 0) uniq++;
  hist[pos] += x;
  if (x == -1 && hist[pos] == 0) uniq--;
}
inline void init() {
  fill(hist, hist + MAXK, 0);
  uniq = 0;
}
inline void solve() {
  init();
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < d; i++) {
    add(arr[i], 1);
  }
  int ans = uniq;
  for (int i = d; i < n; i++) {
    add(arr[i - d], -1);
    add(arr[i], 1);
    ans = min(ans, uniq);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t = 0;
  cin >> t;
  while (cin >> n >> k >> d) solve();
}

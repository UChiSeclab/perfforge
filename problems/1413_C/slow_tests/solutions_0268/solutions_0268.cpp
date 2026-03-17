#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n = 6;
  int ary[n];
  for (int i = 0; i < n; ++i) {
    cin >> ary[i];
  }
  sort(ary, ary + n);
  int m;
  cin >> m;
  vector<int> note;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    note.push_back(a);
  }
  sort(note.begin(), note.end());
  int ans = inf + 10;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int mn = note[j] - ary[i];
      int lo = 0;
      int hi = 1e9;
      while (hi > lo) {
        int mid = (hi + lo) / 2;
        int curl = 0;
        int curh = 0;
        int f = 0;
        for (int k = 0; k < n; ++k) {
          int l = ary[k] + mn;
          int h = l + mid;
          if (l > curh) {
            auto it = upper_bound(note.begin(), note.end(), curh);
            if (it != note.end() && (*it) < l) {
              f = 1;
              break;
            }
            curl = l;
            curh = h;
          } else {
            curh = h;
          }
        }
        auto it = upper_bound(note.begin(), note.end(), curh);
        if (it != note.end()) {
          f = 1;
        }
        if (f != 1) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }
      ans = min(ans, lo);
    }
  }
  cout << ans << "\n";
  return 0;
}

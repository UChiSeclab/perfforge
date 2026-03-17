#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, max = 9999999;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int r[105];
    int n, k1, d;
    cin >> n >> k1 >> d;
    vector<vector<int>> a;
    for (int j = 0; j < n; ++j) {
      int a1;
      cin >> a1;
      r[j] = 0;
      a.push_back({});
      if (j + 1 > d) {
        for (int k = j - d + 1; k <= j; k++) {
          if (!binary_search(a[k].begin(), a[k].end(), a1)) {
            r[k]++;
            a[k].push_back(a1);
            sort(a[k].begin(), a[k].end());
          }
        }
      } else {
        for (int k = 0; k <= j; k++) {
          if (!binary_search(a[k].begin(), a[k].end(), a1)) {
            r[k]++;
            a[k].push_back(a1);
            sort(a[k].begin(), a[k].end());
          }
        }
      }
    }
    sort(r, r + n - d + 1);
    cout << r[0] << endl;
  }
}

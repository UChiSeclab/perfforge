#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> used(2000005, 0);
    int res = 0;
    for (int i = 0; i < d; i++) {
      if (!used[a[i]]) {
        res++;
      }
      used[a[i]]++;
    }
    int cur = res;
    for (int i = d; i < n; i++) {
      if (!used[a[i]]) {
        cur++;
      }
      used[a[i]]++;
      if (used[a[i - d]] == 1) {
        cur--;
      }
      used[a[i - d]]--;
      if (cur < res) {
        res = cur;
      }
    }
    cout << res << endl;
  }
}

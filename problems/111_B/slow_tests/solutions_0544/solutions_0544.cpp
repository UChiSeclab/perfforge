#include <bits/stdc++.h>
using namespace std;
int n;
int x[100001], y[100001];
set<pair<int, int> > comp;
int main() {
  comp.clear();
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> x[i + 1] >> y[i + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < 318; j++) {
      if (x[i] % j == 0) {
        comp.insert(make_pair(j, i));
        int c = x[i] / j;
        comp.insert(make_pair(c, i));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j < 318; j++) {
      if (x[i] % j) continue;
      if (x[i] > 1 && j == x[i]) break;
      if ((long long)j * (long long)j > x[i]) break;
      set<pair<int, int> >::iterator it = comp.lower_bound(make_pair(j, i));
      if (it == comp.begin())
        ans++;
      else {
        it--;
        if (it->first != j || it->second < i - y[i]) {
          ans++;
        }
      }
      if ((long long)j * (long long)j >= x[i]) break;
      int c = x[i] / j;
      if (c == j) continue;
      it = comp.lower_bound(make_pair(c, i));
      if (it == comp.begin())
        ans++;
      else {
        it--;
        if (it->first != c || it->second < i - y[i]) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

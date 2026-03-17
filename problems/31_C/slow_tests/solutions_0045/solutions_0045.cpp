#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, l[N], r[N], a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    r[i]--;
    a[l[i]]++, a[r[i] + 1]--;
  }
  for (int i = 1; i < N; i++) a[i] += a[i - 1];
  int le = 2e9, rg = n;
  for (int i = 1; i < N; i++) {
    if (a[i] > 2) {
      le = -1;
      break;
    }
    if (a[i] == 2) {
      le = min(le, i);
      rg = max(rg, i);
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i++)
    if (le == 2e9 || (l[i] <= le && r[i] >= rg)) res.push_back(i);
  cout << res.size() << '\n';
  for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
  return 0;
}

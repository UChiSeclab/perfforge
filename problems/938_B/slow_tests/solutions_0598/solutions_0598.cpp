#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, i, j, n, m, l, r;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> l;
    a[l] = 1;
  }
  l = r = 0;
  if (a[1] == 1) l++;
  if (a[(int)1e6] == 1) l++;
  for (i = 2, j = 1e6 - 1; i < j && l < n; i++, j--, r++) {
    if (a[i] == 1) l++;
    if (a[j] == 1) l++;
  }
  cout << r << "\n";
  return 0;
}

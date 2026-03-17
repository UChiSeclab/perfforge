#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod = (int)1e9 + 7;
const long long INF = 1000000000000000000LL;
const int WASTE = (int)2e5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  bool z[n], z1[m];
  memset(z, 0, sizeof(z));
  memset(z1, 0, sizeof(z1));
  int k;
  cin >> k;
  int c, cc;
  bool f = 1, ff = 1;
  if (!k) f = 0;
  c = k;
  while (k--) {
    int i;
    cin >> i;
    z[i] = 1;
  }
  cin >> k;
  cc = k;
  if (!k) ff = 0;
  if (!f && !ff) {
    cout << "No";
    return 0;
  }
  while (k--) {
    int i;
    cin >> i;
    z1[i] = 1;
  }
  int ctr = 0, cap = 100 * 100 * 100;
  while (ctr < cap) {
    int i = ctr % n, ii = ctr % m;
    if (z[i] && !z1[ii]) {
      z1[ii] = 1;
      cc++;
    } else if (!z[i] && z1[ii]) {
      z[i] = 1;
      c++;
    }
    if (c == n && cc == m) break;
    ctr++;
  }
  if (c == n && cc == m)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}

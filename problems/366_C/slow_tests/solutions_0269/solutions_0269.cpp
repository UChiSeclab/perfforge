#include <bits/stdc++.h>
using namespace std;
const int base = 1000000007;
int n, k, res = 0;
pair<int, int> a[102];
map<int, int> b, c;
map<int, int>::iterator it;
int main() {
  int i, j;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i].first;
  for (i = 1; i <= n; i++) {
    cin >> a[i].second;
    a[i].second = a[i].first - k * a[i].second;
  }
  b[0] = 0;
  for (i = 1; i <= n; i++)
    for (it = (c = b).begin(); it != c.end(); it++)
      b[it->first + a[i].second] =
          max(b[it->first + a[i].second], a[i].first + it->second);
  if (b[0])
    cout << b[0];
  else
    cout << -1;
  return 0;
}

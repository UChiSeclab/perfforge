#include <bits/stdc++.h>
using namespace std;
vector<int> vt;
map<int, int> mp;
int main() {
  int test, tc = 0;
  long long m, n, ans, i, j, r, b, k, g;
  cin >> test;
  while (test--) {
    mp.clear();
    vt.clear();
    vt.push_back(0);
    ans = 0;
    cin >> n;
    for (i = sqrt(n + 1); i >= 1; i--) {
      j = n / i;
      if (mp[j] == 0) vt.push_back(j);
      mp[j] = 1;
      j = n / j;
      if (mp[j] == 0) vt.push_back(j);
      mp[j] = 1;
    }
    sort(vt.begin(), vt.end());
    n = vt.size();
    cout << n << endl << vt[0];
    for (i = 1; i < n; i++) {
      cout << " " << vt[i];
    }
    cout << endl;
  }
  return 0;
}

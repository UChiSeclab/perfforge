#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> a;
  long long temp, n, k;
  int ans = 0;
  cin >> n >> k;
  while (n--) {
    cin >> temp;
    a.push_back(temp);
  }
  int i, j;
  int ss = a.size();
  while (a[0] < k) {
    ++ans;
    for (i = 0; i < ss; ++i) {
      for (j = i; j + 1 < ss && a[j] == a[j + 1] && a[j] != k; ++j)
        ;
      ++a[j];
      i = j;
      sort(a.begin(), a.end());
    }
  }
  cout << ans << endl;
  a.clear();
  return 0;
}
